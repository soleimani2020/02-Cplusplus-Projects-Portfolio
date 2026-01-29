# LeetCode Problem 88: Convert Sorted Array to Binary Search Tree

## 🧩 Problem Statement

You are given an integer array `nums` sorted in **ascending order**.  
Convert it into a **height-balanced binary search tree (BST)**.

A height-balanced BST is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

---

## 🔹 Examples

**Example 1:**  
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible height-balanced BST is shown.


To construct a **height-balanced BST**:

1. Choose the **middle element** of the array as the root.
2. Recursively build the **left subtree** from the left half.
3. Recursively build the **right subtree** from the right half.

This ensures the tree remains balanced.

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(log n)` (recursion stack)

---
