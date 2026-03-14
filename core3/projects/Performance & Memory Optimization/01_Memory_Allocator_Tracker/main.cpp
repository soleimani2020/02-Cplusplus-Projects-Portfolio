#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <sstream>


using namespace std;



class MemoryManager{
private:

    struct AllocationInfo{
        size_t size;
        time_t timestamp;
    };
    
    unordered_map <void* , AllocationInfo> allocations; // memory address(pointer) -> allocation_info
    
    
public:

    int totalAllocations;
    int totalDeallocations;
    size_t currentAllocatedBytes;  // memory size 
    size_t peakAllocatedBytes;     // memory size 
    
    MemoryManager():totalAllocations(0),totalDeallocations(0),currentAllocatedBytes(0),peakAllocatedBytes(0){}
    
    
    void* allocateMemory(size_t size){
        if(size<=0){
            cout << "Memory allocation request is invalid !" << endl;
            return nullptr;
        }
        
        void* Memory = new char[size];      // Create the memory block
        AllocationInfo  object(size,time(nullptr));
        allocations[Memory] = object; 
        totalAllocations++;
        currentAllocatedBytes+=size;
        peakAllocatedBytes = max(currentAllocatedBytes,peakAllocatedBytes);
        
        
        // Log the deallocation
        ostringstream msg;
        msg << "allocation " << size << " bytes at address " << Memory;
        logToFile(msg.str());
        
        
        return Memory;
    }
    
    
    void deallocateMemory(void* Memory){
        if(Memory ==nullptr){
            cout << "There’s nothing to deallocate !" << endl;
            return;
        }
        
        if(allocations.count(Memory)){
            size_t size = allocations[Memory].size;  // get size
            delete[] static_cast<char*>(Memory); 
            totalDeallocations++;
            currentAllocatedBytes -= size;
            allocations.erase(Memory);
            Memory = nullptr;
        }else{
            cout << "Someone is trying to delete untracked memory !";
        }
    }
    
    
    void* allocateArray(size_t size){
        if(size<=0){
            cout << "Memory allocation request is invalid !" << endl;
            return nullptr;
        }
        void* array = new char[size];
        AllocationInfo object(size,time());
        allocations[array] = object; 
        totalAllocations++;
        currentAllocatedBytes+=size;
        peakAllocatedBytes = max(currentAllocatedBytes,peakAllocatedBytes);
        
        // Log the deallocation
        ostringstream msg;
        msg << "allocation " << size << " bytes at address " << array;
        logToFile(msg.str());
        return array;
    }
    
    
    
    void deallocateArray(void* array){
        if(array==nullptr){
            cout << "There’s nothing to deallocate !" << endl;
            return ;
        }
        
        if(allocations.count(array)){
            size_t size = allocations[array].size;
            delete[] array;
            totalDeallocations++;
            currentAllocatedBytes -= size;
            allocations.erase(array);
            array= nullptr;
        } else {
            cout << "Someone is trying to delete untracked memory !"<< endl;
        }
    }
    


    void reportLeaks(){
        cout << "=== Memory Leak Report ===" << endl;
        if(allocations.empty()){
            cout << "No memory leaks detected!" << endl;
            return;
        }
        
        size_t totalLeakedBytes = 0;
        int leakCount = 0;
        for(const auto& entry: allocations){
            void* ptr= entry.first;
            const AllocationInfo& info = entry.second;
            
            cout << "Leaked memory at address: " << ptr
                 << " | Size: " << info.size
                 << " bytes | Allocated at: " << ctime(&info.timestamp); 
                 
            
            totalLeakedBytes+=info.size;
            leakCount++;
        }
        
        cout << "Total leaked blocks: " << leakCount
         << " | Total leaked bytes: " << totalLeakedBytes << endl;
    }
    
    
    
    void printStatistics(){
        cout << "=== Memory Manager Statistics ===" << endl;
        cout << "Total allocations: " << totalAllocations << endl;
        cout << "Total deallocations: " << totalDeallocations << endl;
        cout << "Current allocated bytes: " << currentAllocatedBytes << endl;
        cout << "Peak allocated bytes: " << peakAllocatedBytes << endl;
    }
    
    
    
    void logToFile(const string& message) {
        ofstream logFile("memory_log.txt", ios::app);
        if (!logFile) {
            cerr << "Error opening log file!" << endl;
            return;
        }
        
        // Get current time
        time_t now = time(nullptr);
        logFile << "[" << ctime(&now) << "] " << message << endl;
    }
    
    
    ~MemoryManager(){
        
        reportLeaks();
        
        for(const auto& entry : allocations){
            void* Memory = entry.first;
            size_t size= entry.second.size;
            time_t timestamp= entry.second.timestamp;
            
            delete[] static_cast<char*>(Memory);
            Memory=nullptr;
            totalDeallocations++;
            currentAllocatedBytes -= size;
        }
        
        printStatistics();
        
    }
        
    
};




