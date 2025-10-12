#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
   
    Node(int value){
        data = value;
        next = nullptr;
    }
}; // End of class Node


class Queue{
private:
    Node* front;
    Node* rear;

public:
    Queue(){
        front = nullptr;
        rear  = nullptr;
    }
   
   
    bool Is_empty(){
        if (front == nullptr){
            cout << "Ops! the queue is empty!" <<endl;
            return true;
        }else{
            return false;
        }
    }
   
   
   
    void Enqueue(int value){
        Node *new_node = new Node(value); // create a new node 
       
        if (rear==nullptr){
            rear=front=new_node;  // if the queue is empty, we make both rear and front to point  to the new node 
            rear->next = front;
            
        }else{
            rear-> next = new_node;
            rear = new_node;      // we update the rear pointer 
            rear->next = front;
        }
        cout << "Circular Enqueue operation is performed !" << endl;
    }
   
   
   
    int Dqueue(){
       
        int x;
        
        
        if (Is_empty()){
            cout << "Nothing to delete !" << endl;
            return -1;
        }
        
        
        if (front==rear){
            cout << "Sinle Node !" << endl;
            delete front;
            front=rear=nullptr;
            return x;
        }
       

        Node *current = front;
        front = front->next;
        rear->next = front;
        x = current->data;
        cout << "Dqueue operation performed!" << endl;
        delete current;
        return x;

    }
    
    
    void Display(){
        
        if (Is_empty()){
            cout << "Nothing to display !" << endl;
            return;
        }
        
        Node *current =front;
        
        do{
            
            cout << "data:" << current->data;
            current= current->next;
            cout << endl;
            
        }while(current != front);
        
        
    }
    
    
   
   
}; // End of class Queue





int main()
{
    Queue  q;
    
    cout << "Determin the size of the qeue!" << endl;
    int size=5;
    for(int i=1; i <= size ; i++){
        q.Enqueue(i);
    }
    
    
    cout << "Display the queue!" << endl;
    q.Display();
    
    cout << "Determin the how many nodes you want to delete!" << endl;
    int size2=2;
    for(int i=1; i <= size2 ; i++){
        q.Dqueue();
    }
    
    
    //cout << "Display after Dqueue!" << endl;
    //q.Display(); 

    return 0;
}









