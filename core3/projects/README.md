# Core3 : Projects

This directory contains all C++ projects organized into three categories.

## 📁 Category Overview

| Category | Focus |
|----------|-------|
| **Performance & Memory Optimization** | Low‑level memory management, custom allocators, memory tracking, and smart pointer pools. |
| **Algorithms & Problem Solving** | Classic algorithmic challenges, number theory, string manipulation, and game logic. |
| **Simulations & Real‑world Models** | Interactive simulations of clocks, geometry, vending machines, and line analysis. |

---

## ⚙️ Performance & Memory Optimization

| Project | Description |
|---------|-------------|
| `01_Memory_Allocator_Tracker` | Custom `new`/`delete` override with leak detection (raw allocator tracker). |
| `02_Memory_Dataset_Tracker` | Tracks named datasets with age and generates leak reports. |
| `03_Memory_SmartPool` | Connection pool implemented with `std::shared_ptr`. |
| `04_Unified_Memory_Debugger` | **Merged project** combining the three tools above into a single debugger suite. |

---

## 🧠 Algorithms & Problem Solving

| Project | Description |
|---------|-------------|
| `DayTypeIdentifier` | Determines if a given day is a weekday, weekend, or holiday. |
| `HappyNumberChecker` | Uses Floyd’s cycle detection to check if a number is a happy number. |
| `LargeNumberStorage` | Handles arithmetic with arbitrarily large integers (includes PDF on operator overloading). |
| `LeapYearChecker` | Validates leap years according to the Gregorian calendar. |
| `PalindromeChecker` | Tests if a string or number reads the same forwards and backwards. |
| `RomanNumeralConverter` | Converts between Roman numerals and integers (includes trace image). |
| `Sensor_Detector` | Simulates sensor data processing and detection logic. |
| `TicTacToeGame` | Console‑based two‑player Tic‑Tac‑Toe game. |

---

## 🎮 Simulations & Real‑world Models

| Project | Description |
|---------|-------------|
| `CircleSimulator` | Geometry and circle‑related calculations. |
| `ClockSimulator` | Digital / analog clock simulation. |
| `FruitJuiceMachineSimulator` | Vending machine logic for juice dispensers (includes two cash register versions). |
| `LineAnalyzer` | Analyzes line equations and intersections. |
| `WorldClockSimulator` | Displays clocks across multiple time zones. |

---

## 📜 Integrity Note

All commits in this repository preserve their **original author and commit dates** (no artificial timestamps). The category structure was applied retroactively using Git history rewriting while keeping every commit’s metadata intact. This ensures an authentic development timeline.

---

## 🔧 Usage

Each project directory contains its own `README.md` with build and run instructions.  
From the repository root, navigate to any project, e.g.:

```bash
cd "core3/projects/Performance & Memory Optimization/01_Memory_Allocator_Tracker"
make && ./main
