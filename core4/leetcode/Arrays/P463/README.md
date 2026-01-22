# LeetCode Problem 463: Island Perimeter (Easy)

## 🧩 Problem Statement

You are given a `row x col` grid representing a map:

- `grid[i][j] = 1` represents **land**  
- `grid[i][j] = 0` represents **water**

The grid cells are connected **horizontally/vertically** (not diagonally).  

The grid is completely surrounded by water and contains **exactly one island**. The island does not contain lakes (water inside not connected to outside).  

Each cell is a square with side length 1. The grid is rectangular, width and height ≤ 100.

**Goal:** Determine the **perimeter** of the island.

---

## 🔹 Examples

**Example 1:**
Input: grid = [[0,1,0,0],
[1,1,1,0],
[0,1,0,0],
[1,1,0,0]]
Output: 16
