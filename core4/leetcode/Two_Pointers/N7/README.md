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

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        if (nums.size() < 3)
            return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {

            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;

                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};
```

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

## Key Techniques

- Sorting
- Two Pointers
- Duplicate Removal
- Greedy Pointer Movement

---

## Tags

`Array` `Two Pointers` `Sorting`




Video : https://www.youtube.com/watch?v=cRBSOz49fQk

video2: https://www.youtube.com/watch?v=K-RsltkN63w&t=6s
