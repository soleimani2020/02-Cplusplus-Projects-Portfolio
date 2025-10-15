# 🔮 Palindrome Checker in C++

This C++ project implements a **palindrome checker** using a class-based structure.  
A **palindrome** is a word, phrase, or sequence of characters that reads the same **forward and backward** (e.g., `"radar"`, `"madam"`).  

The program asks the user for a string and determines whether it is a palindrome.  

---

## ⚙️ Class Overview

### `Palindrome`
Represents a simple palindrome checker.

**Public Methods:**
- `Check_Palindrome(const std::string& statement)` – Returns `true` if the input string is a palindrome, `false` otherwise  

**Implementation Details:**
- Uses a **for loop with two indices**: one starting from the beginning and one from the end  
- Compares characters moving toward the center  
- Prints a message if a **mismatch** is found  

---

## 🖥️ Example Usage

```cpp
Palindrome object;
std::string input = "radar";

if (object.Check_Palindrome(input)) {
    std::cout << "This is a palindrome" << std::endl;
} else {
    std::cout << "This is not a palindrome" << std::endl;
}
