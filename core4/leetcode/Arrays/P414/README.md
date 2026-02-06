# LeetCode Problem 414: Third Maximum Number (Easy)

## 🧩 Problem Statement

Given an integer array `nums`, return the **third distinct maximum number** in this array.  

- If the third maximum does not exist, return the **maximum number**.

---

## 🔹 Examples

**Example 1:**  
Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.
**Example 2:**  
Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned.

We solve this problem by:

1. **Sorting the input array** in descending order.  
2. **Removing duplicates** into a new array : Loop through the sorted array, and add a number only if it’s different from the last added number.  
3. **Returning**:
   - The **third maximum** if it exists,  
   - Otherwise, the **maximum**.

**Time Complexity:** O(n log n)  
**Space Complexity:** O(n) (for storing distinct elements)

Video Tutorial: 

