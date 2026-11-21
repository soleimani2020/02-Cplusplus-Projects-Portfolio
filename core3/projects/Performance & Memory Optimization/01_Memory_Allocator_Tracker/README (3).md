# Memory Allocator Tracker

**A lightweight, low-level memory tracker for C++** that overrides the global `new`/`delete` operators to intercept **every** allocation.

It records size, address, and timestamp for each allocation, automatically detects leaks, and outputs a clean, human-readable log.

This module is the **raw memory tracking foundation** for the larger [**04_Unified_Memory_Debugger**](https://github.com/soleimani2020/02-Cplusplus-Projects-Portfolio/tree/main/core3/projects/Performance%20%26%20Memory%20Optimization/04_Unified_Memory_Debugger) project.

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

## 📊 Test Results

| Test | Result |
|---|---|
| Leak detection | ✅ 3 / 3 scenarios exact |
| Memory accounting (current + peak) | ✅ 6 / 6 phases exact |
| Stress test (100,000 random operations) | ✅ 0 bytes, 0 blocks left |
| Multithreaded (4, 8, 16 threads) | ✅ 18 / 18 checks, 0 failures |
| Overhead vs. default `new`/`delete` | 16× at 64 B → **1.07× at 768 MB** |
| Sharded locks (64 shards, 16 threads) | **−39 % run time** |

### 1. Leak detection

Three scenarios, each with 10,000 allocations of 100 B:

| Scenario | Expected leaked | Reported |
|---|---|---|
| No leak (all freed) | 0 blocks, 0 B | 0 blocks, 0 B ✅ |
| Partial leak (1,000 not freed) | 1,000 blocks, 100,000 B | 1,000 blocks, 100,000 B ✅ |
| Complete leak (nothing freed) | 10,000 blocks, 1,000,000 B | 10,000 blocks, 1,000,000 B ✅ |

The tracker reports the exact number of leaked blocks and bytes in every scenario.

### 2. Memory accounting

Memory rises and falls over six phases. Current and peak memory matched the expected value after every phase:

| Phase | Current memory | Peak memory |
|---|---|---|
| 1,000 × 100 B allocated | 100,000 B | 100,000 B |
| + 1,000 × 200 B | 300,000 B | 300,000 B |
| + 1,000 × 500 B | 800,000 B | 800,000 B |
| 200 B blocks freed | 600,000 B | 800,000 B |
| + 1,000 × 400 B | 1,000,000 B | 1,000,000 B |
| Everything freed | 0 B | 1,000,000 B |

Current memory returns to 0, and peak memory keeps the highest value reached.

### 3. Stress test

100,000 random allocate/free operations, block sizes 8 B – 64 KB, at most 5,000 blocks active at once, checked every 10,000 operations:

- 52,499 allocations and exactly 52,499 deallocations
- 0 bytes and 0 blocks left at the end
- Peak memory ≈ 64 MB
- All checkpoints matched; 5 / 5 final checks passed

### 4. Multithreaded correctness

Several threads allocate and free at the same time, 25,000 operations per thread:

| Threads | Operations | Allocations = deallocations | Peak | Left | Failures |
|---|---|---|---|---|---|
| 4 | 100,000 | 60,005 | ~249 MB | 0 | 0 |
| 8 | 200,000 | 120,159 | ~453 MB | 0 | 0 |
| 16 | 400,000 | 240,247 | ~907 MB | 0 | 0 |

Each run has 6 correctness checks, so 18 / 18 checks passed. A mutex protects the shared allocation table, so no allocation was lost or counted twice.

### 5. Performance overhead

Time for one allocation + one deallocation, tracker vs. default `malloc`/`free` (median of 10 runs, all runs passed the correctness checks):

| Block size | Default | Tracker | Ratio | Extra time per pair |
|---|---|---|---|---|
| 64 B | 36 ns | 573 ns | 16× | ~0.54 µs |
| 256 B | 162 ns | 748 ns | 4.6× | ~0.59 µs |
| 1 KB | 603 ns | 1,228 ns | 2.0× | ~0.63 µs |
| 4 KB | 2,237 ns | 2,923 ns | 1.3× | ~0.69 µs |
| 64 KB | 2,879 ns | 3,523 ns | 1.2× | ~0.64 µs |
| 1 MB | 6,160 ns | 6,949 ns | 1.13× | ~0.79 µs |
| 100 MB | 22,285 ns | 25,260 ns | 1.13× | ~3.0 µs |
| 768 MB | 35,205 ns | 37,500 ns | 1.07× | ~2.3 µs |

The tracker adds a roughly constant bookkeeping cost of **~0.5–0.8 µs per pair** (lock, hash the address, insert/remove the record, update the counters). For tiny blocks this dominates (16×); from 4 KB upwards the overhead is only 1.1–1.3×.

### 6. Optimisation: sharded locks

With one lock for the whole table, 16 threads queue for that lock. Splitting the table into **64 shards, each with its own lock**, lets threads work in parallel unless they need the same shard.

16 threads, 5,000 allocations each, block sizes 8 B – 4 KB, median of 5 runs:

| Locks | Run time | Throughput |
|---|---|---|
| 1 | 966 ms | ~166,000 ops/s |
| 64 | 592 ms | ~270,000 ops/s |

**−39 % run time (~1.6× throughput).** Of the shard counts tested (1 – 64), 2 – 16 gave mixed results; a clear gain appeared only at 32 and 64. With a single thread, sharding gives no benefit.

### Notes and limitations

- The 100 MB and 768 MB timings use one pair per repetition, so they are less precise. The memory is allocated but not touched, so they measure allocation cost, not memory access.
- The multithreaded tests show correctness for the tested runs, not a formal proof. Running under ThreadSanitizer is a planned next check.
- The tracker is a **diagnostic tool for development**, not a faster allocator.

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
```
