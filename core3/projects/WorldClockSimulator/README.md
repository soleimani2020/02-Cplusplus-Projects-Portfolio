This C++ program defines a world clock system with support for time zones using object oriented design in C++. It consists of two classes:
1. clockType – A base class representing a standard 24-hour clock.
2. extClockType is a derived class that extends the clockType class by incorporating time zone functionality. Specifically, it adds the ability to store and manage the time zone name and the time zone difference. For instance, if the GMT time is 04:00:00 in America, the local time in Canada (with a GMT+1 time zone) will be 05:00:00.

   
