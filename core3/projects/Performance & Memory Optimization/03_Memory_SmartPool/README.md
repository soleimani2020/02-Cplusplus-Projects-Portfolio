# 🧠 SmartMemoryPool

> A high-performance, zero-fragmentation memory pool allocator for C++ that eliminates dynamic allocation overhead

[![C++](https://img.shields.io/badge/C%2B%2B-11%2B-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey)]()
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()
[![Code Size](https://img.shields.io/badge/size-~200%20lines-blue.svg)]()

---

## 📖 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [Installation](#-installation)
- [License](#-license)
- [Contact](#-contact)

---

## 📖 Overview

**SmartMemoryPool** is a production-ready memory management solution that pre-allocates a contiguous memory block and handles fixed-size object allocations internally. By bypassing the system heap, it achieves **O(1) allocation times**, **zero fragmentation**, and **predictable performance** — making it ideal for real-time systems, game engines, and embedded applications where every microsecond counts.

---

## ✨ Features

| Feature | Benefit |
|---------|---------|
| ⚡ **O(1) Allocation** | Constant-time operations regardless of pool size |
| 🧩 **Zero Fragmentation** | Contiguous memory layout prevents heap fragmentation |
| 🎯 **Fixed-Size Optimization** | Perfect for homogeneous object types |
| 🔒 **Thread-Safe Option** | Optional mutex protection for multi-threaded environments |
| 📦 **RAII Compatible** | Works seamlessly with modern C++ idioms |
| 🪶 **Minimal Overhead** | Only 8-16 bytes overhead per pool, zero per allocation |
| 🚀 **Cache Friendly** | Excellent memory locality improves performance |
| 🔧 **Simple API** | Just allocate() and free() - no learning curve |

---

## 📦 Installation

### Header-Only Usage
Simply copy `MemoryPool.h` into your project:

```bash
git clone https://github.com/alirezasoleimani/SmartMemoryPool.git
cd SmartMemoryPool
cp MemoryPool.h /your-project/include/

🏗️ Architecture
┌─────────────────────────────────────────────────────────────┐
│                    SmartMemoryPool                          │
├─────────────────────────────────────────────────────────────┤
│  ┌───────────────────────────────────────────────────────┐ │
│  │           Pre-allocated Memory Block                  │ │
│  │  ┌─────────┬─────────┬─────────┬─────────┬─────┐    │ │
│  │  │ Block 0 │ Block 1 │ Block 2 │ Block 3 │ ... │    │ │
│  │  └─────────┴─────────┴─────────┴─────────┴─────┘    │ │
│  └───────────────────────────────────────────────────────┘ │
│                            │                                │
│                     ┌──────▼──────┐                        │
│                     │  Free-List  │                        │
│                     │  ┌───┐     │                        │
│                     │  │ 0 ├──┐  │                        │
│                     │  └───┘  │  │                        │
│                     │  ┌───┐  │  │                        │
│                     │  │ 1 │◄─┘  │                        │
│                     │  └───┘     │                        │
│                     └────────────┘                        │
│                                                           │
│  • O(1) allocate: remove first block from free-list      │
│  • O(1) free: add block to front of free-list            │
│  • No per-object overhead                                 │
│  • Excellent cache locality                               │
└─────────────────────────────────────────────────────────────┘

MIT License

Copyright (c) 2024 Alireza Soleimani

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
