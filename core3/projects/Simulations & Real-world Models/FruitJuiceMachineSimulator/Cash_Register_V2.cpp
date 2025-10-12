#include <iostream>
#include <iomanip>
#include <map>


using namespace std;

class cashRegister{

private:
    //     #1        <AppleJuice, 2$>
    map< int , pair <string, double>> Menu;
    map< int , int  > Quantity;
    //map < int , pair <string, int > > Quantity;
    //    #1    100
    double cost=0.0;
    int item=0;

    //void Money_inside(float deposited_Money){
    //    cost += deposited_Money;
    //}

public:
    cashRegister(){
    // defalt values
    Menu[1]={"Apple Juice ",2.55};
    Menu[2]={"Orange Juice",3.50};
    Menu[3]={"Mango lassi ",4.50};
    Menu[4]={"Fruit punch ",5.50};
    Quantity[1]=100;
    Quantity[2]=100;
    Quantity[3]=100;
    Quantity[4]=100;
    }

    void display()
    {   
        cout << "Welcome to our little shop!" << endl;
        cout << "Please take a look at our Menu" << endl;
        for (const auto & item : Menu){
            cout << item.first << ":" << item.second.first << "$" << fixed << setprecision(2) << item.second.second << "  Quantity:" << 
            Quantity[item.first] << endl;   
        }
    }



    void purchase(int choice){
        
        
        if (Menu.find(choice)==Menu.end()){
            cout << "Invalid choice !" << endl;
            cout << "Please choose another product or end the shopping !" << endl;
            return ;
        }
        
        
        if (Quantity[choice] == 0){
            cout << "Item is sold out!" << endl;
            cout << "Please choose another product or end the shopping !" << endl;
            return ;
        }
        

        //cout << "The cost of "  << Menu[choice].first << "is $"<<fixed << setprecision(2) << Menu[choice].second << "" << endl;
        
        
        cout << "Please deposit $" << Menu[choice].second << " for your " << fixed << setprecision(2) << Menu[choice].first  <<"."<< endl;

        float total_money =0.0;
        
        while (total_money < Menu[choice].second){
            float deposited_money;
            //cout << "Please deposit $" <<fixed << setprecision(2) << Menu[choice].second   << " for your " << Menu[choice].first <<"."<< endl;
            cin >> deposited_money;
            total_money += deposited_money;
            
            if (total_money < Menu[choice].second){
                cout << "Your money is not enough ! Please deposit $" << Menu[choice].second - total_money << " more: " << endl ;
            }else{
                
                cout << "Thank you for your shopping !" << endl;
                cout << "Please take your change $" << total_money - Menu[choice].second << endl;
                Quantity[choice] -=1;
            }

         }
  
         
    }



};



int main(){
    cashRegister object;
    
    object.display();
    cout << "Please choose your item:" << endl;
    int choice;
    cin >> choice;
    
    object.purchase(choice);
    





/*
int choice;

while (true){
    cin >> choice;
    float deposited_Money;
    switch (choice){
        case 1:
            cout << "Please deposit 2$" << endl;
            cin >> deposited_Money;
            object.money_acceptor(deposited_Money);
            break;
        case 2:
            cout << "Please deposit 2$" << endl;
            cin >> deposited_Money;
            object.money_acceptor(deposited_Money);
            break;
        case 3:
            cout << "Please deposit 2$" << endl;
            cin >> deposited_Money;
            object.money_acceptor(deposited_Money);
            break;
        case 4:
            cout << "Please deposit 2$" << endl;
            cin >> deposited_Money;
            object.money_acceptor(deposited_Money);
            break;
        case 5:
            cout << "Thanks for shopping!" << endl;
            return 0;
        default:
            cout << "This is an invalid choice."  << endl;
    }
}
*/

}
