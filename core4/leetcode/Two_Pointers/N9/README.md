# LeetCode 11: Container With Most Water (Medium)

## 🧩 Problem Statement

You are given an integer array `height` where:

- `height[i]` represents the height of the `i-th` bar.
- There are `n` vertical lines drawn such that the endpoints of the `i-th` line are `(i,0)` and `(i,height[i])`.

Choose two lines that, together with the x-axis, form a container that holds the most water.

Return the maximum amount of water a container can store.

---

## Example 1

### Input

```text
height = [1,8,6,2,5,4,8,3,7]
```

### Output

```text
49
```

### Explanation

The container is formed by the lines at index `1` and index `8`.

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

## Example 2

### Input

```text
height = [1,1]
```

### Output

```text
1
```

---

## Constraints

- `n == height.length`
- `2 <= n <= 100000`
- `0 <= height[i] <= 10000`

---

# 💡 Approach: Two Pointers

## Observation

The amount of water between two lines is:

\[
Area = min(height[left], height[right]) \times (right-left)
\]

A brute-force solution checks every pair:

\[
O(n^2)
\]

which is too slow.

---

## Two Pointer Strategy

Start with:

- `left` pointer at the beginning.
- `right` pointer at the end.

The width is maximum initially.

At each step:

1. Calculate current area.
2. Update maximum area.
3. Move the pointer with the smaller height.

Why?

The shorter line limits the amount of water. Moving the taller line cannot increase the height, so we move the shorter one hoping to find a taller boundary.

---

## Example

Input:

```text
[1,8,6,2,5,4,8,3,7]
```

Initial:

```text
left = 0
right = 8
```

Area:

```text
min(1,7) * 8 = 8
```

Since:

```text
height[left] < height[right]
```

move `left`.

Continue until:

```text
left >= right
```

The maximum area found is:

```text
49
```


---

# 🔍 Complexity Analysis

## Time Complexity

Each pointer moves only once:

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

- The area is limited by the shorter line.
- Two pointers reduce the brute-force `O(n^2)` solution to `O(n)`.
- Always move the pointer pointing to the smaller height.
- The maximum width is obtained by starting with both ends.

---

## Topics

- Array
- Two Pointers
- Greedy Algorithm

---

## Company Tags

- Amazon
- Google
- Microsoft
- Meta
- Apple
- Bloomberg

---

## Follow Up

Can you solve it without using extra memory?

Yes. The two-pointer approach uses:

- Time: `O(n)`
- Space: `O(1)`

  
Video Tutorial: https://www.youtube.com/watch?v=w7ftYsZtIbs&t=432s
