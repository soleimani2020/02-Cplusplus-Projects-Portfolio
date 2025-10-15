# 🧮 Large Integers Class in C++

This C++ project implements a `largeIntegers` class that can handle integers up to **100 digits long**.  
It supports **addition (+)** and **subtraction (-)** of large numbers using **operator overloading**.  

---

## ⚙️ Class Overview

### `largeIntegers`
Represents a large integer up to 100 digits.

**Features:**
- Stores digits in a fixed-size array (`Array`)  
- Stores digits in **reversed order** for convenience (`Array_Reversed`)  
- Default constructor initializes the number to `0`  
- Constructor from a string supports numbers up to 100 digits  
- Overloaded operators `+` and `-` for addition and subtraction  

**Key Functions:**
- `digit_print()` – Prints the number normally  
- `digit_print_Reversed()` – Prints the number in reversed order  
- `operator+` – Adds two `largeIntegers` objects  
- `operator-` – Subtracts two `largeIntegers` objects  

---

## 🖥️ Example Usage

### Initialize Large Integers
```cpp
largeIntegers obj1("123456789");
largeIntegers obj2("987654321");
