# LeetCode Problem 118: Pascal's Triangle (EASY)

## 🧩 Problem Statement

Given an integer `numRows`, return the first `numRows` of **Pascal's triangle**.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

---

## 🔹 Examples

**Example 1:**  

Input: numRows = 5
Output:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]

## ✅ Solution Approach

1. Start with the first row `[1]`.
2. For each new row:
   - Set the first and last elements to `1`.
   - Each inner element is the sum of the two elements above it.
3. Repeat until `numRows` rows are generated.

**Time Complexity:** `O(n²)`  
**Space Complexity:** `O(n²)`


Video Tutorial: https://www.youtube.com/watch?v=nFqeCXOJn0I
