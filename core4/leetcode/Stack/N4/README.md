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

------
# Daily Temperatures — Algorithm

## Algorithm Steps

1. Create an empty stack to store the **indices** of temperatures.

2. Create an answer array `ans` of the same size as the input, initialized with `0`.

3. Traverse the temperatures from **right to left**.

4. For each index `i`:
   - Let `x = nums[i]`.
   - Remove indices from the stack while their temperature is **less than or equal to** `x`.
   - If the stack is not empty, the top of the stack is the index of the **nearest warmer day**.
   - Calculate the number of days:
     ```cpp
     ans[i] = st.top() - i;
     ```
   - Push the current index `i` onto the stack.

5. Return the `ans` array.

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

## Key Idea

Keep removing the stack top until the top element is strictly larger than the current element.


Video Tutorial : https://www.youtube.com/watch?v=ekFs9Nb2RNQ&t=613s
