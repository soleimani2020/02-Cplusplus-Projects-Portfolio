# LeetCode Problem 42: Trapping Rain Water (Hard)

## 🧩 Problem Statement

You are given an array of non-negative integers `height` representing an elevation map.

Each value:

- `height[i]` represents the height of a bar.
- Each bar has a width of `1`.

After raining, water can be trapped between the bars.

Return the total amount of trapped water.

The solution should be efficient and use constant extra memory.

### Constraints

- `1 <= height.length <= 2 * 10^4`
- `0 <= height[i] <= 10^5`
- The answer fits in a 32-bit integer.
- You should aim for:
  - **O(n) time complexity**
  - **O(1) extra space**

---

## Example 1

```text
Input:
height = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:
6


Video Tutorial: https://www.youtube.com/watch?v=09KF1hjWoSU&t=1023s
