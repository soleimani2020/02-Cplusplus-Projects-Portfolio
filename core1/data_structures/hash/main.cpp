#include <iostream>
using namespace std;

const int size = 10;

class Hash_Set{
private:
    int  table[size];       // 10 slots indexed from 0 to 9
    int used_table[size];   // 0 = never used, 1 = occupied, 2 = deleted (tombstone)

    int Hash(int value){
        return value % size;  // converts to an index between 0 and size-1
    }

public:
    Hash_Set(){
        for(int i = 0; i < size; i++){
            table[i] = -1;           // empty slots
            used_table[i] = 0;       // never used
        }
    }

    void insert(int val){

        int index = Hash(val);
        int first_deleted = -1;

        // linear probing to find a spot to insert the value
        for(int i = 0; i < size; i++){
            int prob_index = (index + i) % size;

            if (used_table[prob_index] == 0) {
                // never used: best place to insert (unless we saw a deleted slot earlier)
                int target = (first_deleted != -1) ? first_deleted : prob_index;
                table[target] = val;
                used_table[target] = 1; // occupied
                return;
            }
            else if (used_table[prob_index] == 2) {
                // tombstone: remember first one for possible reuse
                if (first_deleted == -1) first_deleted = prob_index;
            }
            else if (used_table[prob_index] == 1) {
                if (table[prob_index] == val) {
                    // value already present -> do nothing
                    return;
                }
                // else continue probing
            }
        }

        // If we reached here, table had no "never used" slots but maybe a tombstone
        if (first_deleted != -1) {
            table[first_deleted] = val;
            used_table[first_deleted] = 1; // occupied
        }
        // else table full -> insertion fails silently (same behavior as before)
    }

    void Deletion(int val){

        int index = Hash(val);

        for(int i = 0; i < size; i++){

            int prob_index = (index + i) % size;

            // If the current slot is marked never-used (0), val is not in the table.
            if (used_table[prob_index] == 0){
                return;
            }

            // If the value is found, mark tombstone (deleted)
            if (used_table[prob_index] == 1 && table[prob_index] == val){
                table[prob_index] = -1;
                used_table[prob_index] = 2; // tombstone
                return;
            }
            // otherwise continue probing (either tombstone or occupied with different value)
        }
    }

    void Display(){
        for(int i = 0; i < size; i++){
            cout << table[i] << " " ;
        }

        cout << endl;
    }

    bool Contain(int key){

        int index = Hash(key);

        for(int i = 0; i < size ; i++){
            int prob_index = (index + i) % size;

            if (used_table[prob_index] == 0){
                return false;  // never used → key not in table
            }

            if (used_table[prob_index] == 1 && table[prob_index] == key){
                return true; // Found the key in the table
            }
            // if tombstone or occupied but different value, continue probing
        }

        return false; // unsuccessful search after checking entire table
    }

}; //

int main()
{

    Hash_Set  object;

    for (int j = 0; j < size; j++){
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
