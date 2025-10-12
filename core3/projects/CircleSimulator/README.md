This C++ programm follows Object-Oriented Programming (OOP) principles, specifically focusing on inheritance and encapsulation to to model points and circles in a smart way.
How Does This Code Work with OOP?
1. Defines a pointType class (Base Class)
   Represents a point on a 2D plane with x and y coordinates.
   Has functions to set, get, and display the coordinates.
2. Creates a circleType class (Derived Class)
   Inherits from pointType, meaning it automatically gets x and y properties.
   Adds a radius and functions to calculate area and circumference.

Why Use Inheritance?
  Instead of writing x and y again in circleType, it reuses them from pointType.
  Saves time and makes the code cleaner and easier to manage.

Encapsulation (Data Protection)
  x, y, and radius are private or protected, meaning they can’t be directly changed from outside the class.
  Instead, the class provides functions to update or access these values safely.




