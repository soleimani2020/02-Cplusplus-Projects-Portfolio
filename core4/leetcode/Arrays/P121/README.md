# LeetCode Problem 121: Best Time to Buy and Sell Stock (EASY)

## 🧩 Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the *i-th day*.

You want to maximize your profit by choosing a single day to **buy** one stock and a **different day in the future to sell** that stock.

Return the **maximum profit** you can achieve from this transaction.  
If no profit can be achieved, return `0`.

---

## 🔹 Examples

**Example 1:**  
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5

**Example 2:**  
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: No transaction is done, maximum profit = 0


## ✅ Solution Approach

- Track the **minimum price** seen so far while iterating through the array.  
- At each step, calculate the potential **profit** by selling at the current price.  
- Keep track of the **maximum profit** observed.  

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)`

---

Video Tutorial: https://www.youtube.com/watch?v=1pkOgXD63yU


