# LeetCode Problem: Largest Rectangle in Histogram (Hard)

## 🧩 Problem Statement

Given an array of integers `heights` where:

- `heights[i]` represents the height of the `i-th` bar.
- The width of each bar is `1`.

Return the area of the largest rectangle that can be formed inside the histogram.

The area of a rectangle is:

```
Area = height × width
```

---

## 💡 Approach: Monotonic Stack

### Idea

The challenge is to find the maximum rectangle that can be created using consecutive bars.

For each bar, we need to determine:

- How far the bar can extend to the left.
- How far the bar can extend to the right.

A **monotonic increasing stack** helps efficiently find these boundaries.

### Algorithm

1. Traverse the histogram from left to right.
2. Maintain a stack containing indices of bars with increasing heights.
3. When a smaller height is encountered:
   - The taller bars in the stack cannot extend further.
   - Calculate the area using the popped bar as the rectangle height.
4. Keep track of the maximum area found.

---

## 🔎 Example

Input:

```
heights = [2,1,5,6,2,3]
```

Histogram:

```
        |
      | |
      | |
  |   | |
  |   | |
----------------
2  1  5  6  2  3
```

The largest rectangle:

```
height = 5
width = 2

Area = 5 × 2 = 10
```

Output:

```
10
```

---

## 🧠 Key Insight

The largest rectangle is not always created by the tallest bar.

A shorter bar may create a larger rectangle because it can extend across multiple adjacent bars.

Example:

```
height = small
width = large
```

can be larger than:

```
height = large
width = small
```

---

## ⏱️ Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Histogram traversal | O(n) |
| Stack processing | O(n) |
| Total Time Complexity | **O(n)** |
| Space Complexity | **O(n)** |

---

Video Tutorial 0 (best) : https://www.youtube.com/watch?v=vcv3REtIvEo

Video Tutorial 1 : https://www.youtube.com/watch?v=IasMlShanvc

Video Tutorial 2 : https://www.youtube.com/watch?v=vcv3REtIvEo

