# LeetCode Problem 3794: Reverse String Prefix (Easy)

## 🧩 Problem Statement

You are given a string `s` and an integer `k`.

Reverse the first `k` characters of `s` and return the resulting string.

The remaining characters after the first `k` characters should stay unchanged.

### Constraints

- `1 <= s.length <= 10^5`
- `1 <= k <= s.length`
- `s` consists of lowercase English letters.
- The solution should use:
  - **O(n) time complexity**
  - **O(1) extra space**

---

## Example 1

```text
Input:
s = "abcd"
k = 2

Output:
"bacd"
