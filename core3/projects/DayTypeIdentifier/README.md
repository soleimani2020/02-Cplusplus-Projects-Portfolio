# 📅 Day Calculator in C++

This C++ project implements a **day management system** using a `dayType` class. It allows the user to:  
- Set a day of the week ✅  
- Print the current day 🖥️  
- Find the **next** and **previous** day 🔄  
- Calculate a day **n days ahead** 🕒  

The project also demonstrates **cyclical indexing** for weekdays and input validation.  

---

## ⚙️ Class Overview

### `dayType`
Represents a day of the week.

**Features:**
- Stores the current day (`today`)  
- Maintains an array of weekdays (`week[7]`)  
- Provides functions for **day manipulation** and **calculations**  

**Private Function:**
- `Day_index(const string &wanted_day)` – Returns the index of a day (0–6). Returns `-1` if invalid.  

**Public Functions:**
- `Set_day(const string &wanted_day)` – Sets the current day (defaults to Sunday if invalid)  
- `Print_day()` – Prints the current day  
- `Return_next_day()` – Prints the next day  
- `Return_previous_day()` – Prints the previous day  
- `Calculate_day(int day_ahead)` – Returns the day after `day_ahead` days  

---

## 🖥️ Main Program Flow

1. Prompt the user to **enter a day of the week**:
```cpp
cout << "Enter a day of the week (e.g., Monday): ";
string wanted_day;
cin >> wanted_day;
