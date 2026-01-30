# LeetCode Problem 136: Single Number (EASY)

## 🧩 Problem Statement

Given a **non-empty array** of integers `nums`, every element appears **twice** except for **one**.  
Find that single element.

**Note:** You must implement a solution with:

- **Linear runtime complexity** (`O(n)`)  
- **Constant extra space** (`O(1)`)

---

## 🔹 Examples

**Example 1:** 
Input: nums = [2,2,1]
Output: 1


## ✅ Solution Approach

- Use the **XOR operator** (`^`) to find the unique element:
  - `a ^ a = 0`  
  - `a ^ 0 = a`
- XOR all elements in the array.  
- All duplicates cancel out, leaving the single number.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)`


Video Tutorial: https://www.youtube.com/watch?v=sFBCAl8yBfE
