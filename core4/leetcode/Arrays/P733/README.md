# LeetCode Problem 733: Flood Fill (Easy)

## 🧩 Problem Statement

An **image** is represented by a 2D integer grid `image` where `image[i][j]` represents the color of the pixel at position `(i, j)`.

You are given three integers `sr`, `sc`, and `newColor`. Perform a **flood fill** on the image starting from the pixel `(sr, sc)`:

- Replace the color of the starting pixel and all **connected pixels** of the same color with `newColor`.
- Two pixels are connected if they are **4-directionally adjacent** (up, down, left, right) and have the same color as the starting pixel.

Return the **modified image** after performing the flood fill.

---

## 🔹 Examples

**Example 1:**

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

Video Tutorial (DFS): https://www.youtube.com/watch?v=JI_e2RzARbM 
