/******************************************************************************
                              Queue Using Array!

*******************************************************************************/

#include <iostream>
using namespace std;


class Queue_Array{
    
private:
    int head;
    int rear;
    int size;
    int *Array;
    
    
public:
    // Constructor
    Queue_Array(int My_Size){
        head = rear = -1;
        size = My_Size;
        Array = new int[size];
    }
    
    // Destructor
    ~Queue_Array(){
        delete[] Array;
    }
           
    
    bool Is_Empty(){
        if (head==-1 || head > rear){
            cout << "Queue is Empty!" << endl;
            return true;
    }else{
        return false;
        
    }
    }
    
    
       
        
    bool Is_Full(){return (rear==size-1); }// Queue is Full!

             
    
    void Enqueue(int value){
        if (Is_Full()){
            cout << "Sorry ! Queue is Full !" << endl;
            return;
        }
        
        
        if (head ==-1){
            head=0;
        }
        
        rear++;
        Array[rear]=value;
    }
    
    
  int Dequeue() {
      if (Is_Empty()) {
          cout << "Sorry ! Nothing to delete" << endl;
          return -1;
      }
  
      int x = Array[head];  // get the element at front
      if (head == rear) {
          // Queue becomes empty after removing the last element
          head = rear = -1;
      } else {
          head++;           // move head to next element
      }
      return x;
  }

    
    
    void Dispaly_Queue(){
        
        for (int i=head; i<= rear; i++){
            cout << Array[i] << " ";
        }
        
        cout << endl;
        
        
        
    }
    
    
      
    
};// End of the class 


int main(){
    
    cout << "Array Size?!" << endl;
    int size;
    cin >> size;
    Queue_Array object(size);
    
    
    for(int i=0; i< size; i++){
        object.Enqueue(i);
        
    }
    
    cout << "Array After Enqueue Operation!" << endl;
    object.Dispaly_Queue();
    
    object.Dequeue();
    cout << "Array After Dequeue Operation!" << endl;
    object.Dispaly_Queue();

    
    return 0;
}




