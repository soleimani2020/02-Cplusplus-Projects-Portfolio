# LeetCode Problem 167: Two Sum II - Input Array Is Sorted (Medium)

## 🧩 Problem Statement

Given an array of integers `numbers` that is sorted in **non-decreasing order**, find two numbers such that they add up to a specific `target` number.

Return the indices of the two numbers as an array `[index1, index2]`, where:

- `index1` and `index2` are **1-indexed**.
- `index1 < index2`.
- The same element cannot be used twice.
- There is exactly one solution.
- The solution must use **O(1) extra memory**.

### Constraints

- `2 <= numbers.length <= 3 * 10^4`
- `-1000 <= numbers[i] <= 1000`
- `numbers` is sorted in non-decreasing order.
- `-1000 <= target <= 1000`

---

## Example

```python
Input: numbers = [1,2,3,4], target = 3

Output: [1,2]
