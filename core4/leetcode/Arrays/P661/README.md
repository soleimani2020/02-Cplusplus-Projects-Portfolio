# LeetCode Problem 661: Image Smoother (3×3 Filter)

## 🧩 Problem Statement

## 📌 Overview
The **Image Smoother** is a simple image processing algorithm that applies a **3 × 3 averaging filter** to smooth an image.

Each pixel in the image is replaced by the **floor of the average** of itself and its surrounding neighbors.

This technique helps reduce noise and create a smoother visual appearance.

---

## ⚙️ How It Works

For every cell (pixel) in the image:

- Consider the **current cell + its 8 neighboring cells** (a 3×3 grid).
- Compute the **average value** of these cells.
- **Round down** the result (i.e., take the floor).
- Assign this value to the output image.

### ⚠️ Edge Handling

If a cell is on the border and some neighbors are missing:
- Only use the **existing neighboring cells**.
- Compute the average based on **available cells only**.

---
