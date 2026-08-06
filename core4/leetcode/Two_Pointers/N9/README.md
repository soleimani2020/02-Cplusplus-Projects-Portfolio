# LeetCode 11: Container With Most Water (Medium)

## 🧩 Problem Statement

You are given an integer array `height` where:

- `height[i]` represents the height of the `i-th` bar.
- There are `n` vertical lines drawn such that the endpoints of the `i-th` line are `(i,0)` and `(i,height[i])`.

Choose two lines that, together with the x-axis, form a container that holds the most water.

Return the maximum amount of water a container can store.

---

# Example 1

## Input

```text
height = [1,8,6,2,5,4,8,3,7]
```

## Output

```text
49
```

## Explanation

The optimal container is formed by:

```text
index 1 and index 8
```

Height:

```text
min(8,7) = 7
```

Width:

```text
8 - 1 = 7
```

Area:

```text
7 * 7 = 49
```

---

# Example 2

## Input

```text
height = [1,1]
```

## Output

```text
1
```

---

# Constraints

- `n == height.length`
- `2 <= n <= 100000`
- `0 <= height[i] <= 10000`

---

# 💡 Approach: Two Pointers

## Observation

The amount of water stored between two lines is:

\[
Area = min(height[left], height[right]) \times (right-left)
\]

A brute-force approach checks every pair of lines:

\[
O(n^2)
\]

which is too slow for:

```text
n = 100000
```

---

# Two Pointer Strategy

Initialize:

```text
left = 0
right = n - 1
```

The initial width is maximum.

At every step:

1. Calculate the current area.
2. Update the maximum area.
3. Move the pointer with the smaller height.

---

## Why move the smaller height?

The shorter line limits the amount of water.

Example:

```text
height[left] = 3
height[right] = 8
```

The container height is:

```text
min(3,8) = 3
```

Moving the taller line:

```text
8 -> another value
```

cannot increase the height limit.

Therefore, we move the shorter line hoping to find a taller boundary.

---

# Algorithm Walkthrough

Example:

```text
height = [1,8,6,2,5,4,8,3,7]
```

Initial:

```text
left = 0
right = 8
```

Area:

```text
min(1,7) * (8-0)

= 1 * 8

= 8
```

Since:

```text
height[left] < height[right]
```

move:

```text
left++
```

Continue until:

```text
left >= right
```

Maximum area:

```text
49
```

# 🔍 Complexity Analysis

## Time Complexity

Each pointer moves at most `n` times:

\[
\boxed{O(n)}
\]

---

## Space Complexity

Only constant variables are used:

\[
\boxed{O(1)}
\]

---

# ✅ Key Takeaways

- The shorter line determines the container height.
- Starting from both ends gives maximum width.
- Two pointers reduce the solution from `O(n^2)` to `O(n)`.
- Always move the pointer with the smaller height.
- The algorithm works in-place without extra memory.

---

# Topics

- Array
- Two Pointers
- Greedy Algorithm

---

# Company Tags

- Amazon
- Google
- Microsoft
- Meta
- Apple
- Bloomberg

---

# Follow Up

Can you solve it without using extra memory?

Yes.

The two-pointer approach achieves:

```text
Time Complexity:  O(n)
Space Complexity: O(1)
```

---

# Video Tutorial

https://www.youtube.com/watch?v=w7ftYsZtIbs&t=432s
