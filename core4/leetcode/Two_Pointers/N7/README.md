# LeetCode Problem 15: 3Sum (Medium)

## 🧩 Problem Statement

Given an integer array `nums`, return all the unique triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`
- `i != k`
- `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must **not contain duplicate triplets**.

---

## 💡 Approach

### 1. Sort the Array

Sorting allows us to efficiently use the two-pointer technique and makes duplicate handling straightforward.

### 2. Iterate Through the Array

Treat each element `nums[i]` as the first number of a potential triplet.

- Skip duplicate values to avoid generating identical triplets.
- If `nums[i] > 0`, stop early because the remaining numbers are also positive.

### 3. Two-Pointer Search

For each fixed element:

- Set `left = i + 1`
- Set `right = n - 1`

Compute:

```cpp
sum = nums[i] + nums[left] + nums[right];
```

- If `sum == 0`, store the triplet.
- If `sum < 0`, move `left` forward.
- If `sum > 0`, move `right` backward.

After finding a valid triplet, skip duplicate values on both pointers.

---

## ✅ Correctness

The algorithm guarantees:

- Every triplet sums to zero.
- No duplicate triplets are returned.
- Every possible valid triplet is considered exactly once.

---

## ⏱ Complexity Analysis

### Time Complexity

- Sorting: **O(n log n)**
- Outer loop: **O(n)**
- Two-pointer search: **O(n)**

Overall:

**O(n²)**

---

### Space Complexity

Ignoring the output array:

**O(1)**

---



---

## Example

### Input

```text
nums = [-1,0,1,2,-1,-4]
```

### Output

```text
[
  [-1,-1,2],
  [-1,0,1]
]
```

---





Video : https://www.youtube.com/watch?v=cRBSOz49fQk

video2: https://www.youtube.com/watch?v=K-RsltkN63w&t=6s
