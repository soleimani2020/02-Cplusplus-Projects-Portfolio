/******************************************************************************

                              Bit manipulation !


*******************************************************************************/

#include <iostream>
using namespace std;

class BitManipulator {
private:
    int number;

public:
    BitManipulator(int num) : number(num) {}

    void setBit(int k) {
        number = number | (1 << k);
    }

    void clearBit(int k) {
        number = number & ~(1 << k);
    }

    void toggleBit(int k) {
        number = number ^ (1 << k);
    }

    bool isBitSet(int k) {
        return number & (1 << k);
    }

    void printNumber() {
        cout << "Current number: " << number << endl;
    }
};

int main() {
    BitManipulator bm(5);

    bm.printNumber();

    bm.setBit(1);
    bm.printNumber();

    bm.clearBit(2);
    bm.printNumber();

    bm.toggleBit(0);
    bm.printNumber();

    cout << "Is 2nd bit set? " << (bm.isBitSet(1) ? "Yes" : "No") << endl;

    return 0;
}







