#include <iostream>
using namespace std;

const int size = 10;

class Hash_Set {
private:
    int table[size];       // 10 slots indexed from 0 to 9
    int used_table[size];  // 0 = never used, 1 = occupied, 2 = deleted (tombstone)

    int Hash(int value) {
        return value % size;  // converts to an index between 0 and size-1
    }

public:
    Hash_Set() {
        for (int i = 0; i < size; i++) {
            table[i] = -1;       // empty slots
            used_table[i] = 0;   // never used
        }
    }

    bool insert(int val) {
        int index = Hash(val);
        int first_deleted = -1;  // no deleted slot found yet

        for (int i = 0; i < size; i++) {
            int prob_index = (index + i) % size;

            if (used_table[prob_index] == 0) {
                // never used: best place to insert (unless a tombstone exists)
                int target = (first_deleted != -1) ? first_deleted : prob_index;
                table[target] = val;
                used_table[target] = 1; // occupied
                return true;
            } 
            else if (used_table[prob_index] == 2) {
                // tombstone: remember first one for possible reuse
                if (first_deleted == -1) first_deleted = prob_index;
            } 
            else if (used_table[prob_index] == 1) {
                if (table[prob_index] == val) {
                    // value already present -> do nothing
                    return false;
                }
            }
        }

        // If table had no empty slots but a tombstone exists
        if (first_deleted != -1) {
            table[first_deleted] = val;
            used_table[first_deleted] = 1; // occupied
            return true;
        }

        // Table full
        cout << "Error: Hash table is full, cannot insert " << val << endl;
        return false;
    }

    void remove(int val) {
        int index = Hash(val);

        for (int i = 0; i < size; i++) {
            int prob_index = (index + i) % size;

            if (used_table[prob_index] == 0) {
                // never-used → val not present
                return;
            }

            if (used_table[prob_index] == 1 && table[prob_index] == val) {
                table[prob_index] = -1;
                used_table[prob_index] = 2; // mark as tombstone
                return;
            }
        }
    }

    bool contain(int key) {
        int index = Hash(key);

        for (int i = 0; i < size; i++) {
            int prob_index = (index + i) % size;

            if (used_table[prob_index] == 0) return false; // never-used → key not found
            if (used_table[prob_index] == 1 && table[prob_index] == key) return true;
        }

        return false;
    }

    void display() {
        cout << "Hash table content:\n";
        for (int i = 0; i < size; i++) {
            if (used_table[i] == 0) cout << "[E] ";      // Empty
            else if (used_table[i] == 2) cout << "[T] "; // Tombstone
            else cout << "[" << table[i] << "] ";
        }
        cout << endl;
    }
};

int main() {
    Hash_Set object;

    // Insert values 0 to 9
    for (int j = 0; j < size; j++) {
        object.insert(j);
    }

    object.display();

    // Delete some values
    object.remove(0);
    object.remove(4);
    object.remove(2);
    object.remove(6);
    object.display();

    // Check user input
    cout << "Enter key to search: ";
    int key;
    cin >> key;

    if (object.contain(key)) {
        cout << "The key exists!" << endl;
    } else {
        cout << "The key does NOT exist!" << endl;
    }

    return 0;
}
