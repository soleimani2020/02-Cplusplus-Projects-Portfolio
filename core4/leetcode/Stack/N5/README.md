# Next Greater Element I
## 🧩  Problem Statement

Given two arrays `nums1` and `nums2` where `nums1` is a subset of `nums2`, find the next greater element for each element in `nums1`.

The **Next Greater Element** of an element `x` in `nums2` is the first element to the right of `x` that is greater than `x`.  
If no such element exists, return `-1`.

---

## Approach: Monotonic Stack + Hash Map

### Idea

1. Traverse `nums2` from **right to left**.
2. Use a stack to maintain decreasing elements.
3. For each element:
   - Remove all smaller or equal elements from the stack.
   - The top of the stack is the next greater element.
   - Store the result in a hash map.
4. For every element in `nums1`, retrieve the answer from the map.

---

## Example

### Input

```
nums1 = [4,1,2]
nums2 = [1,3,4,2]
```



## Complexity Analysis

| Operation | Complexity |
|-----------|-------------|
| Build map using stack | O(n) |
| Query nums1 | O(m) |
| Total Time | **O(n + m)** |
| Space | **O(n)** |

Where:
- `n` = size of `nums2`
- `m` = size of `nums1`

---

## Key Concepts

- Monotonic Stack
- Hash Map
- Next Greater Element Pattern
- Stack-based Optimization

---

Video Tutorial 1: https://www.youtube.com/watch?v=NKbExYwvjb0

Video Tutorial 2: [https://www.youtube.com/watch?v=NKbExYwvjb0](https://www.youtube.com/watch?v=mJWQjJpEMa4&t=709s)

