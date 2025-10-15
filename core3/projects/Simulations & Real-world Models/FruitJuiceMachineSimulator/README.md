# 🥤 Vending Machine Simulation in C++

This C++ project simulates a **vending machine** for a fruit juice shop. It demonstrates **object-oriented programming** concepts such as **classes, encapsulation, constructors, and member functions**.

The program allows the user to:
- Select from multiple products 🍏🍊🥭🍹  
- Pay for items 💵  
- Dispense products and update inventory 🛒  
- Track cash in the register 💰  

---

## ⚙️ Classes

### 1. `CashRegister`
Represents the cash stored in the vending machine.

**Features:**
- Stores current balance (`cashOnHand`)  
- Accepts deposits from customers  
- Provides balance inquiry  

**Key Functions:**
- `acceptAmount(int amount)` – Add amount to the cash register  
- `getCurrentBalance()` – Returns current cash  

---

### 2. `DispenserType`
Represents a product dispenser.

**Features:**
- Stores **number of items** and **cost**  
- Reduces inventory when a sale is made  

**Key Functions:**
- `getNoOfItems()` – Returns number of items left  
- `getCost()` – Returns price of the item  
- `makeSale()` – Decreases number of items by 1  

---

## 🖥️ Main Program Flow

1. Show product menu:
```cpp
ShowSelection();
