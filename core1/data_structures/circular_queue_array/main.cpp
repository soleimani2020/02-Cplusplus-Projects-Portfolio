/******************************************************************************
                              Circular Queue Using Array!

*******************************************************************************/

#include <iostream>
using namespace std;

class Circular_Qeue{
    
private:
    int size;
    int *Array;
    int rear;  // to insert
    int front; // to delete


public:
    Circular_Qeue(int s){
        
        rear = front = -1;
        size = s;
        Array=new int[size]; 
    }
    
    bool Is_Empty(){
        if (front == -1){
            return true;
        }else{
            return false;
        }
    }


    // [F] [ ] [ ] [ ] [R]
    // [ ] [R] [F] [ ] [ ]
    bool Is_Full(){
        if ((rear+1)%size == front){
            return true;
        }else{
            return false;
        }
    } 
    
    
    
    
    void Enqueue_circ(int value){
        if (Is_Full()){
            cout << "Oppps ! the queue is full !";
            return ;
        }
        
        
        if (Is_Empty()){
            rear = front = 0;  // This is because the first element occupies the first index of the array.
        }else{
            rear = (rear+1)%size;  // (rear + 1) % size ensures circular behavior: when rear reaches the end of the array, it wraps around to index 0.
        } 
        
        Array[rear]=value;
        cout << "Enqueue operation performed!" << endl;

    }
    
    
    
    
    
    void dqueue_circ(){
        
        if (Is_Empty()){
            return;
        }


        // If front equals rear, it means there is only one element in the queue.
        // After deleting it, the queue becomes empty, so both front and rear are reset to -1.
      
        if (front==rear){
            front=rear=-1;
        }else{
            
            front = (front+1)%size;  // (front + 1) % size ensures circular behavior, so after reaching the end of the array, it wraps around to index 0.
            
        }
        
        cout << "dqueue performed!" << endl;
   
    }
    
    
    void Display(){
                
        if (Is_Empty()){
            cout << "OPS! Queue is empty !" << endl;
            return;
        }
        
        int i = front;
        while(true){
            cout << Array[i] << "     " << endl;
            if (i==rear){
                break;
            }
            i=(i+1)%size;
        }
        

    }
    
    
    
    
    
    
    
    
    
}; // End of class 



int main(){
    
    cout << "Determine the array size!"<< endl;
    int size;
    cin >> size;
    Circular_Qeue object(size);
    
    
    for(int i=1; i< size+1; i++){
        object.Enqueue_circ(i);
    }
    

    object.Display();
    
    
    
    
    
}
