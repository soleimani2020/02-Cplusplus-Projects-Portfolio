/******************************************************************************

                              STACK!


*******************************************************************************/

#include <iostream>
using namespace std;

/*

struct STACK{
    
    int size;
    int top;
    int *s;
}
*/


class STACK{
    
private:
    int size;
    int top;
    int* S;    // Pointer to dynamically allocate an array in heap for stack elements

    
public:
    

    STACK(int mysize){
        top   =-1;
        size  = mysize;
        S = new int[size]; // heap allocates the block starting at address eg. 0x1000 and Now, S points to the beginning of that memory block  0x1000.
        
    }
    
    
    bool Is_Empty(){
        if (top ==-1)
            return true;
        else
            return false;
        
    }
        
    bool Is_Full(){
        if (top == size-1)
            return true;
        else
            return false;    
    }
        
        
    void Push(int x) {
        if (Is_Full()) {
            cout << "Stack is full! Cannot push " << x << "." << endl;
            return;
        }
    
        S[++top] = x;
        cout << "Value " << x << " was pushed onto the stack!" << endl;
    }
    
    
    void Pop(){
        
        if (Is_Empty()){
            cout << "Stack is empty ! Nothing to delete !" << endl;
            return;
        }
        
        
        cout << "The value being deleted from stack: " << S[top] << endl;
        top--;

    }
    
    
    
    int Peek(int index){
        
        if (Is_Empty()){
            cout << "Stack is empty ! Nothing to Peek !" << endl;
            return -1;
        }
        
        return S[index];
    }
    

    void Display(){
        for (int i=top; i >=0; i-- ){
            cout << S[i] << endl;
        }
    }
          
    
    
};// End of CLASS



int main(){
    
   int array_size;
   cout << "What is the size of array?" << endl;
   cin >> array_size;

   STACK object(array_size);
   
   object.Push(1);
   object.Push(2);
   object.Push(3);
   object.Push(4);
   
   
   cout << "\nStack is:" << endl;
   object.Display();
   
   cout << "\n\n";
   
   object.Pop();
   object.Display();
   
   cout << "What index do you want to choose?" << endl;
   int index;
   cin >> index;
   cout << "Index " << index << " has value :"<< object.Peek(index) << endl;
   
   
   
   
   
   
   

    
    
}
