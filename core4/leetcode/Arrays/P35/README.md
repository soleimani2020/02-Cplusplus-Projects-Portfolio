# LeetCode Problem 35: Search Insert Position

## 🧩 Problem Statement

Given a sorted array of **distinct integers** and a target value, return the index if the target is found.  
If not, return the index where it would be inserted in order.

You must write an algorithm with **O(log n)** runtime complexity.

---

## ✅ Solution Approach

We use **Binary Search** because the array is sorted and we need logarithmic time complexity.

- If the target exists, return its index.
- If not, return the position where it should be inserted to keep the array sorted.

---

Video Tutorial: https://www.youtube.com/watch?v=p07ahfFzMi0
