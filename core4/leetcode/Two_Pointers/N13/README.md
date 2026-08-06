# LeetCode Problem 541: Reverse String II (Easy)

## 🧩 Problem Statement

Given a string `s` and an integer `k`, reverse the first `k` characters for every `2k` characters counting from the beginning of the string.

If fewer than `k` characters remain, reverse all remaining characters.

If at least `k` but fewer than `2k` characters remain, reverse the first `k` characters and leave the rest unchanged.

The reversal must be done **in-place**.

### Constraints

- `1 <= s.length <= 10^4`
- `s` consists of only lowercase English letters.
- `1 <= k <= 10^4`
- The solution should use:
  - **O(n) time complexity**
  - **O(1) extra space** (excluding the input string)

---

## Example 1

```text
Input:
s = "abcdefg"
k = 2

Output:
"bacdfeg"

Video : https://www.youtube.com/watch?v=SUrrSVfk7pk&t=29s
