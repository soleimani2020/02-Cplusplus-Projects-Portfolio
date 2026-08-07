# LeetCode Problem: Decode String (Medium)

## 🧩 Problem Statement

Decode a string using the rule `k[encoded_string]`, where the substring inside brackets is repeated `k` times. Use a stack to handle nested brackets by storing previous strings and repeat counts. When a closing bracket `]` is found, reconstruct the decoded substring.  

**Concepts:** Stack, String Parsing, Nested Expressions  
**Complexity:** Time `O(n)`, Space `O(n)`


The key idea:

ans is like a scratchpad.

Before [ → it contains the string before entering a new level.
After [ → it becomes empty and starts collecting the inside.
Before ] → it contains the completed inner string.
After ] → it becomes the expanded result.

A good sentence to remember:

ans always stores the decoded string at my current depth. When I go deeper, I reset it. When I come back, I merge it with the previous level.


🔗 Video

https://www.youtube.com/watch?v=E9qHRcQXmDk&t=15s
