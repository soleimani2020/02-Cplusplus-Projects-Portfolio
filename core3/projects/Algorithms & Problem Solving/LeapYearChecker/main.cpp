// write a class called  MyDate and within that checks whether a year is a leap year.
// we get the dat >> check if it is valid ---> check the leap year --> bool
// Show the : day / month / year  21 . 04. 2025
//{"January=31","February=28/29","March=31","May=31","April=30","June==30","July=31","August=31","September=30","October=31","November=30","December=31" }
// 1. If we have a private method in the class, it can only be accessed in the main using a public wraper!
// 2. A private method can be accesssed in the public but only with the scope of the same class.

// Keep asking for another date if the date is unvalid



#include <iostream>
using namespace std;


class MyDate{
    
private:
    // function members ---> attributes  
    int  day;
    int  month;
    int  year;
    
    // Methods : Is_leapyear  | Is_Valid_date | set_data | show_data | isLeapYear

    // Checks if a given year is a leap year: Look at pdf in git for the leap year algorithm.

    bool Is_leapyear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }


    // Checks if the given date is valid
    bool Is_Valid_date(int d, int m, int y) const {
            
        if ( m < 1 ||  m > 12 ){
            return false;
        }


        // Days_months starts with 0, since we want the index of the array match the index of the month of the year.
        int Days_months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        
        // m=2 is Feburary which has either 28 or 29 days !
        if (m==2 && Is_leapyear(y) ){
            Days_months[m]=29; // if it is a leap year , then Feburary has 29 days!
        }
        
        return (d>=1 && d<=Days_months[m]);
      
    }
        

    
    

public:
    // constructor with date validation
    MyDate(int d, int m , int y){
        if (Is_Valid_date(d,m,y)){
            day=d;
            month =m;
            year=y;
        } else {
            day=12;
            month=12;
            year=2012;
        }
            
    }
    

    
    // redundent !
    void set_data(int d,int m,int y){
        if (Is_Valid_date(d,m,y)){
            day=d;
            month =m;
            year=y;
        }else{
            cout << "Invalid date. Data not updated." << endl;
        }
            
    }
    
    
    void show_data(int d,int m,int y){
        if (Is_Valid_date(d,m,y)){
            cout << "Date is: " ;
            
            if (day<10){
                cout << "0" << day << ".";
            }else{
                cout << day << ".";
            }
            
            if (month<10){
                cout << "0" << month<< ".";
            }else{
                cout <<  month<< ".";
            }
            
            if (year){
                cout <<  year<< endl;
            } 

        }else{
            cout << "Invalid date ! We need sth like 12.12.2020 !" << endl;
        }
    }
    
    
    // Public method (wrapper) to check leap year
    bool isLeapYear() const {
        return Is_leapyear(year);
    }


};//class end






int main()
{

    
    int d,m,y;
    cout << "Enter day:"<<endl;
    cin>>d;
    cout << "Enter month:"<<endl;
    cin>>m;
    cout << "Enter year:"<<endl;
    cin>>y;
    
    MyDate newDate(d, m, y);
    newDate.show_data(d, m, y);
    
    cout << endl;

    if (newDate.isLeapYear()) {
        cout << "The year " << y << " IS a leap year!" << endl;
    } else {
        cout << "The year " << y << " IS NOT a leap year!" << endl;
    }

    return 0;


}
