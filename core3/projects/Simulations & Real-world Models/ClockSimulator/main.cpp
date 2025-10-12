// This C++ program defines a class clockType that represents a simple digital clock. 
// It allows setting and displaying time in the format HH:MM:SS.


#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class clockType{
    
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
    
    void print_time(){
        
        cout << "Time is: " ;
        
        if (hours<10){
            cout << "0" << hours << ":";
        }else{
            cout <<  hours << ":";
        }
            
        
        if (minutes<10){
            cout << "0" << minutes<< ":";
        }else{
            cout <<  minutes << ":";
        }
        
        if (seconds<10){
            cout << "0" << seconds<< endl;
        }else{
            cout <<  seconds << ":";
        }      

    }
    
    

        
    
    

}; // End of the class 



int main(){
    
    clockType object;
    object.set_time(1,3,2);
    object.print_time();
    
    
    
    
}






