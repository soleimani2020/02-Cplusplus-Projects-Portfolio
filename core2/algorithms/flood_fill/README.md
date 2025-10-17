# 🌊 Flood Fill Algorithm Using DFS in C++

This repository demonstrates the **Flood Fill algorithm** implemented in **C++** using **Depth-First Search (DFS)**.

---

## 🧠 Algorithm Summary

Flood Fill is used to **replace a color/value in a 2D grid** starting from a specific cell, filling all connected cells of the same color.

**Steps:**

1. Start from a given cell `(x, y)` in the grid.
2. Check if the cell matches the **target color**.
3. If it does, **replace it with the new color**.
4. Recursively explore in **4 directions**:
   - ↖ **Up** `(x-1, y)`
   - ↗ **Right** `(x, y+1)`
   - ↘ **Down** `(x+1, y)`
   - ↙ **Left** `(x, y-1)`
5. Skip cells that are:
   - ⛔ Out of bounds
   - ⛔ Already filled
   - ⛔ Not matching the target color
6. Stops when **all connected matching cells are filled**.

> Follows **DFS**: explores deeply before backtracking.

---
