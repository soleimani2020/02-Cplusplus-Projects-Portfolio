# 🕒 Clock and Extended Clock in C++

This C++ project demonstrates a **basic clock (`clockType`)** and an **extended clock (`extClockType`)** with support for time zones. The project illustrates **inheritance**, **constructor initializer lists**, and **time formatting**.

---

## ⚙️ Class Overview

### `clockType`
Represents a basic 24-hour clock.

**Protected Attributes:**
- `hours` – Current hour (0–23)  
- `minutes` – Current minute (0–59)  
- `seconds` – Current second (0–59)  

**Public Methods:**
- `set_time(int hr, int min, int sec)` – Sets the clock time with validation  
- `print_time()` – Prints time in **GMT format (HH:MM:SS)**  

---

### `extClockType : public clockType`
Represents a clock with **time zone adjustment**.

**Private Attributes:**
- `timeZoneName` – Name of the time zone (e.g., `"GMT+1"`)  
- `timezone` – Offset from GMT in hours (-12 to +12)  

**Public Methods:**
- `set_time_zone(int tz, string tzName)` – Sets the time zone  
- `get_time_zone()` – Returns the time zone offset  
- `get_time_zone_Name()` – Returns the time zone name  
- `print_time()` – Prints **local time** adjusted by the time zone  

---

## 🖥️ Example Usage

```cpp
clockType object;
object.set_time(4, 3, 12);
object.print_time(); // GMT Time: 04:03:12

extClockType extObject(4, 3, 12, 10, "GMT+10");
extObject.print_time(); // Local Time (GMT+10): 14:03:12
