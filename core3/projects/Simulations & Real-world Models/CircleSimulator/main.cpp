/******************************************************************************                           
// a point on x-y plane 
// show the point
// sett the coordinates 
// return y// return y 
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class pointType{
    
protected:
    float x;
    float y;
    
public:
    pointType(){
        x=0;
        y=0;
    }
    
    pointType(float x_coord,float y_coord){
        x= x_coord;
        y= y_coord;
    }
    
    
    void show_coordinate(){
        cout << "The coordinate X and Y are:"<< "(" << x << "," << y << ")"<< endl;
    }
    
    
    void set_coordinate(float x_coord, float y_coord){
        x= x_coord;
        y= y_coord;
    }
    
    float X_coordinate(){
        return x;
    }
    
    
    float Y_coordinate(){
        return y;
    }    
    
    
    
    
}; // end of the class


class circleType : public pointType{
    
private:
    float radius;
    
public:
    // calling constructor of the base class with arguments a and y. 
    // initialize the member variable radius of circleType with r .
    circleType(float x=0, float y=0, float r=0) : pointType(x,y) , radius(r){}


    
/*
    circleType(float x, float y, float r){
       init(x,y,r);
   
    } 
    
    void init(float x, float y , float r){
        pointType::x=x;
        pointType::y=y;
        radius=r;
    }
    

 */
 
 /*
    circleType(): circleType(0,0,0){}
    circleType(float x, float y):circleType(x,y,0){}
    circleType(float x, floay y, float r):pointType(x,y), radius(r){}
    
 */


    
    
    void set_radius(float r){
        radius =r;
    }
    
    void print_radius(){
        cout << "The radius is :" << radius << endl;
    }   
    
    
    void  area_calculation(){
        
        float area = 3.14*radius*radius ;// X_coordinate()*Y_coordinate() ;
        cout << "The area is:" << area << endl;

    }
    
    void circumf_calculation(){
        float circumft = 2*3.14*radius;
        cout << "The circumfanct is:" << circumft;

    }

}; // end of the derived class 




int main()
{
    pointType point(10,20);
    point.show_coordinate();
    point.set_coordinate(10,20);
    point.X_coordinate();
    point.Y_coordinate();
    
    
    circleType Radius(10,20,12);
    Radius.set_radius(12);
    Radius.print_radius();
    Radius.area_calculation();
    Radius.circumf_calculation();
    


    return 0;
}

/*
Another example fo initializer list :

class RectangleType : public pointType {
private:
    float width;
    float height;

public:
    RectangleType(float x = 0, float y = 0, float w = 0, float h = 0)
        : pointType(x, y), width(w), height(h) {}
};
*/


