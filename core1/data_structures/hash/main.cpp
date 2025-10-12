#include <iostream>
using namespace std;



const int size = 10;

class Hash_Set{
private:
    int  table[size];  
    bool used_table[size];

    int Hash(int value){
        return value%size;  // converts to index 
    }
   
public:
    Hash_Set(){
        for(int i=0; i<size;i++){
            table[i]=-1;
            used_table[i]=false;
        }
    }
   
    void insert(int val){
       
        int index = Hash(val);

        // This loop attempts to find a spot to insert the value.
        for(int i=0;i<size;i++){
            int prob_index = (index+i)%size;
            if (used_table[prob_index]==false || table[prob_index]==val){
                used_table[prob_index]=true;
                table[prob_index]=val;
                return;  
            }
        }
    }
   
   
    void Deletion(int val){
       
        int index = Hash(val);
       
        for(int i=0; i< size; i++){
           
            int prob_index = (index+i)%size;

            // If the current slot is marked unused (false), it means val is not in the table.
            if(used_table[prob_index]==false){
                return;
            }


            // If the value is found, delete it.
            if(table[prob_index]==val){
                table[prob_index]=-1;
                used_table[prob_index]=false;
                return;
            }
        }
    }
   
   
    void Display(){
        for(int i=0; i < size; i++){
            cout << table[i] << " " ;
        }
       
        cout << endl;
    }
   
   
   
    bool Contain(int key){
        
        int index = Hash(key);
        
        for(int i=0; i<size ; i++){
            int prob_index = (index+i)%size;
            if (used_table[prob_index]==false){
                return false;  // Slot unused → key not in table
            }
            
            if (table[prob_index]==key){
                return true; // Found the key in the table
            }
        }
        
        
        return false; // unseccusful search . Key not found after checking entire table
        
    }
    
    
   
   
}; //






int main()
{
   
    Hash_Set  object;
   
    for (int j=0; j < size; j++){
        object.insert(j);
    }
   
   
    object.Display();
   
    object.Deletion(0);
    object.Deletion(4);
    object.Deletion(2);
    object.Deletion(6);
    object.Display();
    
    cout << "What is the key?!" << endl;
    int key;
    cin >> key;
    if (object.Contain(key)){
        
        cout << "The key exists!" << endl;
    }else{
        
        cout << "The key does NOT exist!" << endl;
    }
    
    
    
    
    
    
    
    

}
