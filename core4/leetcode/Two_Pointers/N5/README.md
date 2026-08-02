# LeetCode Problem 26: Remove Duplicates from Sorted Array (Easy)

## 🧩 Problem Statement

You are given a sorted integer array `nums` in **non-decreasing order**.

Remove the duplicates **in-place** so that each unique element appears only once.

Return the number of unique elements, denoted as `k`, such that the first `k` elements of `nums` contain all the unique values.

### Notes

- The relative order of the unique elements must remain the same.
- You must modify the array **in-place**.
- It does not matter what values remain after the first `k` positions.

---

## Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is sorted in non-decreasing order.

---

## Example 1

```python
Input:
nums = [1,1,2]

Output:
k = 2
nums = [1,2,_]

Explanation:
The first two elements are the unique values: [1,2].
The remaining elements are ignored.
```

---

## Example 2

```python
Input:
nums = [0,0,1,1,1,2,2,3,3,4]

Output:
k = 5
nums = [0,1,2,3,4,_,_,_,_,_]

Explanation:
The first five elements contain all unique values.
```

---


## 🎥 Video Tutorial

https://www.youtube.com/watch?v=oMr9lehS7Us

https://www.youtube.com/watch?v=DEJAZBq0FDA](https://www.youtube.com/watch?v=oMr9lehS7Us
