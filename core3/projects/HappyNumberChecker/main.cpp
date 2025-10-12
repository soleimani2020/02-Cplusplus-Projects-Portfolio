/******************************************************************************

                              Happy Number !


*******************************************************************************/

#include <iostream>
using namespace std;


class HappyNumberChecker{

    public:
        // constructor
        HappyNumberChecker(int num) : number(num) {}

        // Function to determine if the number is happy
        bool isHappyNumber(){
            int slow = number, fast = number;
            // Use Floyd's Tortoise and Hare algorithm to detect cycles

            do{
                slow = sumOfSquaresOfDigits(slow);
                fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));

            }while(fast != slow); // continuation condition 

            // If pointers meet at 1, it's a happy number
            // The loop continues until slow == fast
            // (i) slow==fast --> both are 1 ---> Happy number 
            // (ii) slow==fast ---> both are not 1 ---> sad number 

            return (slow ==1);
        }

    private:

        int number;
        int sumOfSquaresOfDigits(int num){
            int sum=0;
            while(num !=0){
                int digit = num %10;
                sum+= digit*digit;
                num = num /10;

            }

            return sum;
        }
};

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Create an instance of the HappyNumberChecker class
     HappyNumberChecker checker(num);

    // Check if the number is happy
    if (checker.isHappyNumber()) {
        cout << num << " is a Happy Number!" << endl;
    } else {
        cout << num << " is a Sad Number!" << endl;
    }

    return 0;
}










