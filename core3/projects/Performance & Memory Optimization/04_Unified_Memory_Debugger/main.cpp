#include "../01_Memory_Management_System/memory_manager.h"
#include "../02_Memory_Track_System/memory_tracker.h"
#include "../03_SmartMemoryPool/connection_pool.h"
#include <iostream>

int main() {
    std::cout << "=== Unified Memory Debugger Demo ===\n";

    // 1. Raw allocator tracker
    auto& mm = MemoryManager::instance();
    void* p1 = mm.allocate(100);
    void* p2 = mm.allocate(200);
    mm.deallocate(p1);
    mm.reportLeaks();

    // 2. Logical dataset tracker
    auto& mt = MemoryTracker::instance();
    mt.track("user_session");
    mt.track("user_session");
    mt.untrack("user_session");
    mt.reportActive();

    // 3. Connection pool
    auto& pool = ConnectionPool::instance();
    auto conn1 = pool.acquire();
    auto conn2 = pool.acquire();
    conn1.reset();
    conn2.reset();
    pool.reportStatus();

    std::cout << "Demo completed.\n";
    return 0;
}
