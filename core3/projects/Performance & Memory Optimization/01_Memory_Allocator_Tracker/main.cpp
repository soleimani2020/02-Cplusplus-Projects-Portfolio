#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <mutex>
#include <cstdlib>
#include <algorithm>
#include <new>

using namespace std;


// Allocator that takes memory directly from malloc/free.
// The allocation table uses it, so adding or removing a record
// never calls the global operator new/delete again.
template <typename T>
struct MallocAllocator
{
    using value_type = T;

    MallocAllocator() = default;

    template <typename U>
    MallocAllocator(const MallocAllocator<U>&) {}

    T* allocate(size_t n)
    {
        void* p = malloc(n * sizeof(T));
        if(p == nullptr)
            throw bad_alloc();
        return static_cast<T*>(p);
    }

    void deallocate(T* p, size_t)
    {
        free(p);
    }

    template <typename U>
    bool operator==(const MallocAllocator<U>&) const { return true; }

    template <typename U>
    bool operator!=(const MallocAllocator<U>&) const { return false; }
};


// Re-entrancy guard.
// While the tracker is working, any memory it needs for itself
// (strings, stringstream, log file, cout) is taken directly from
// malloc and is not tracked. This prevents recursive tracking
// and the deadlock on the mutex.
thread_local bool insideTracker = false;

struct TrackerGuard
{
    TrackerGuard()  { insideTracker = true; }
    ~TrackerGuard() { insideTracker = false; }
};


class MemoryManager
{
    struct Allocation
    {
        size_t id;
        size_t size;
        double time;        // seconds since the tracker started
    };

    using Table = unordered_map<
        void*, Allocation,
        hash<void*>, equal_to<void*>,
        MallocAllocator<pair<void* const, Allocation>>>;

    Table allocations;

    mutex mtx;

    ofstream logFile;

    chrono::steady_clock::time_point start;

    size_t allocationsCount = 0;
    size_t deallocationsCount = 0;

    size_t currentBytes = 0;
    size_t peakBytes = 0;

    size_t idCounter = 0;


    double secondsSinceStart() const
    {
        return chrono::duration<double>(chrono::steady_clock::now() - start).count();
    }


public:

    MemoryManager()
        : start(chrono::steady_clock::now())
    {
        logFile.open("memory_log.txt", ios::app);
    }


    void* allocate(size_t size)
    {
        // new must succeed for size 0 and return a unique pointer
        if(size == 0)
            size = 1;

        // 1. Allocate memory using malloc()
        void* ptr = malloc(size);

        if(ptr == nullptr)
            throw bad_alloc();

        // Memory requested by the tracker itself is not tracked
        if(insideTracker)
            return ptr;

        TrackerGuard guard;
        lock_guard<mutex> lock(mtx);

        // 2. Store allocation information
        Allocation a;
        a.id = ++idCounter;
        a.size = size;
        a.time = secondsSinceStart();

        allocations[ptr] = a;

        // 3. Update statistics
        allocationsCount++;
        currentBytes += size;
        peakBytes = max(peakBytes, currentBytes);

        stringstream msg;
        msg << "Allocated " << size << " bytes at " << ptr << " (ID " << a.id << ")";
        log(msg.str());

        // Return memory address
        return ptr;
    }


    void deallocate(void* ptr)
    {
        if(ptr == nullptr)
            return;

        if(!insideTracker)
        {
            TrackerGuard guard;
            lock_guard<mutex> lock(mtx);

            auto it = allocations.find(ptr);

            if(it != allocations.end())
            {
                // Remove record and update statistics
                currentBytes -= it->second.size;
                deallocationsCount++;

                stringstream msg;
                msg << "Released " << it->second.size << " bytes at " << ptr
                    << " (ID " << it->second.id << ")";
                log(msg.str());

                allocations.erase(it);
            }
        }

        // Release memory
        free(ptr);
    }


    void report()
    {
        TrackerGuard guard;
        lock_guard<mutex> lock(mtx);

        cout << "\nMemory report\n";

        // Check allocation table
        if(allocations.empty())
        {
            cout << "No leaks detected\n";
            return;
        }

        size_t total = 0;

        for(auto& item : allocations)
        {
            cout << "Leak: " << item.second.size << " bytes at " << item.first
                 << " (ID " << item.second.id
                 << ", allocated at " << item.second.time << " s)\n";

            total += item.second.size;
        }

        cout << "Total leaked memory: " << total << " bytes in "
             << allocations.size() << " block(s)\n";
    }


    void statistics()
    {
        TrackerGuard guard;
        lock_guard<mutex> lock(mtx);

        cout << "\nStatistics\n";
        cout << "Allocations:        " << allocationsCount << "\n";
        cout << "Deallocations:      " << deallocationsCount << "\n";
        cout << "Current memory:     " << currentBytes << " bytes\n";
        cout << "Peak memory:        " << peakBytes << " bytes\n";
        cout << "Active allocations: " << allocations.size() << "\n";
    }


    // Called with the guard set, so its own allocations are not tracked
    void log(const string& msg)
    {
        if(!logFile)
            return;

        time_t now = time(nullptr);
        char stamp[32];
        strftime(stamp, sizeof(stamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

        logFile << "[" << stamp << "] " << msg << "\n";
    }


    ~MemoryManager();
};


MemoryManager* manager = nullptr;


MemoryManager::~MemoryManager()
{
    statistics();
    report();

    // From now on new/delete go directly to malloc/free,
    // so nothing uses this object after it is destroyed
    manager = nullptr;

    TrackerGuard guard;

    // Leaked blocks are reported above; free them before exit
    for(auto& item : allocations)
        free(item.first);

    if(logFile)
        logFile.close();
}


void* operator new(size_t size)
{
    if(manager)
        return manager->allocate(size);

    void* ptr = malloc(size == 0 ? 1 : size);

    if(ptr == nullptr)
        throw bad_alloc();

    return ptr;
}


void operator delete(void* ptr) noexcept
{
    if(ptr == nullptr)
        return;

    if(manager)
        manager->deallocate(ptr);
    else
        free(ptr);
}


void* operator new[](size_t size)
{
    return operator new(size);
}


void operator delete[](void* ptr) noexcept
{
    operator delete(ptr);
}


// Sized versions (C++14) forward to the ones above
void operator delete(void* ptr, size_t) noexcept   { operator delete(ptr); }
void operator delete[](void* ptr, size_t) noexcept { operator delete[](ptr); }


int main()
{
    MemoryManager memory;

    manager = &memory;

    cout << "Memory Tracking Test\n";

    // Single object
    int* a = new int;
    *a = 10;
    cout << "new int at " << a << ", value " << *a << "\n";
    delete a;

    // Array
    int* array = new int[5];
    for(int i = 0; i < 5; i++)
        array[i] = i;
    cout << "new int[5] at " << array << "\n";
    delete[] array;

    // Deliberate leak: never deleted
    int* leak = new int[20];
    cout << "new int[20] at " << leak << " (not deleted)\n";

    return 0;
}
