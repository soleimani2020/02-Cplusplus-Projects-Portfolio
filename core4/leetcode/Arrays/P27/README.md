# LeetCode Problem 27: Remove Element

## 🧩 Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place. The order of the elements may be changed. Return the number of elements that are not equal to `val`.

Let `k` be the number of elements not equal to `val`. After the operation:

- The first `k` elements of `nums` should contain the elements not equal to `val`.
- The remaining elements are not important.
- Return `k`.

---

## ✅ Solution Approach

We use a **two-pointer** technique:

- One pointer scans the array.
- Another pointer keeps track of where to place the next valid (non-`val`) element.

This runs in **O(n)** time and **O(1)** extra space.

Video Tutotial : https://www.youtube.com/watch?v=j8IZXlWJMLo

---

