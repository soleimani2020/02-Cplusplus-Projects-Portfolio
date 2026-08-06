# LeetCode 88: Merge Sorted Array

## 🧩 Problem Statement

You are given two sorted integer arrays `nums1` and `nums2`.

- `nums1` has a length of `m + n`, where the first `m` elements contain valid numbers and the last `n` elements are `0` placeholders.
- `nums2` has `n` elements.

Merge `nums2` into `nums1` so that `nums1` becomes a single sorted array.

The merge must be done **in-place**.

---

## 💡 Approach: Two Pointers (From the End)

### Key Idea

Instead of merging from the beginning, we merge from the **end** of `nums1`.

Why?

`nums1` already has empty spaces at the end, so filling from the back avoids overwriting existing elements.

We use three pointers:

- `i` → last valid element in `nums1`
- `j` → last element in `nums2`
- `k` → last position of `nums1`

At each step:
1. Compare `nums1[i]` and `nums2[j]`.
2. Place the larger value at `nums1[k]`.
3. Move the corresponding pointer backward.

---

