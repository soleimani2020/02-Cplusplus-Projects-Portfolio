# LeetCode 150: Evaluate Reverse Polish Notation (Medium)

## 🧩 Problem Statement

You are given an array of strings `tokens` that represents a valid arithmetic expression in **Reverse Polish Notation (RPN)**.

Return the integer result of evaluating the expression.

### Rules

- Operands may be integers or results of other operations.
- Operators include:
  - `+`
  - `-`
  - `*`
  - `/`
- Division between integers truncates toward zero.

---

## 💡 Approach: Stack

Reverse Polish Notation places operators **after** their operands.

Example:
["2","1","+","3","*"]


represents:


(2 + 1) * 3 = 9


Video Tutorial : https://www.youtube.com/watch?v=8VYdGvOnkl0&t=365s
