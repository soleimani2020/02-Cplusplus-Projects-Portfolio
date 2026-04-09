/*
#include "../01_Raw_Memory_Tracker/memory_manager.h"
#include "../02_Logical_Dataset_Tracker/memory_tracker.h"
#include "../03_Smart_Pointer_Pool/connection_pool.h"
#include <iostream>
int main() {
    std::cout << "Unified Memory Debugger\n";
    return 0;
}
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <chrono>
#include <memory>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

// (i): Memory Allocator Tracker 

class MemoryManager {
private:
    struct AllocationInfo {
        size_t size;
        time_t timestamp;
    };
    unordered_map<void*, AllocationInfo> allocations;

public:
    int totalAllocations = 0;
    int totalDeallocations = 0;
    size_t currentAllocatedBytes = 0;
    size_t peakAllocatedBytes = 0;

    void* allocateMemory(size_t size) {
        if (size <= 0) {
            cerr << "Memory allocation request is invalid!" << endl;
            return nullptr;
        }
        void* memory = new char[size];
        allocations[memory] = {size, time(nullptr)};
        totalAllocations++;
        currentAllocatedBytes += size;
        peakAllocatedBytes = max(currentAllocatedBytes, peakAllocatedBytes);

        ostringstream msg;
        msg << "allocation " << size << " bytes at address " << memory;
        logToFile(msg.str());
        return memory;
    }

    void deallocateMemory(void* memory) {
        if (!memory) {
            cerr << "There's nothing to deallocate!" << endl;
            return;
        }
        auto it = allocations.find(memory);
        if (it != allocations.end()) {
            size_t size = it->second.size;
            delete[] static_cast<char*>(memory);
            totalDeallocations++;
            currentAllocatedBytes -= size;
            allocations.erase(it);
        } else {
            cerr << "Someone is trying to delete untracked memory!" << endl;
        }
    }

    void* allocateArray(size_t size) {
        if (size <= 0) {
            cerr << "Memory allocation request is invalid!" << endl;
            return nullptr;
        }
        void* array = new char[size];
        allocations[array] = {size, time(nullptr)};
        totalAllocations++;
        currentAllocatedBytes += size;
        peakAllocatedBytes = max(currentAllocatedBytes, peakAllocatedBytes);

        ostringstream msg;
        msg << "allocation " << size << " bytes at address " << array;
        logToFile(msg.str());
        return array;
    }

    void deallocateArray(void* array) {
        if (!array) {
            cerr << "There's nothing to deallocate!" << endl;
            return;
        }
        auto it = allocations.find(array);
        if (it != allocations.end()) {
            size_t size = it->second.size;
            delete[] static_cast<char*>(array);
            totalDeallocations++;
            currentAllocatedBytes -= size;
            allocations.erase(it);
        } else {
            cerr << "Someone is trying to delete untracked memory!" << endl;
        }
    }

    void reportLeaks() {
        cout << "\n=== [Raw Memory] Leak Report ===" << endl;
        if (allocations.empty()) {
            cout << "No raw memory leaks detected." << endl;
            return;
        }
        size_t totalLeaked = 0;
        for (const auto& entry : allocations) {
            cout << "Leaked address: " << entry.first
                 << " | Size: " << entry.second.size
                 << " bytes | Allocated at: " << ctime(&entry.second.timestamp);
            totalLeaked += entry.second.size;
        }
        cout << "Total leaked blocks: " << allocations.size()
             << " | Total leaked bytes: " << totalLeaked << endl;
    }

    void printStatistics() {
        cout << "\n=== [Raw Memory] Statistics ===" << endl;
        cout << "Total allocations: " << totalAllocations << endl;
        cout << "Total deallocations: " << totalDeallocations << endl;
        cout << "Current allocated bytes: " << currentAllocatedBytes << endl;
        cout << "Peak allocated bytes: " << peakAllocatedBytes << endl;
    }

    void logToFile(const string& message) {
        ofstream logFile("memory_log.txt", ios::app);
        if (!logFile) return;
        time_t now = time(nullptr);
        logFile << "[" << ctime(&now) << "] " << message << endl;
    }

    ~MemoryManager() {
        reportLeaks();
        for (const auto& entry : allocations) {
            delete[] static_cast<char*>(entry.first);
            totalDeallocations++;
            currentAllocatedBytes -= entry.second.size;
        }
        printStatistics();
    }
};

// Global instance (must be initialized before any other allocations)
MemoryManager* globalMemoryManager = nullptr;

void* operator new(size_t size) {
    if (!globalMemoryManager) throw bad_alloc();
    return globalMemoryManager->allocateMemory(size);
}

void operator delete(void* ptr) noexcept {
    if (ptr && globalMemoryManager)
        globalMemoryManager->deallocateMemory(ptr);
}

void* operator new[](size_t size) {
    if (!globalMemoryManager) throw bad_alloc();
    return globalMemoryManager->allocateArray(size);
}

void operator delete[](void* ptr) noexcept {
    if (ptr && globalMemoryManager)
        globalMemoryManager->deallocateArray(ptr);
}

// (ii):: Logical Dataset Tracker

struct DataSet {
    string name;
    int* data;
    int size;
    chrono::steady_clock::time_point creationTime;

    DataSet(const string& n, int s) : name(n), size(s), data(nullptr) {
        creationTime = chrono::steady_clock::now();
    }
};

class MemoryTracker {
private:
    vector<DataSet*> activeSets;
    int totalAllocations = 0;
    int totalDeallocations = 0;

public:
    bool allocateDataSet(const string& name, int size) {
        if (size <= 0) {
            cout << "Error: Cannot allocate dataset '" << name << "' with size " << size << endl;
            return false;
        }
        for (DataSet* ds : activeSets) {
            if (ds->name == name) {
                cout << "Error: Dataset '" << name << "' already exists!" << endl;
                return false;
            }
        }
        try {
            DataSet* ds = new DataSet(name, size);      // tracked by MemoryManager
            ds->data = new int[size];                   // also tracked
            for (int i = 0; i < size; i++) ds->data[i] = i * 5;
            activeSets.push_back(ds);
            totalAllocations++;
            cout << "✓ Allocated dataset '" << name << "' with " << size << " elements" << endl;
            return true;
        } catch (const bad_alloc&) {
            cout << "✗ Allocation failed for dataset '" << name << "'" << endl;
            return false;
        }
    }

    bool deallocateDataSet(const string& name) {
        for (auto it = activeSets.begin(); it != activeSets.end(); ++it) {
            if ((*it)->name == name) {
                DataSet* ds = *it;
                delete[] ds->data;
                delete ds;
                activeSets.erase(it);
                totalDeallocations++;
                cout << "✓ Deallocated dataset '" << name << "'" << endl;
                return true;
            }
        }
        cout << "✗ Dataset '" << name << "' not found for deallocation" << endl;
        return false;
    }

    void displayActiveDataSets() {
        cout << "\n=== [Logical] Active Datasets ===" << endl;
        if (activeSets.empty()) {
            cout << "No active datasets." << endl;
            return;
        }
        auto now = chrono::steady_clock::now();
        for (DataSet* ds : activeSets) {
            auto age = chrono::duration_cast<chrono::seconds>(now - ds->creationTime).count();
            cout << "Dataset: " << ds->name << " | Size: " << ds->size
                 << " | Age: " << age << "s | Data address: " << ds->data << endl;
        }
    }

    void detectLogicalLeaks() {
        cout << "\n=== [Logical] Leak Detection ===" << endl;
        cout << "Total dataset allocations: " << totalAllocations << endl;
        cout << "Total dataset deallocations: " << totalDeallocations << endl;
        if (!activeSets.empty()) {
            cout << "⚠ WARNING: Logical memory leaks detected!" << endl;
            cout << "Datasets not deallocated:" << endl;
            for (DataSet* ds : activeSets) {
                cout << "  - " << ds->name << " (" << ds->size << " elements)" << endl;
            }
        } else {
            cout << "✓ No logical dataset leaks." << endl;
        }
    }

    ~MemoryTracker() {
        for (DataSet* ds : activeSets) {
            delete[] ds->data;
            delete ds;
        }
        activeSets.clear();
    }
};

// (iii):: Smart Pointer Pool (RAII connection manager)

class DatabaseConnection {
private:
    int connectionId;
    bool connected;
    bool inUse = false;

public:
    DatabaseConnection(int ID) : connectionId(ID), connected(true) {
        cout << "Connection with ID " << connectionId << " opened." << endl;
    }

    void connect() {
        if (connected) return;
        connected = true;
        cout << "DatabaseConnection " << connectionId << " connected." << endl;
    }

    void disconnect() {
        if (!connected) return;
        connected = false;
        cout << "DatabaseConnection " << connectionId << " disconnected." << endl;
    }

    void query(const string& sql) {
        if (connected) {
            cout << "Executing query on DatabaseConnection " << connectionId
                 << ": " << sql << endl;
        } else {
            cout << "Cannot execute query: DatabaseConnection " << connectionId
                 << " is disconnected." << endl;
        }
    }

    bool isInUse() const { return inUse; }
    void setInUse(bool use) { inUse = use; }

    ~DatabaseConnection() {
        disconnect();
        cout << "Connection with ID " << connectionId << " closed." << endl;
    }
};

class ConnectionManager {
private:
    vector<shared_ptr<DatabaseConnection>> connectionPool;

public:
    ConnectionManager(int poolSize = 3) {
        for (int i = 0; i < poolSize; i++) {
            connectionPool.push_back(make_shared<DatabaseConnection>(i + 1));
        }
        cout << "ConnectionManager created with " << poolSize << " connections." << endl;
    }

    shared_ptr<DatabaseConnection> getConnection() {
        for (auto& conn : connectionPool) {
            if (!conn->isInUse()) {
                conn->setInUse(true);
                cout << "Connection " << conn->isInUse() << " (ID?) given out." << endl;
                return conn;
            }
        }
        cout << "No available connections in the pool." << endl;
        return nullptr;
    }

    void releaseConnection(shared_ptr<DatabaseConnection> conn) {
        if (conn) {
            conn->setInUse(false);
            cout << "Connection released back to pool." << endl;
        }
    }
};

// MAIN 

int main() {
    // Initialize the global memory manager FIRST – all subsequent allocations are tracked.
    globalMemoryManager = new MemoryManager();

    cout << "========================================" << endl;
    cout << "   UNIFIED MEMORY DEBUGGER" << endl;
    cout << "========================================" << endl;

    // ----- 1. Raw Allocator Tracker demonstration -----
    cout << "\n--- 1. Raw Allocator Tracker ---" << endl;
    int* a = new int(42);
    cout << "Allocated int with value " << *a << endl;
    delete a;

    int* arr = new int[5];
    for (int i = 0; i < 5; i++) arr[i] = i * 10;
    cout << "Allocated int[5] and initialized" << endl;
    delete[] arr;

    // Intentional leak to test detection
    cout << "\n--- Creating intentional leak (int[3]) ---" << endl;
    int* leak = new int[3];   // never deleted

    // ----- 2. Logical Dataset Tracker demonstration -----
    cout << "\n--- 2. Logical Dataset Tracker ---" << endl;
    MemoryTracker tracker;
    tracker.allocateDataSet("Temperature", 100);
    tracker.allocateDataSet("Humidity", 50);
    tracker.allocateDataSet("Pressure", 75);
    tracker.displayActiveDataSets();

    // Test error handling
    tracker.allocateDataSet("Temperature", 200);  // duplicate
    tracker.allocateDataSet("Invalid", -10);      // invalid size

    // Proper cleanup of two datasets
    tracker.deallocateDataSet("Humidity");
    tracker.deallocateDataSet("Pressure");

    tracker.displayActiveDataSets();
    tracker.detectLogicalLeaks();   // "Temperature" remains – intentional logical leak

    // ----- 3. Smart Pointer Pool demonstration -----
    cout << "\n--- 3. Smart Pointer Pool ---" << endl;
    ConnectionManager connMgr(2);

    auto conn1 = connMgr.getConnection();
    if (conn1) conn1->query("SELECT * FROM users");
    connMgr.releaseConnection(conn1);

    auto conn2 = connMgr.getConnection();
    if (conn2) conn2->query("UPDATE readings SET value=42");
    // conn2 not released – will be destroyed when going out of scope (RAII)
    // but still tracked by MemoryManager.

    // Also demonstrate shared_ptr and weak_ptr from original code
    cout << "\n--- Additional smart pointer demo ---" << endl;
    shared_ptr<DatabaseConnection> ptr1 = make_shared<DatabaseConnection>(99);
    cout << "Reference count: " << ptr1.use_count() << endl;
    weak_ptr<DatabaseConnection> wptr = ptr1;
    if (auto locked = wptr.lock()) {
        cout << "Resource alive, ref count: " << locked.use_count() << endl;
    }

    // ----- Final cleanup and leak reports -----
    cout << "\n--- Cleaning up global memory manager ---" << endl;
    delete globalMemoryManager;
    globalMemoryManager = nullptr;

    cout << "\n=== Unified Memory Debugger finished ===" << endl;
    return 0;
}
