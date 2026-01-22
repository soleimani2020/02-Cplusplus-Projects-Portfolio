# LeetCode Problem 495: Teemo Attacking (Easy)

## 🧩 Problem Statement

You are given a **list of time points** when Teemo attacks and an integer `duration`.  
Return the **total time that Ashe is poisoned**.  

- When Teemo attacks at time `t`, Ashe is poisoned for `duration` seconds.  
- If Teemo attacks again before the poison ends, the timer **resets** but does not double-count the overlapping time.

---

## 📌 Examples

### Example 1:

**Input:**
timeSeries = [1,4], duration = 2
**Output:**
4

**Explanation:**  
- Ashe is poisoned from time 1 → 3 (2 seconds)  
- Ashe is poisoned from time 4 → 6 (2 seconds)  
- Total poisoned time = 4
