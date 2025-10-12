/******************************************************************************

Design the class largeIntegers so that an object of this class can store an integer up to 100 digits long.

Overload the operators + and – to add and subtract, respectively, the values of two objects of this class.

*******************************************************************************/

#include <iostream>
using namespace std;

class largeIntegers{
    
private:
    static const int MAX_SIZE = 100;  // Fixed size for 100-digit numbers
    char Array[MAX_SIZE];  // Stores the large number
    char Array_Reversed[MAX_SIZE];  // Stores reversed representation

public: 

    // Default Constructor - Initializes to zero
    largeIntegers() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Array[i] = '0';
            Array_Reversed[i] = '0';
        }
    }
    
    
    // Constructor to initialize from a string
    largeIntegers(const string& input) {
        int length = input.length();
        
        if (length > MAX_SIZE) {
            cout << "Error: Input exceeds 100 digits!" << endl;
            exit(1);
        }


        // Important to memorise
        for (int i = 0; i < length; i++) {
            // Store the number in Array as right-aligned
            Array[MAX_SIZE - length + i] = input[i];
            // Store reversed order
            Array_Reversed[i] = input[length - i - 1];  
        }
    }
    
    void digit_print(){
        for (int i=0 ; i < MAX_SIZE; i++ ){
            cout << Array[i];
        }
    }
    
    
    
    void digit_print_Reversed(){
        cout << endl;
        for (int i=0 ; i < MAX_SIZE; i++ ){
            cout << Array_Reversed[i];
        }
        
        
    }
    
    largeIntegers operator+(const largeIntegers& obj) const {
        largeIntegers result;  // To store the sum
        int carry = 0;

        // Start at the rightmost digit (highest index in the array) for addition operation
        for (int i = MAX_SIZE - 1; i >= 0; i--) {
            int sum = (Array[i] - '0') + (obj.Array[i] - '0') + carry; // add the two digits from previous step
            result.Array[i] = (sum % 10) + '0'; // Store last digit of sum in the result array 
            carry = sum / 10; // Update carry for the next generation 
        }
        return result;
    }



    largeIntegers operator-(const largeIntegers& obj) const{
        largeIntegers result;
        int borrow=0;
        for(int i=MAX_SIZE - 1; i >=0; i--){
            int diff = (Array[i]-'0')-(obj.Array[i]-'0') - borrow;
            if (diff<0){
                diff += 10;
                borrow=1;
                
            }else{
                borrow=0;
            }
            result.Array[i] = diff + '0';
        }
        
        return result;
    }


    

    

    
};//the class end 



int main() {
    largeIntegers object1;  // Default constructor (should print 0)
    //object1.print();

    largeIntegers object2("9876543210123456789");
    object2.digit_print();
    object2.digit_print_Reversed();
    
    
    largeIntegers obj1("123456789") , obj2("987654321");
    
    largeIntegers sum = obj1 + obj2 ; 
    //sum.print();
    
    
    
    
    

    return 0;
}
