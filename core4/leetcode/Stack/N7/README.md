# LeetCode Problem: Car Fleet (Medium)

## 🧩 Problem Statement

There are `n` cars traveling to the same destination on a one-lane highway.

You are given:

- `target` – the destination position.
- `position[]` – the starting position of each car.
- `speed[]` – the speed of each car.

A car can never pass another car ahead of it. If a faster car catches up to a slower car, they form a **car fleet** and continue traveling together at the slower car's speed.

Return the number of **car fleets** that will arrive at the destination.

---

## 💡 Approach: Sorting + Monotonic Stack

### Idea

The key observation is that each car can be represented by the **time** it takes to reach the destination:

```text
time = (target - position) / speed
```

### Algorithm

1. Pair each car's **position** with its **arrival time**.
2. Sort the cars by their **position** in ascending order.
3. Traverse the cars from **right to left** (closest to the destination first).
4. Maintain a stack of arrival times.
5. If the current car's arrival time is **greater** than the fleet ahead, it forms a **new fleet**.
6. Otherwise, it catches up and joins the existing fleet.

---

## 🔎 Example

Input:

```text
target = 12

position = [10,8,0,5,3]

speed = [2,4,1,1,3]
```

Arrival times:

| Position | Speed | Time to Target |
|---------:|------:|---------------:|
| 0 | 1 | 12 |
| 3 | 3 | 3 |
| 5 | 1 | 7 |
| 8 | 4 | 1 |
| 10 | 2 | 1 |

Traverse from right to left:

```text
Position 10 → Fleet 1

Position 8  → Time = 1
             Joins Fleet 1

Position 5  → Time = 7
             Forms Fleet 2

Position 3  → Time = 3
             Joins Fleet 2

Position 0  → Time = 12
             Forms Fleet 3
```

Output:

```text
3
```

---

## 🧠 Key Insight

A car can only:

- Form a **new fleet**, or
- Catch up to the fleet immediately ahead.

If its arrival time is **less than or equal to** the fleet ahead, it joins that fleet.

If its arrival time is **greater**, it cannot catch up and forms a new fleet.

---

## ⏱️ Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Sort cars | O(n log n) |
| Traverse cars | O(n) |
| Total Time Complexity | **O(n log n)** |
| Space Complexity | **O(n)** |

---

## 📚 Key Concepts

- Sorting
- Greedy Algorithm
- Monotonic Stack
- Simulation
- Array Traversal

---

## 🔗 Related Problems

- Daily Temperatures
- Next Greater Element
- Largest Rectangle in Histogram
- Asteroid Collision
```


Video Tutorial : https://www.youtube.com/watch?v=TPSiTAFhszA
