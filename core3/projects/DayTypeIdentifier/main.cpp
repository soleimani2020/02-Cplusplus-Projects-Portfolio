// 1st: a function (Set_date) to check if the data is valid --> Boolian
// 2nd: Add a function member, isLeapYear, to check whether a year is a leap year.
// Weekdays Are Cyclical : Monday → Tuesday → ... → Sunday → back to Monday 
// So the index goes: 0 → 1 → ... → 6 → back to 0
// EX: (6 + 1) % 7 = 7 % 7 = 0  → Monday
// prev_index = (0 - 1 + 7) % 7 = 6 % 7 = 6 → Sunday ✅


#include <iostream>
#include <string>

using namespace std;


class dayType{
private:
    string today;
    string week[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};


    // Private function to get index of a given day
    int Day_index(const string  &wanted_day){

        for (int i=0 ; i< 7; i++){
            if (week[i]==wanted_day){
                return i;
            }
        }
        return -1;// Return -1 if the day is invalid
    }





public:
    // Constructor initializes today to Sunday by default
    dayType(){
        today = "Sunday";

    }

    void Set_day(const string &wanted_day);
    void Print_day();
    void Return_next_day();
    void Return_previous_day();
    string Calculate_day(int day_ahead);

};//end of the class



// Function to set the current day
void dayType::Set_day(const string &wanted_day){
    if (Day_index(wanted_day)!=-1){
        today= wanted_day;
    }else{

        cout << "Invalid day! Defaulting to Sunday." << endl;
        today = "Sunday";
    }
}


// Function to print the current day
void dayType::Print_day(){
    cout << "Current day is "<< today << endl;
}


// Function to print the next day
void dayType::Return_next_day(){

    int Today_index = Day_index(today);
    int NextDay_index = (Today_index+1) % 7; // Wrap around using modulo
    cout << "The next day is: " << week[NextDay_index] << endl;

}


// Function to print the previous day
void dayType::Return_previous_day(){
    int today_index = Day_index(today);
    int prev_index = (today_index-1+7) % 7; // Wrap around for negative indices
    cout << "The previous day is: " << week[prev_index] << endl;
}



// Function to calculate a future day
string dayType::Calculate_day(int day_ahead){
    int Today_index = Day_index(today);
    int future_index= (Today_index + day_ahead) % 7;
    return week[future_index];

}





// Main function
int main()
{
    cout << "Enter a day of the week (e.g., Monday): ";
    string wanted_day;
    cin >> wanted_day;

    cout << "Enter the number of days ahead to calculate: ";
    int day_ahead;
    cin >> day_ahead;


    // Create an object and set the day
    dayType object;
    object.Set_day(wanted_day);
    object.Print_day();
    object.Return_next_day();
    object.Return_previous_day();


    // Display future day
    cout << "The day " << day_ahead << " days ahead will be: " << object.Calculate_day(day_ahead) << endl;

    return 0;


}











