# LeetCode 20: Valid Parentheses (Easy)

## 🧩 Problem Statement

Given a string `s` containing:

```text
'(', ')', '{', '}', '[', ']'

Return true if the brackets are valid.

A valid string means:

Every opening bracket has the same type closing bracket.
Brackets are closed in the correct order.

Complexity

Time: O(n)
Space: O(n)

### Algorithm in words

1. Create an empty **stack**.
2. Go through the string **character by character**.
3. If the character is an **opening bracket** `(`, `[`, `{`, push it onto the stack.
4. If it is a **closing bracket**:
   - If the stack is empty → return `false`.
   - Check the top element of the stack.
   - If it does not match the closing bracket → return `false`.
   - If it matches → remove it from the stack.
5. After processing the whole string:
   - If the stack is empty → return `true`.
   - Otherwise → return `false`.

**Key idea:** Every closing bracket must match the **most recently opened bracket**.


Video Tutorial : https://www.youtube.com/watch?v=PeItw8HD7cA
