#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class clockType{


// protected: accessible both in base and drived class.  
protected:
    int hours;
    int minutes;
    int seconds;
   

public:

    clockType(){
        hours =0;
        minutes =0;
        seconds =0;
    }

    // This constructor is actually redundant : the three hours, minutes, seconds are initialized with the set_time function in the main 
    clockType(int hr, int min , int sec){
        hours   = hr;
        minutes = min;
        seconds = sec;
    }




    void set_time(int hr, int min , int sec){
       
        if (hr >=0  && hr < 24){
            hours = hr;
        }else{
            hours=0;
        }
       
       
               
        if  (min >=0 && min < 60){
            minutes = min;
        }else{
            minutes=0;
        }
       
       
                       
        if  (sec >=0  && sec < 60){
            seconds = sec;
        }else{
            seconds=0;
        }
       
    }

    void print_time() const {
       
        cout << "GMT Time: " ;
       
        if (hours<10){
            cout << "0" << hours << ":";
        }else{
            cout << hours << ":";
        }
       
        if (minutes<10){
            cout << "0" << minutes<< ":";
        }else{
            cout << minutes<< ":";
        }
       
        if (seconds<10){
            cout << "0" << seconds << endl;
        }else{
            cout <<seconds << endl;
        }      
   
    }

};


class extClockType : public clockType {
private:
    string timeZoneName;
    int timezone; // Time difference from GMT

public:
    extClockType(int hr = 0, int min = 0, int sec = 0, int tz = 0, string tzName = "GMT")
        : clockType(hr, min, sec) {
            set_time_zone(tz,tzName);
        }


/*
public:
    extClockType(int hr = 0, int min = 0, int sec = 0, int tz = 0, string tzName = "GMT")
        : clockType(hr, min, sec), timeZone(tz), timeZoneName(tzName) { }
*/

        

    void set_time_zone(int tz, string tzName) {
        if (tz >= -12 && tz <= 12) {
            timezone = tz;
        } else {
            timezone = 0;
        }
        timeZoneName = tzName;
    }
    
    
    
    int get_time_zone() {
        return timezone;
    }
        
    string get_time_zone_Name() {
        return timeZoneName;
    }
    
    
    void print_time() const {
        int adjHours = (hours + timezone) % 24;
        // 
        if (adjHours < 0) {
            adjHours += 24; // To make sure it remains within 0-23 range
        }

        cout << "Local Time (" << timeZoneName << "): ";
        cout << (adjHours < 10 ? "0" : "") << adjHours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};






int main() {
    clockType object;
    object.set_time(4, 3, 12);
    object.print_time();

    extClockType extObject(4, 3, 12, 10, "GMT+1");
    extObject.print_time();

    return 0;
}



// Example for the constructor using initializer list

/*

#include <stdlib.h>
#include <iostream>
using namespace std;

class Basaclass {
private:
    int value; 
    
public:
    Basaclass(int val):value(val){
        cout << "Here is the base class and the value for the private member is:" << value << endl;
    }

}; // end of the class

class derivedclass : public Basaclass {
    
private:
    int value2;
    int value3;
    
public:
    derivedclass(int value2, int value3):Basaclass(value2){
        
        cout << "Here is the derived class and the value for the first private member is:" << value2 << endl;
        cout << "Here is the derived class and the value for the second private member is:" << value3 << endl;

    }

};// end of the class




int main(){
    
    derivedclass obj(10,20);
    return 0;
  
}

*/



