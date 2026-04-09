# Memory Dataset Tracker

**A high-level logical memory tracker for C++** that manages named `DataSet` objects with automatic allocation, deallocation, timestamping, and leak detection.

It tracks datasets by name, handles dynamic integer arrays, provides detailed status reports, and ensures clean RAII-style cleanup.  

This module is the **Logical Dataset Tracker** for the larger [**04_Unified_Memory_Debugger**](https://github.com/yourusername/04_Unified_Memory_Debugger) project.

---

## 🔗 Role in the Unified Memory Debugger

This component provides **named object + logical dataset tracking**.  
When merged with:
- **Memory Allocator Tracker** (raw byte-level tracking)
- **Smart_Pointer_Pool** (RAII-aware lifetime management)

it enables **dual-level leak detection**:
- Raw byte-level tracking
- High-level named dataset + object tracking

Together they form a complete, production-grade memory debugging solution.

---

## ✨ Key Features

- `DataSet` struct with name, dynamic `int` array, size, and creation timestamp
- `MemoryTracker` class using `std::vector` for active dataset management
- Safe `allocateDataSet()` with duplicate name and invalid size checks
- Safe `deallocateDataSet()` with proper `delete[]` + `delete`
- Real-time display of active datasets (name, size, age, memory address)
- Built-in memory leak detection with allocation/deallocation counters
- Automatic cleanup in destructor (RAII-compliant)
- Comprehensive error handling and console feedback

---

## 🛠️ Build & Usage

### Quick Start

```bash
# Clone the repository
git clone https://github.com/yourusername/memory-dataset-tracker.git
cd memory-dataset-tracker

# Build
g++ -std=c++11 -O2 -Wall main.cpp -o dataset_tracker

# Run
./dataset_tracker
