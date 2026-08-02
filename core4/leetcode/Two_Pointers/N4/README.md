# LeetCode Problem 1768: Merge Strings Alternately (Easy)

## 🧩 Problem Statement

You are given two strings `word1` and `word2`.

Construct a new string by merging them in **alternating order**:

- Take one character from `word1`.
- Then take one character from `word2`.
- Continue this process until all characters are used.

If one string is longer than the other, append the remaining characters to the end of the merged string.

Return the final merged string.

---

## Constraints

- `1 <= word1.length, word2.length <= 100`
- `word1` and `word2` consist of lowercase English letters.

---

## Example 1

```python
Input:
word1 = "abc"
word2 = "xyz"

Output:
"axbycz"

Explanation:

Take characters alternately:

word1: a b c
word2: x y z

Result:
a x b y c z

---

Video: https://www.youtube.com/watch?v=qq-AqEPKsI8
