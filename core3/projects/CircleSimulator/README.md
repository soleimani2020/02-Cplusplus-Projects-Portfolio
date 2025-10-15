# ⭕ Point and Circle Classes in C++

This C++ project demonstrates **object-oriented programming** with **base and derived classes**. It defines a `pointType` class to represent a point on the **x-y plane**, and a `circleType` class derived from `pointType` to represent a **circle** with a radius.  

The project highlights:
- Class design with **constructors** and **initializer lists** 🏗️  
- **Inheritance** and **protected members** 🔗  
- Basic geometric calculations like **area** and **circumference** ⏱️  
- Encapsulation and member access methods ✅  

---

## ⚙️ Main Classes

### 1. `pointType`
The base class representing a point in 2D space.

**Features:**
- Stores coordinates `x` and `y` (`float`)  
- Initializes coordinates to `(0,0)` by default  
- Provides methods to **set**, **show**, and **access** coordinates  

**Key Functions:**
- `set_coordinate(float x_coord, float y_coord)` – Sets the point’s coordinates  
- `show_coordinate()` – Prints coordinates as `(x, y)`  
- `X_coordinate()` – Returns `x` value  
- `Y_coordinate()` – Returns `y` value  

---

### 2. `circleType`
Derived class representing a circle, inheriting from `pointType`.

**Features:**
- Adds a **radius** property (`float`)  
- Supports **default and parameterized initialization** using **initializer lists**  
- Performs basic geometric calculations  

**Key Functions:**
- `set_radius(float r)` – Sets the radius  
- `print_radius()` – Prints the radius  
- `area_calculation()` – Calculates and prints the area using \( \pi r^2 \)  
- `circumf_calculation()` – Calculates and prints the circumference using \( 2 \pi r \)  

**Constructor Example Using Initializer List:**
```cpp
circleType(float x=0, float y=0, float r=0) : pointType(x, y), radius(r) {}
