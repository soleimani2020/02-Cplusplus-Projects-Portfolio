# Maximum Frequency Stack

[![LeetCode](https://img.shields.io/badge/LeetCode-895-orange?style=flat-square&logo=leetcode)](https://leetcode.com/problems/maximum-frequency-stack/)
[![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red?style=flat-square)]()
[![Topics](https://img.shields.io/badge/Topics-Stack%20%7C%20Hash%20Table%20%7C%20Design-blue?style=flat-square)]()

---

## Problem Statement

Design a stack-like data structure that supports the following operations:

- **`push(int val)`** – pushes an integer `val` onto the stack.
- **`pop()`** – removes and returns the **most frequent** element in the stack.
  - If there is a tie (multiple elements have the same highest frequency), the element that is **closest to the top** of the stack (i.e., the most recently pushed among those with the highest frequency) is removed and returned.

Implement the `FreqStack` class:

```java
class FreqStack {
    public FreqStack() { ... }
    public void push(int val) { ... }
    public int pop() { ... }
}
