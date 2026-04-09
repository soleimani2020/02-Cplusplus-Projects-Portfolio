# Unified Memory Debugger

This project merges three earlier memory‑focused tools into a single, cohesive debugger:

- **01_Memory_Allocator_Tracker** – raw allocator tracker (global new/delete override + leak detection)
- **02_Memory_Dataset_Tracker** – logical dataset tracker (named datasets with age and leak report)
- **03_Memory_SmartPool** – connection pool with smart pointers

The unified debugger provides:

- Real‑time memory allocation tracking
- Leak detection and reporting
- Object lifetime monitoring
- Connection pooling with automatic cleanup

## Build & Run

```bash
make
./unified_memory_debugger
