# Memory Smart Pool

**A modern C++ connection pool using smart pointers** that demonstrates RAII, `shared_ptr`, `weak_ptr`, and `unique_ptr` with custom deleters.

It implements a reusable pool of `DatabaseConnection` objects, tracks usage with an `inUse` flag, and safely manages resource lifetimes without manual `new`/`delete`.  

This module is the **RA‑II aware smart pointer pool** for the larger [**04_Unified_Memory_Debugger**](https://github.com/yourusername/04_Unified_Memory_Debugger) project.

---

## 🔗 Role in the Unified Memory Debugger

This component provides **smart pointer‑based resource management** and a **connection pool** example.  
When merged with:
- **Memory Allocator Tracker** (raw byte‑level tracking)
- **Logical Dataset Tracker** (named object + logical leak detection)

it demonstrates:
- How modern C++ (`shared_ptr`, `unique_ptr`, `weak_ptr`) eliminates manual memory errors
- How a pool can be integrated with global allocation tracking (via overridden `new`/`delete`)
- Dual‑level leak detection (raw bytes + logical objects) alongside RAII containers

Together they form a complete, production‑grade memory debugging and resource management suite.

---

## ✨ Key Features

- `DatabaseConnection` class with RAII constructor/destructor (auto‑disconnect)
- `ConnectionManager` that maintains a pool of `shared_ptr<DatabaseConnection>`
- `getConnection()` returns an available connection and marks it `inUse`
- `releaseConnection()` returns the connection to the pool
- Demonstration of `shared_ptr` reference counting and `weak_ptr` for non‑owning observation
- `unique_ptr` with custom deleter for `FILE*` (C‑style file handling)
- Console output for all operations (connect, disconnect, query, reference counts)
- No manual `new`/`delete` – fully modern C++

---

## 🛠️ Build & Usage

### Quick Start

```bash
# Clone the repository
git clone https://github.com/yourusername/smart-pointer-pool.git
cd smart-pointer-pool

# Build
g++ -std=c++11 -O2 -Wall main.cpp -o smart_pool

# Run
./smart_pool
