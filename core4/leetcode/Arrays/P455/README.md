# LeetCode Problem 455: Assign Cookies (Easy)

## 🧩 Problem Statement

You are an awesome parent and want to give your children some cookies — but each child can receive **at most one cookie**.

- Each child `i` has a **greed factor** `g[i]`, which is the minimum cookie size they need.
- Each cookie `j` has a size `s[j]`.

A child is content if `s[j] >= g[i]`.

Your goal is to **maximize the number of content children**.

---

## 🔹 Examples

**Example 1:**
Input: g = [1,2,3], s = [1,1]
Output: 1


---

## ✅ Solution Approach — Greedy Strategy

1. Sort both the greed array `g` and the cookie sizes array `s`.
2. Use two pointers:
   - One for children.
   - One for cookies.
3. Try to assign the smallest possible cookie that satisfies each child.
4. Count how many children can be satisfied.

---

## ⏱ Complexity Analysis

- **Time Complexity:** O(n log n) due to sorting  
- **Space Complexity:** O(1) extra space (excluding input storage)


Video Tutorial: https://www.youtube.com/watch?v=biFWx4Z5Cr0
