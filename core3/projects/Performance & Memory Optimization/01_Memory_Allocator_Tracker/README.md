# Memory Allocator Tracker

**A lightweight, low-level memory tracker for C++** that overrides the global `new`/`delete` operators to intercept **every** allocation.

It records size, address, and timestamp for each allocation, automatically detects leaks, and outputs a clean, human-readable log.  

This module is the **raw memory tracking foundation** for the larger [**04_Unified_Memory_Debugger**]([https://github.com/yourusername/04_Unified_Memory_Debugger](https://github.com/soleimani2020/02-Cplusplus-Projects-Portfolio/tree/main/core3/projects/Performance%20%26%20Memory%20Optimization/04_Unified_Memory_Debugger)) project.

---

## 🔗 Role in the Unified Memory Debugger

This component provides **byte-accurate allocation data**.  
When merged with **Logical_Dataset_Tracker** and **Smart_Pointer_Pool**, it enables **dual-level leak detection** (raw bytes + named objects) and RAII-aware tracking.

---

## ✨ Key Features

- Overrides `new`, `delete`, `new[]`, and `delete[]` (single-object and array versions)
- Tracks all active allocations in a high-performance `std::unordered_map`
- Automatic leak detection with full details (address, size, allocation timestamp)
- Detailed logging to `memory_log.txt`
- Prints concise memory usage statistics on program exit
- Zero runtime overhead when disabled (compile-time flag)

---

## 🛠️ Build & Usage

### Quick Start

```bash
# Clone the repository
git clone https://github.com/yourusername/memory-allocator-tracker.git
cd memory-allocator-tracker

# Build
g++ -std=c++11 -O2 -Wall main.cpp -o alloc_tracker

# Run
./alloc_tracker
