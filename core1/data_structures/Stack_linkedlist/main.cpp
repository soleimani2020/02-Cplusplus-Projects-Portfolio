/******************************************************************************

                              STACK using Linked List!


*******************************************************************************/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};


class STACK_LL{
    
private:
    Node *top;


public:

    STACK_LL(){
        top = nullptr;
    }



    bool Is_Empty(){
        if (top == nullptr)
            return true;
        else
            return false;
    }
    
    
    bool Is_Full(){
        
        Node *t = new Node();
        
        if (t==nullptr)
            return true; // stack full
        delete t;
        return false;
    }
    

    void Push(int value){
        if (Is_Full()){
            cout << "Stack Overflow!" << endl;
            return ;
        }
        
        
        Node *t = new Node();
        t->data = value;
        t->next = top;
        top = t;
        cout << "Pushed " << value << " to the stack !" << endl;
    }
    
    
    
    
    int Pop(){
        if (Is_Empty()){
            cout << "Stack underflow!" << endl;
            return -1 ;  
        }
        
        Node *current = top;
        top = top->next;
        int x = current->data;
        delete current;
        return x;
 
    }
    
    
    int Peek_index(int index){
        
        
        
        if (Is_Empty()){
            cout << "Stack underflow!" << endl;
            return -1 ;  
        }
        
        Node *current = top;
        
        for (int i=0; i<index-1; i++){
            current=current->next;
        }
        
        
        if (current != nullptr){
            return current->data;
        }else{
            cout << "Invalid Index!" << endl;
            return -1;
        }
            
  
    }
    
    
    void Display(){
        
        if (Is_Empty()){
            cout << "Stack underflow!" << endl;
            return ;  
        }
        
        
        
        Node *current = top;
        
        while(current != nullptr){
            cout << current->data << endl;
            current = current->next;
        }

        
    }
    
    
    
    
    
    
};//End of the class 

int main(){
    
    STACK_LL object;
    
    cout << "Choose the stack size!"<< endl;
    int size;
    cin >> size;
    
    for(int i=1; i<=size; i++){
        object.Push(i);
    }

    cout << "The stack is now :" << endl;
    object.Display();
    
    
    object.Pop();
    object.Pop();
    cout << "The stack after pop is now :" << endl;
    object.Display();
    
    
    return 0;
}








