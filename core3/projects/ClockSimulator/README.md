# ⏰ Clock and Extended Clock Classes in C++

This C++ project implements **clock management** using classes. It defines a basic `clockType` class for standard **GMT time** and an extended `extClockType` class to handle **time zones**.

The project demonstrates:
- Class design using **constructors** and **initializer lists** 🏗️  
- **Inheritance** and **protected members** 🔗  
- **Time manipulation** and formatting ⏱️  
- Safe handling of invalid inputs ✅  

---

## ⚙️ Main Classes

### 1. `clockType`
The base class representing a 24-hour clock.

**Features:**
- Stores hours, minutes, and seconds (`int`)  
- Initializes time to `00:00:00` by default  
- Validates input values for hours (0–23), minutes (0–59), and seconds (0–59)  
- Prints time in **GMT format** with leading zeros  

**Key Functions:**
- `set_time(int hr, int min, int sec)` – Sets and validates time  
- `print_time() const` – Prints time as `HH:MM:SS` in GMT  

---

### 2. `extClockType`
Derived class that adds **time zone functionality** to `clockType`.

**Features:**
- Stores a **time zone offset** (`int`) and a **time zone name** (`string`)  
- Allows time zone adjustment from GMT (`-12` to `12`)  
- Overrides `print_time()` to display **local time**  

**Key Functions:**
- `set_time_zone(int tz, string tzName)` – Sets the time zone and name  
- `get_time_zone()` – Returns the numeric time zone offset  
- `get_time_zone_Name()` – Returns the time zone name  
- `print_time() const` – Prints local time with proper formatting  

---

## 🏗️ Constructors

### `clockType` Constructors:
- Default: Initializes `hours`, `minutes`, `seconds` to 0  
- Parameterized: Initializes time to user-specified values  

### `extClockType` Constructor:
- Uses **initializer list** to call the `clockType` constructor  
- Sets time zone and name using `set_time_zone()`  
- Example:
```cpp
extClockType extObject(4, 3, 12, 10, "GMT+1");
