# LeetCode Problem 125: Valid Palindrome (Easy)

## 🧩 Problem Statement

Given a string `s`, return `true` if it is a palindrome, otherwise return `false`.

A palindrome is a string that reads the same forward and backward.

The comparison should be:
- **Case-insensitive**
- Ignoring all **non-alphanumeric characters**

A character is alphanumeric if it is a letter (`A-Z`, `a-z`) or a number (`0-9`).

---

## Constraints

- `1 <= s.length <= 2 * 10^5`
- `s` consists only of printable ASCII characters.
- The solution should be efficient for large strings.

---

## Example 1

```python
Input: s = "Was it a car or a cat I saw?"

Output: True

Explanation:
After removing non-alphanumeric characters and converting
uppercase letters to lowercase:

"wasitacaroracatisaw"

The string reads the same forward and backward.
