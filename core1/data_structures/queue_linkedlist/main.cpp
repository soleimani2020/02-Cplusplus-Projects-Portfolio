/******************************************************************************

                             Queue using linked list.


*******************************************************************************/

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
        Node *new_node = new Node(value);  // Creates a new node with the given value
       
        if (rear==nullptr){
            rear=front=new_node;  // If the queue is empty (rear == nullptr), both front and rear point to the new node.
        }else{
            rear-> next = new_node;
            rear = new_node;  // Then rear is updated to point to this new node
        }
        cout << "Enqueue operation is performed !" << endl;
    }
   
   
   
    int Dqueue(){
       
        int x;
       
        if (Is_empty()){
            cout << "Nothing to delete !" << endl;
            return -1;
        }
       
       
        Node *current = front;
        front = front->next;
        x = current->data;

        // If queue becomes empty after deletion, update rear to nullptr
        if (front == nullptr){
            rear = nullptr;
        }

      
        cout << "Dqueue operation performed!" << endl;
        delete current;
        return x;

    }
    
    void display(){
        
        Node *current=front;
        
        while(current){
            cout << current->data;
            current= current->next;
            cout << endl;
        }

        
        
    }
   
   
}; // End of class Queue





int main()
{
    Queue q;
    
    
    
    cout << "Determine the size of the queue?" << endl;
    int size=5;
    for(int i=0; i< size; i++){
        q.Enqueue(i);
    }
    
    
    cout << "Displaying the link list: " << endl;
    q.display();
    
    
    
    q.Dqueue();
    q.Dqueue();
    q.Dqueue();
    cout << "Displaying the link list after Dqueue operation: " << endl;
    q.display();
    
    

    return 0;
}











