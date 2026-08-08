# Asteroid Collision

## Problem

You are given an array `asteroids` of integers representing asteroids in a row.

- The absolute value represents the size of the asteroid.
- The sign represents its direction:
  - Positive → moving right
  - Negative → moving left

All asteroids move at the same speed.

When two asteroids collide:
- The smaller asteroid explodes.
- If they are the same size, both explode.
- Asteroids moving in the same direction never collide.

Return the state of the asteroids after all collisions.

### Example 1

**Input:**
```text
asteroids = [5, 10, -5]


**Output:**

[5, 10]

**Input:**
```text
asteroids = [5, 10, -5]


Video Tutorial 1 : https://www.youtube.com/watch?v=LN7KjRszjk4


Video Tutorial 2 :https://www.youtube.com/watch?v=6GGTBM7mwfs


