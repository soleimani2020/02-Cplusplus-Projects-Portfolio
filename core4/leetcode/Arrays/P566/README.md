# P566: Reshape the Matrix (EASY)

## Problem Description

You are given an `m x n` matrix `mat` and two integers `r` and `c` representing the number of rows and columns of the desired reshaped matrix.  

The reshaped matrix should be filled with all the elements of the original matrix in the **same row-traversing order** as they were.

If the reshape operation with the given parameters is **possible and legal**, output the new reshaped matrix. Otherwise, output the **original matrix**.

---

## Hint

In MATLAB, there is a handy function called `reshape` which can reshape an `m x n` matrix into a new one with a different size `r x c` while keeping its original data.

---

## Topics

- Array  
- Matrix  

---

## Example

**Input:**

```text
mat = [[1,2],[3,4]], r = 1, c = 4
