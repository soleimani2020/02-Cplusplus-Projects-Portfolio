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

# 💡 Approach: Two Pointers

Since the array is already sorted, duplicate values appear next to each other.

Use two pointers:

- `read` scans every element.
- `write` points to the position where the next unique element should be placed.

Whenever a new unique value is found:

- Copy it to `nums[write]`.
- Increment `write`.

At the end:

- `write` equals the number of unique elements.

---

## Algorithm

1. Initialize:

```text
write = 1
```

2. Traverse the array using `read` from index `1`.

3. If:

```text
nums[read] != nums[read - 1]
```

copy the element:

```text
nums[write] = nums[read]
write += 1
```

4. Return `write`.

---

# ⏱️ Complexity Analysis

## Time Complexity

```text
O(n)
```

Each element is visited exactly once.

## Space Complexity

```text
O(1)
```

The algorithm modifies the array in-place.

---

# 💻 Solutions

## C++

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty())
            return 0;

        int write = 1;

        for(int read = 1; read < nums.size(); read++) {

            if(nums[read] != nums[read - 1]) {
                nums[write] = nums[read];
                write++;
            }
        }

        return write;
    }
};
```

---

## Python

```python
class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:

        if not nums:
            return 0

        write = 1

        for read in range(1, len(nums)):

            if nums[read] != nums[read - 1]:
                nums[write] = nums[read]
                write += 1

        return write
```

---

## 🎥 Video Tutorial

https://www.youtube.com/watch?v=DEJAZBq0FDA
