# LeetCode Problem 169: Majority Element (EASY)

## 🧩 Problem Statement

Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears more than ⌊n / 2⌋ times.  
You may assume that the majority element **always exists** in the array.

---

## 🔹 Examples

**Example 1:** 

Input: nums = [3,2,3]
Output: 3


## ✅ Solution Approach

We use the **Boyer-Moore Voting Algorithm** to find the majority element in **linear time and constant space**:

1. Initialize a **candidate** and a **count**.  
2. Iterate through the array:  
   - If `count == 0`, set `candidate = nums[i]`.  
   - If `nums[i] == candidate`, increment `count`.  
   - Otherwise, decrement `count`.  
3. The final `candidate` is the majority element.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)`

Video tutorial: https://www.youtube.com/watch?v=7pnhv842keE
