#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <mutex>
#include <cstdlib>
#include <algorithm>

using namespace std;


class MemoryManager
{
    struct Allocation
    {
        size_t id;
        size_t size;
        time_t time;
    };

    unordered_map<void*, Allocation> allocations;
    mutex mtx;

    ofstream logFile;

    size_t allocationsCount = 0;
    size_t deallocationsCount = 0;
    size_t currentBytes = 0;
    size_t peakBytes = 0;
    size_t idCounter = 0;


public:

    MemoryManager()
    {
        logFile.open("memory_log.txt", ios::app);
    }


    void* allocate(size_t size)
    {
        void* ptr = malloc(size);

        if(!ptr)
            throw bad_alloc();


        Allocation a;
        a.id = ++idCounter;
        a.size = size;
        a.time = time(nullptr);


        {
            lock_guard<mutex> lock(mtx);

            allocations[ptr] = a;

            allocationsCount++;
            currentBytes += size;

            peakBytes = max(peakBytes, currentBytes);
        }


        log("Allocated " + to_string(size) + " bytes");

        return ptr;
    }



    void deallocate(void* ptr)
    {
        if(!ptr)
            return;


        lock_guard<mutex> lock(mtx);


        auto it = allocations.find(ptr);


        if(it != allocations.end())
        {
            currentBytes -= it->second.size;

            deallocationsCount++;

            allocations.erase(it);

            free(ptr);
        }
        else
        {
            free(ptr);
        }
    }



    void report()
    {
        cout << "\nMemory report\n";

        if(allocations.empty())
        {
            cout << "No leaks detected\n";
            return;
        }


        for(auto& item : allocations)
        {
            cout << "Leak: "
                 << item.second.size
                 << " bytes at "
                 << item.first
                 << endl;
        }
    }



    void statistics()
    {
        cout << "\nStatistics\n";
        cout << "Allocations: " << allocationsCount << endl;
        cout << "Deallocations: " << deallocationsCount << endl;
        cout << "Current: " << currentBytes << " bytes\n";
        cout << "Peak: " << peakBytes << " bytes\n";
    }



    void log(const string& msg)
    {
        if(logFile)
            logFile << msg << endl;
    }



    ~MemoryManager()
    {
        report();

        for(auto& item : allocations)
            free(item.first);

        statistics();
    }
};



MemoryManager* manager = nullptr;


void* operator new(size_t size)
{
    if(manager)
        return manager->allocate(size);

    return malloc(size);
}


void operator delete(void* ptr) noexcept
{
    if(manager)
        manager->deallocate(ptr);
    else
        free(ptr);
}


void* operator new[](size_t size)
{
    if(manager)
        return manager->allocate(size);

    return malloc(size);
}


void operator delete[](void* ptr) noexcept
{
    if(manager)
        manager->deallocate(ptr);
    else
        free(ptr);
}



int main()
{
    MemoryManager memory;

    manager = &memory;


    int* a = new int;
    *a = 10;

    delete a;


    int* array = new int[5];

    for(int i=0;i<5;i++)
        array[i]=i;


    delete[] array;


    int* leak = new int[20];


    return 0;
}
