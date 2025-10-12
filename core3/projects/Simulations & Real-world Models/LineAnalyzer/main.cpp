#include <iostream>

using namespace std;

class lineType{

private:
    float a1,b1,c1;
   
// line1 = (a1,b1,c1)
// line2 = (a2,b2,c2)
// a2 =line.a1
// b2 =line.b1
// c2= line.c1



public:
    lineType(float a1,float b1,float c1){
        // this is a pointer to the current instance of the class
        this->a1 = a1; // assigns parameter to member variable!
        this->b1 = b1;
        this->c1 = c1;
    }

    void is_nonvertical()
    {
        if (b1 !=0){
        cout << "a" << a1 << "b" << b1;
        float slope = (-a1)/b1;
        cout << "\nThe ine is nonvertical and the slope is: " << slope << endl;
        }
        else{
        cout << "The line is vertical."<< endl;
        }
   
    }



void is_equal0(lineType line){
   
    if ((a1 * line.b1 == b1 * line.a1) && (a1 * line.c1 == c1 * line.a1)){
        cout << "The two lines are equal" << endl;
    }else{
    cout << "These are not equal lines." << endl;
    }
}


void is_equal(lineType line){
    float k = 12.5;
    if ((a1==line.a1 && b1==line.b1 && c1==line.c1 ) || (a1==k*line.a1 && b1==k*line.b1 && c1==k*line.c1 )){
        cout << "The two lines are equal" << endl;
    }else{
        cout << "The two lines are not equal" << endl;
    }
}



void is_parallel(lineType line){
    float slope1 = (-a1/b1);
    float slope2 = (-line.a1)/line.b1;
    if ((slope1 == slope2) || (b1==0 && line.b1==0))
    {
    cout <<"The two lines are parallel" << endl;
    }else{
        cout <<"The two lines are not paralle !"<< endl;
    }
}




void is_perpendicular(lineType line){
   
    float slope1 = (-a1/b1);
    float slope2 = (-line.a1)/line.b1;
    if ((slope1*slope2==-1) || ((a1==0 && line.b1==0) || (b1==0 && line.a1==0))){
       
        cout << "The two lines are prependicular !" << endl;
    }else{
       
        cout << "The two lines are not prependicular !" << endl;
    }

}



void is_intersection(lineType line){
   
    if (a1*line.b1-line.a1*b1 == 0){
       
        cout << "There is no intersection found !" << endl;
       
    }else{
        float x = (c1*line.b1 - line.c1*b1  )/(a1*line.b1 - line.a1*b1 );
        float y = (a1*line.c1 - line.a1*c1  )/(a1*line.b1 - line.a1*b1);
       
        cout << "The intersection point is X:" << x <<" "<<"Y: " << y << endl;
    }
}



};

int main()
{
   
    cout << "Welcome to our little calculator" << endl;
   
    lineType line1(1,2,3);
    lineType line2(2,-1,5);
    //lineType line3(100,200,300);
   
    line1.is_nonvertical();
    line1.is_equal(line2);
    line1.is_parallel(line2);
    line1.is_perpendicular(line2);
    line1.is_intersection(line2);
   
    cout << "Happy calculaing , see you soon !" << endl;
   

    return 0;

}


// Main point : objects can indeed be passed to functions as arguments
