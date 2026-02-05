# LeetCode Problem 304: Range Sum Query 2D – Immutable (Medium)

## 🧩 Problem Statement

Given a 2D matrix `matrix`, handle multiple queries of the following type:

- Calculate the **sum of the elements** of `matrix` inside the rectangle defined by its **upper left corner** `(row1, col1)` and **lower right corner** `(row2, col2)`.

You need to implement the `NumMatrix` class:

1. `NumMatrix(vector<vector<int>>& matrix)`  
   Initializes the object with the integer matrix `matrix`.  

2. `int sumRegion(int row1, int col1, int row2, int col2)`  
   Returns the **sum of the elements** inside the rectangle defined by `(row1, col1)` and `(row2, col2)`.

**Note:** `sumRegion` should work in **O(1) time complexity**.

---

## 🔹 Examples

**Example 1:**  

NumMatrix numMatrix = new NumMatrix(matrix);
numMatrix.sumRegion(2,1,4,3); // return 8
numMatrix.sumRegion(1,1,2,2); // return 11
numMatrix.sumRegion(1,2,2,4); // return 12


Video Tutorial: https://www.youtube.com/watch?v=WibxoqMSMCw
