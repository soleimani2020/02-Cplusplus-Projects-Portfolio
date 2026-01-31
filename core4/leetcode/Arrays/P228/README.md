# LeetCode Problem 228: Summary Ranges

## 🧩 Problem Statement

You are given a **sorted unique integer array** `nums`.

A **range** `[a,b]` is the set of all integers from `a` to `b` (inclusive).

Return the **smallest sorted list of ranges** that cover all the numbers in the array exactly.  
Each element of `nums` should be covered by **exactly one range**, and no integer outside of `nums` should be included.

---

## 🔹 Examples

**Example 1:**  
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are [0,1,2], [4,5], and [7].

---

## ✅ Solution Approach

1. Initialize `start` to the first number of the current range.  
2. Iterate through the array:
   - If the current number is **not consecutive** from the previous, close the current range and start a new range.  
3. After iteration, add the **last range**.  
4. Return the list of ranges in **string format**:  
   - Single number: `"a"`  
   - Range: `"a->b"`

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)`

---

Video Tutorial : https://www.youtube.com/watch?v=ZHJDwbfqoa8

