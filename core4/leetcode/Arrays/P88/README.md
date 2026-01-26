# LeetCode Problem 88: Merge Sorted Array

## 🧩 Problem Statement

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n` representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums2` into `nums1` so that `nums1` becomes a single array sorted in **non-decreasing order**.

**Note:**  
- The final sorted array **should not be returned** by the function.  
- Instead, it should be stored inside the array `nums1`.  
- `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored.  
- `nums2` has a length of `n`.

---

## 🔹 Examples

**Example 1:**  

Input: nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3
Output: nums1 = [1,2,2,3,5,6]



## ✅ Solution Approach

We solve this **in-place** by filling `nums1` from the **end**:

1. Use three pointers:  
   - `p1` pointing at the last element of the initial `nums1` (`m-1`)  
   - `p2` pointing at the last element of `nums2` (`n-1`)  
   - `p` pointing at the last position of `nums1` (`m+n-1`)  

2. Compare `nums1[p1]` and `nums2[p2]` and place the larger value at `nums1[p]`.  
3. Move the pointers accordingly and continue until all elements are merged.  
4. If `nums2` still has remaining elements, copy them to the start of `nums1`.

**Time Complexity:** `O(m + n)`  
**Space Complexity:** `O(1)` (in-place)

---
