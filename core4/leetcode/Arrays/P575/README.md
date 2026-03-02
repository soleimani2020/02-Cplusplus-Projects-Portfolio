# P575: Distribute Candies (EASY)

## Problem Description

Alice has `n` candies, where the `i`th candy is of type `candyType[i]`. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to **only eat n / 2 of the candies she has** (`n` is always even).  

Alice wants to eat the **maximum number of different types of candies** while still following the doctor's advice.

Given an integer array `candyType` of length `n`, return the **maximum number of different types of candies** she can eat if she only eats `n / 2` of them.

---

## Hint

- Alice can take at most `n / 2` candies.  
- She wants to maximize the number of **unique candy types**.  
- Sorting or using a set can help count unique types.  

---

## Example

**Input:**

```text
candyType = [1,1,2,2,3,3]
Ouput:
3
