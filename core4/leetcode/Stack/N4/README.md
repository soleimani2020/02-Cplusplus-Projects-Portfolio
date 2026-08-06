# LeetCode 739: Daily Temperatures (Medium)

## 🧩 Problem Statement

You are given an array of integers `temperatures` where:

```cpp
temperatures[i]

represents the temperature on the i-th day.

Return an array result where:

    result[i] is the number of days you have to wait after day i to get a warmer temperature.

    If there is no future day with a warmer temperature, set result[i] = 0.

Example 1
Input

temperatures = [73,74,75,71,69,72,76,73]

Output

[1,1,4,2,1,1,0,0]
