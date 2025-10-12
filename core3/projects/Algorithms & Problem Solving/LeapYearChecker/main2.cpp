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


    MyDate(){
            day=12;
            month =12;
            year=2012;
    }




    // constructor with date validation
    MyDate(int d, int m , int y){
        
        //cout << "param constructor:"<< endl;
        if (Is_Valid_date(d,m,y)){
            day=d;
            month =m;
            year=y;
        } else {
            cout << " The date is not valid, Please choose a valid data and return to us! " << endl;
        }
            
    }
    

    void set_data(int d,int m,int y){
        if (Is_Valid_date(d,m,y)){
            day=d;
            month =m;
            year=y;
        }else{
            cout << " The date is not valid, Please choose a valid data and return to us! " << endl;
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
    void Check_LeapYear() const{
        cout << " is this a leap year ?!" << (Is_leapyear(year)?" yes! ":"no !") << endl;
    }


};//class end






int main()
{
    while(true){
    
        int d,m,y;
        cout << "Enter day:"<<endl;
        cin>>d;
        cout << "Enter month:"<<endl;
        cin>>m;
        cout << "Enter year:"<<endl;
        cin>>y;
        
        

        MyDate newDate;
        
        
        
        newDate.set_data(d, m, y);
        
        if (d>0 && m>0 && y>0){
            
            newDate = MyDate(d,m,y);
            newDate.show_data(d, m, y);
            newDate.Check_LeapYear();
 
        }
        
        cout << "Gibt es noch einen Wunsch?!(Y/N)" << endl;
        
        char choice;
        
        cin >> choice;
        
        if (choice == 'N' || choice =='n' || choice != 'Y' || choice != 'y'){
            cout << "Wir wünschen euch einen schönen Tag" << endl;
            break;
        }
        
        
        

        
        
        
        
    }       
        
        
        
    cout << "Das ist das Ende des Programms!" << endl;
    return 0;
        
        
    
    

    return 0;


}
