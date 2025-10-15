# 🏛️ Roman Numeral Converter in C++

This C++ project implements a **Roman numeral to decimal converter** using a class-based approach.  

It takes a Roman numeral as input and outputs the corresponding decimal value.  

---

## ⚙️ Class Overview

### `romanType`
Represents a Roman numeral and handles conversion to decimal.

**Private Attributes:**
- `roman` – Stores the Roman numeral string  
- `decimal` – Stores the converted decimal value  

**Public Methods:**
- `getromannumber(string r)` – Sets the Roman numeral  
- `convert_roman_to_decimal()` – Converts the Roman numeral to decimal  
- `show_roman()` – Prints the Roman numeral  
- `show_decimal()` – Prints the decimal value  

**Implementation Details:**
- Uses an **unordered_map** to map Roman characters to their integer values  
- Handles the **subtractive notation** (e.g., `IV = 4`, `IX = 9`)  
- Iterates through the string and adds or subtracts values based on Roman numeral rules  

---

## 🖥️ Example Usage

```cpp
romanType object;
object.getromannumber("MCMXCIV");
object.convert_roman_to_decimal();
object.show_roman();    // Output: MCMXCIV
object.show_decimal();  // Output: 1994
