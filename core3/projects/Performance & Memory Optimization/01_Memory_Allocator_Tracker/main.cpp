#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <mutex>
#include <cstdlib>
#include <algorithm>
#include <new>

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

        if(size == 0)
            throw bad_alloc();


        void* ptr = malloc(size);


        if(ptr == nullptr)
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


            peakBytes = max(
                peakBytes,
                currentBytes
            );

        }



        stringstream msg;

        msg << "Allocated "
            << size
            << " bytes at "
            << ptr;


        log(msg.str());



        return ptr;

    }





    void deallocate(void* ptr)
    {

        if(ptr == nullptr)
            return;



        lock_guard<mutex> lock(mtx);



        auto it = allocations.find(ptr);



        if(it != allocations.end())
        {

            currentBytes -= it->second.size;


            deallocationsCount++;


            stringstream msg;

            msg << "Released "
                << it->second.size
                << " bytes at "
                << ptr;


            log(msg.str());



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



        size_t total = 0;



        for(auto& item : allocations)
        {

            cout
            << "Leak: "
            << item.second.size
            << " bytes at "
            << item.first
            << endl;


            total += item.second.size;

        }



        cout
        << "Total leaked memory: "
        << total
        << " bytes\n";


    }






    void statistics()
    {

        cout << "\nStatistics\n";


        cout
        << "Allocations: "
        << allocationsCount
        << endl;


        cout
        << "Deallocations: "
        << deallocationsCount
        << endl;


        cout
        << "Current memory: "
        << currentBytes
        << " bytes\n";


        cout
        << "Peak memory: "
        << peakBytes
        << " bytes\n";


    }






    void log(const string& msg)
    {

        if(!logFile)
            return;



        time_t now = time(nullptr);



        logFile
        << "["
        << ctime(&now)
        << "] "
        << msg
        << endl;

    }






    ~MemoryManager()
    {

        report();



        for(auto& item : allocations)
        {

            free(item.first);

        }



        statistics();



        if(logFile)
            logFile.close();

    }


};





MemoryManager* manager = nullptr;





void* operator new(size_t size)
{

    if(manager)
        return manager->allocate(size);



    void* ptr = malloc(size);



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

    if(manager)
        return manager->allocate(size);



    void* ptr = malloc(size);



    if(ptr == nullptr)
        throw bad_alloc();



    return ptr;

}






void operator delete[](void* ptr) noexcept
{

    if(ptr == nullptr)
        return;



    if(manager)
        manager->deallocate(ptr);

    else
        free(ptr);

}







int main()
{

    MemoryManager memory;


    manager = &memory;



    cout
    << "Memory Tracking Test\n";



    int* a = new int;


    *a = 10;



    delete a;





    int* array = new int[5];


    for(int i = 0; i < 5; i++)
    {
        array[i] = i;
    }



    delete[] array;





    int* leak = new int[20];



    return 0;

}
