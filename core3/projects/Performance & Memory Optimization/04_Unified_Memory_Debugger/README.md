# Unified Memory Debugger

**A production‑inspired C++ memory debugging suite** that combines raw allocation tracking, logical dataset monitoring, and RAII‑based resource management into a single, coherent tool.

This project merges three earlier components:

- **01_Memory_Allocator_Tracker** – global `new`/`delete` override with byte‑accurate leak detection
- **02_Memory_Dataset_Tracker** – named dataset management with age tracking and logical leak reports
- **03_Memory_SmartPool** – smart pointer connection pool demonstrating modern RAII

---

## ✨ Features

- **Global allocation interception** – overrides `new`, `delete`, `new[]`, `delete[]` to track every dynamic allocation.
- **Dual‑level leak detection** – raw memory (address, size, timestamp) + logical datasets (name, age, size).
- **Real‑time logging** – all allocations written to `memory_log.txt` with timestamps.
- **Usage statistics** – total allocations/deallocations, currently allocated bytes, peak memory usage.
- **Named dataset tracking** – prevents duplicates, validates sizes, computes object age.
- **Smart pointer pool** – `shared_ptr`‑based connection pool with automatic cleanup.
- **RAII everywhere** – destructors clean up resources; no manual `delete` in user code.

---

## 🔧 Future Improvements

- Thread‑safe allocation tracking
- Custom memory allocator
- Over‑aligned type support
- Memory poisoning
- OS‑level memory mapping
- Backtrace capture

Contributions and suggestions are welcome – see below.

---

## 🤝 Contributing

This project is part of a C++ portfolio demonstrating memory management expertise. If you have ideas, find a bug, or want to discuss advanced debugging techniques:

- Open an issue on GitHub
- Submit a pull request
- Contact the author directly

---

## 👤 Author

**Dr. Alireza Soleimani**  
PhD in Biophysics | Computational Scientist | C++ & Algorithm Development
