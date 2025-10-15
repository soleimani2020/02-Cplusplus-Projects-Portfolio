# 📐 Line Calculator in C++

This C++ project implements a **line calculator** using a `lineType` class.  
It allows users to analyze lines in the 2D plane and perform common operations such as:

- Checking if a line is **vertical** or **non-vertical**  
- Calculating the **slope** of a line  
- Checking if two lines are **equal**  
- Checking if two lines are **parallel** or **perpendicular**  
- Finding the **intersection point** of two lines  

---

## ⚙️ Class Overview

### `lineType`
Represents a line in 2D space using the **general form**:


**Private Attributes:**
- `a1` – Coefficient of x  
- `b1` – Coefficient of y  
- `c1` – Constant term  

**Public Methods:**
- `is_nonvertical()` – Checks if the line is vertical and prints its slope  
- `is_equal(lineType line)` – Checks if two lines are equal (exact match or scalar multiple)  
- `is_parallel(lineType line)` – Checks if two lines are parallel  
- `is_perpendicular(lineType line)` – Checks if two lines are perpendicular  
- `is_intersection(lineType line)` – Finds and prints the intersection point of two lines  

---

## 🖥️ Example Usage

```cpp
lineType line1(1, 2, 3);
lineType line2(2, -1, 5);

line1.is_nonvertical();
line1.is_equal(line2);
line1.is_parallel(line2);
line1.is_perpendicular(line2);
line1.is_intersection(line2);
