# 📅 MyDate Class in C++

This C++ project implements a `MyDate` class for **date management**.  
It validates user input for day, month, and year, and checks whether a year is a **leap year**.  

The program repeatedly asks for a valid date and shows:  
- Date in `DD.MM.YYYY` format  
- Whether the year is a leap year  
- Keeps prompting until the user decides to exit  

---

## ⚙️ Class Overview

### `MyDate`
Represents a calendar date.

**Private Attributes:**
- `day` – Day of the month  
- `month` – Month of the year  
- `year` – Year  

**Private Methods:**
- `Is_leapyear(int y)` – Returns `true` if the year is a leap year  
- `Is_Valid_date(int d, int m, int y)` – Returns `true` if the date is valid  

**Public Methods:**
- `MyDate()` – Default constructor initializes date to `12.12.2012`  
- `MyDate(int d, int m, int y)` – Constructor with validation  
- `set_data(int d, int m, int y)` – Sets the date if valid  
- `show_data(int d, int m, int y)` – Prints the date in `DD.MM.YYYY` format  
- `Check_LeapYear()` – Wrapper method to check if the current year is a leap year  

---

## 🖥️ Example Usage

```cpp
MyDate date1(21, 4, 2025);
date1.show_data(21, 4, 2025);
date1.Check_LeapYear();
