# LeetCode Problem 2000: Reverse Prefix of Word (Easy)

## 🧩 Problem Statement

Given a **0-indexed string** `word` and a character `ch`, reverse the segment of `word` that starts at index `0` and ends at the index of the **first occurrence** of `ch` (inclusive).

If the character `ch` does not exist in `word`, return the original string unchanged.

### Constraints

- `1 <= word.length <= 250`
- `word` consists of lowercase English letters.
- `ch` is a lowercase English letter.
- The solution should use:
  - **O(n) time complexity**
  - **O(1) extra space**

---

## Example 1

```text
Input:
word = "abcdefd"
ch = "d"

Output:
"dcbaefd"
