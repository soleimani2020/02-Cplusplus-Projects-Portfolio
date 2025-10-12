/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

class cashRegister{

    public:

        int getcurrentBalance() const;
        // Function to show the current amount in the cash register.
        // The const keyword ensures this function does not modify the object.

        void acceptAmount(int amountIn);
        // Function to receive the amount deposited by the customer and update the amount in the register.
        //cashOnHand += amountIn;

        cashRegister();
        //Default constructor
        // Can not be zero as the machine might need to give back change to the customer
            cashOnHand=500;

        cashRegister(int CashIn);
        //Constructor with a parameter.
        // cashOnHand = CashIn
            if (CashIn >= 0 )
                cashOnHand = CashIn;
            else
                cashOnHand=500;

    private:
        // It is private to ensure that only the CashRegister class can modify or access it directly,
        // thereby enforcing encapsulation.
        int cashOnHand; // the amunt stored in the register

};



int CashRegister::getcurrentBalance() const
{
    return cashOnHand;
}


void CashRegister::acceptAmount(int amountIn){
    cashOnHand += amountIn;
}



CashRegister::CashRegister(){
    cashOnHand = 500;
}


CashRegister::CashRegister(int CashIn)
{
    if (CashIn >= 0 )
        cashOnHand = CashIn;
    else
        cashOnHand=500;

}



class dispenserType{

    public:

        int getNoOfItems() const;
        // Function to show the number of items in the machine
        // return price of the items

        int getCost() const;
        // Function to show the cost of the item.
        // return cost of the items

        void makesSale();
        // Function to reduce the number of items by 1

        dispenserType();
        // numberofitems =100
        // cost =100

        dispenserType(int setNoOfItems, int setCost)
        // numberofitems = setNoOfItems
        // cost = setCost



    private:

        int numberofitems;
        int cost;

}


int dispenserType::getNoOfItems() const
{

    return numberofitems;

}



int dispenserType::getCost() const
{
    return cost;
}


void dispenserType::makesSale()
{
    if (numberofitems > 0)
    {
        numberofitems-=1;
    }

}


dispenserType::dispenserType(){
    numberofitems=50;
    cost=500;

}


dispenserType::dispenserType(int setNoOfItems, int setCost  ){

    if (setNoOfItems>=0)
        numberofitems = setNoOfItems;
    else
        setNoOfItems=50;

    if (setCost>=0)
        cost = setCost;
    else
        cost=50;

}




void ShowSelection(){

    cout << "*** Welcome to Shelly's Fruit Juice Shop ***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for apple juice" << endl;
    cout << "2 for orange juice" << endl;
    cout << "3 for mango lassi" << endl;
    cout << "4 for fruit punch" << endl;
    cout << "9 to exit" << endl;


}





void sellProduct (CashRegister& product , dispenserType& pCounter){

    int amount;  // variable to hold the amount entered
    int amount2; // variable to hold the extra amount needed

    // If the dispenser is not empty
    // a. Show and prompt the customer to enter the cost of the item.

    if (product.getNoOfItems() > 0 )
    {
        cout << "Please pay" << product.getCost() << "cents" << end;
        cin >> amount;

        // If the amount entered by the customer is less than the cost of the product,
        if (amount < product.getCost()){
            cout << "You need to add " << product.getCost()-amount << "cents" << endl;
            cin >> amount2;
            // total amount entered by the customer.
            amount += amount2;
        }

        if (amount >= product.getCost()){

            product.acceptAmount(amount);
            pCounter.makesSale();
            cout << " Enjoy !" << endl;
        }

        else {

            cout << " The money u paid is not enough !" << end;
            cout << "Collect what you deposited." << endl;

        }
        else {

            cout << "The item is not available anymore !" << endl;
        }



    } // end of sellProduct



int main(){


    cashRegister counter;

    dispenserType appleJuice(100,50);
    dispenserType orangeJuice(100,65);
    dispenserType mangoLassi(75,45);
    dispenserType fruitPunch(100,85);


    //ShowSelection();
    int choice;



    do {
        ShowSelection();
        cin >> choice;

        switch (choice)
        {
            case 1:
                sellProduct(appleJuice,counter);
                break;

            case 2:
                sellProduct(orangeJuice,counter);
                break;

            case 3:
                sellProduct(mangoLassi,counter);
                break;

            case 4:
                sellProduct(fruitPunch,counter);
                break;

            case 9:
                cout << "Thanks for buying !" << endl;
                break;

            default:
                cout << "Invalid selection." << endl;



        }




    }while(choice != 9)

    return 0;






}// end of main




}
























