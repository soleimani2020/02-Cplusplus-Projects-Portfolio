# LeetCode Problem 448: Find All Numbers Disappeared in an Array (Easy)

## 🧩 Problem Statement

Given an integer array `nums` of length `n` where **nums[i] is in the range [1, n]**, some elements may appear **twice** and others **once**.  

Return an array of all the **numbers in the range [1, n] that do not appear in `nums`]**.

You must solve the problem with **O(n) time complexity** and **without using extra space** (disregarding the output array).

---

## 🔹 Examples

**Example 1:**  
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]


---

## ✅ Solution Approach — In-Place Marking Trick

We use the array itself to mark visited numbers:

1. For each number `x` in the array, mark the element at index `abs(x) - 1` as **negative**.
2. After processing, any index that still contains a **positive** number means its index + 1 is missing.
3. Collect and return all such indices + 1.

---

## ⏱ Complexity Analysis

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1) extra space (output array not counted)


Video Tutorial : https://www.youtube.com/watch?v=oEBHLcucDYg
