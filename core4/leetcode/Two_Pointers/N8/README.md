# LeetCode 189: Rotate Array (Medium)

## 🧩 Problem Statement

Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

A rotation by one step means:

- The last element moves to the first position.
- Every other element shifts one position to the right.

---

## Example 1

### Input

```text
nums = [1,2,3,4,5,6,7,8]
k = 4
```

### Output

```text
[5,6,7,8,1,2,3,4]
```

### Explanation

Rotate 1 step:

```text
[8,1,2,3,4,5,6,7]
```

Rotate 2 steps:

```text
[7,8,1,2,3,4,5,6]
```

Rotate 3 steps:

```text
[6,7,8,1,2,3,4,5]
```

Rotate 4 steps:

```text
[5,6,7,8,1,2,3,4]
```

---

## Example 2

### Input

```text
nums = [1000,2,4,-3]
k = 2
```

### Output

```text
[4,-3,1000,2]
```

### Explanation

Rotate 1 step:

```text
[-3,1000,2,4]
```

Rotate 2 steps:

```text
[4,-3,1000,2]
```

---

## Constraints

- `1 <= nums.length <= 100000`
- `-(2^31) <= nums[i] <= (2^31)-1`
- `0 <= k <= 100000`

---

# 💡 Approach: Array Reversal

The key observation is that rotating an array can be achieved using three reversals.

For rotating right by `k` positions:

1. Reverse the entire array.
2. Reverse the first `k` elements.
3. Reverse the remaining `n-k` elements.

Before:

```text
[1,2,3,4,5,6,7,8]
```

After reversing all:

```text
[8,7,6,5,4,3,2,1]
```

Reverse first `k = 4`:

```text
[5,6,7,8,4,3,2,1]
```

Reverse remaining:

```text
[5,6,7,8,1,2,3,4]
```

---

# 🔍 Complexity Analysis

### Time Complexity

Each element is reversed at most a constant number of times:

- Reverse whole array: `O(n)`
- Reverse first `k` elements: `O(k)`
- Reverse remaining elements: `O(n-k)`

Total:

\[
\boxed{O(n)}
\]

---

### Space Complexity

The algorithm modifies the array in-place and uses only constant extra variables.

\[
\boxed{O(1)}
\]

---

# ✅ Key Takeaways

- Rotating an array does not require extra memory.
- The reversal technique provides an elegant `O(n)` solution.
- Always use:

```cpp
k %= nums.size();
```

because rotating by `n` positions returns the original array.

---

## Topics

- Array
- Two Pointers
- Reversal Algorithm
- In-place Algorithm

---

## Company Tags

- Amazon
- Microsoft
- Google
- Apple
- Facebook

---

## Follow Up

**Could you do it in-place with O(1) extra space?**

Yes. The reversal approach solves it using:

- Time: `O(n)`
- Extra Space: `O(1)`


Video : https://www.youtube.com/watch?v=TYT5TJSfGlo&t=372s
