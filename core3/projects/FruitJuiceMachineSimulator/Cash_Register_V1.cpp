#include <iostream>
using namespace std;

class CashRegister {
private:
    int itemCount;
    float itemCost;

public:
    // Default constructor
    CashRegister() {
        itemCost = 100.0f;
        itemCount = 100;
    }

    // Parameterized constructor
    CashRegister(float costPerItem, int numItems) {
        itemCost = costPerItem;
        itemCount = numItems;
    }

    // Display message based on item availability
    void display() const {
        if (itemCount > 0) {
            cout << "Enjoy!" << endl;
        } else {
            cout << "Item sold out!" << endl;
        }
    }

    // Get the cost of the item
    float getItemCost() const {
        return itemCost;
    }

    // Handle money deposit and purchase process
    void processTransaction() {
        float totalMoney = 0.0f;
        float depositedMoney;

        cout << "Please deposit money: ";

        // Loop until enough money is deposited
        while (totalMoney < itemCost) {
            cin >> depositedMoney;
            totalMoney += depositedMoney;

            if (totalMoney < itemCost) {
                cout << "You need to deposit " << itemCost - totalMoney << " more to buy the item." << endl;
            }
        }

        cout << "Enjoy your drink!" << endl;
        itemCount--;  // Decrease the item count
        cout << "# of items left in the machine: " << itemCount << endl;

        // Calculate and give back change if applicable
        float change = totalMoney - itemCost;
        if (change > 0) {
            cout << "Please take your change: " << change << endl;
        }
        cout << "You can buy another product or press 5 to end shopping!" << endl;
    }
};

int main() {
    CashRegister registerMachine(2.0f, 20);  // Initialize with item cost and number of items

    cout << "Welcome to our little shop!" << endl;
    cout << "Please choose a product:" << endl;
    cout << "1. Apple juice (2$)" << endl;
    cout << "2. Orange juice (2$)" << endl;
    cout << "3. Mango lassi (2$)" << endl;
    cout << "4. Fruit punch (2$)" << endl;
    cout << "5. Exit" << endl;

    int choice;

    // Main loop to handle user input and transactions
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                registerMachine.processTransaction();
                break;
            case 5:
                cout << "Thanks for shopping!" << endl;
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
}
