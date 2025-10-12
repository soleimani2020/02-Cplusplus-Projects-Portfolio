#include <iostream>
using namespace std;

struct Node {
    int data;    // Stores the value of the node
    Node* next;  // Pointer to the next node in the list
    // Constructor to initialize the node with a value and set next to nullptr
    Node(int val) : data(val), next(nullptr) {}
/*
Node* n = new Node(42);

+------+------+
| 42   | null |
+------+------+

*/

};

class Linked_List {
private:
    Node* head;



    // Recursive helper function: counts and sums and etc nodes starting from 'current'

    int Count_recursive_helper(Node* current) {// loop detected
        if (current == nullptr) {
            return 0;
        }
        return 1 + Count_recursive_helper(current->next);
    }
    
    
    int Summation_recursive_helper(Node* current) {
        if (current == nullptr) {
            return 0; // base case: end of list
        }
        return current->data + Summation_recursive_helper(current->next);
    }





    Node* Find_Middle(Node *head){
        
        Node *slow = head;
        Node *fast = head->next;
        
        while(fast !=nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Middle node
        return slow;
        
    }
    
    
    // Merge two sorted lists : A and B are pinters to the first node of the first and second lists.
    Node *Merge_helper(Node *A , Node *B){
        
        if (!A) return B;
        if (!B) return A;
        
        if (A->data <= B->data){
            A->next = Merge_helper(A->next,B);
            return A; // head of the merged list 
        }
        
        else{
            B->next = Merge_helper(A,B->next);
            return B;
        }
        }
        
    
    
    Node *RecursiveMergeSort(Node *head){
        
        if (head ==nullptr ||  head->next == nullptr){
         return head;
        }
        
        
        // Split the LL into two parts
        Node *middle =Find_Middle(head);
        Node *middle_Next =  middle->next;
        middle_Next=nullptr;
        
        Node *leaft = RecursiveMergeSort(head);
        cout << "LEFT:" << leaft << endl;
        
        
        Node *right = RecursiveMergeSort(middle_Next);
        
        return Merge_helper(leaft,right);
        
    }
    
    







public:
    Linked_List() : head(nullptr) {}
    
    
    

    int count() {
        int c = 0;
        // Create a pointer named current that points to the same "node" that head is pointing to.
        Node* current = head;
        // While current is not nullptr
        while (current) {
            c++;
            current = current->next;
        }
        return c;
    }
    
    
    int Count_recursive() {
        return Count_recursive_helper(head);
    }


    

 
    int Summation() {
        int sum = 0;
        Node* current = head;
        while (current) {
            sum += current->data;
            current = current->next;
        }
        return sum;
    }


    int Summation_recursive() {
        return Summation_recursive_helper(head);
    }
    
    


    bool search(int key) {
        Node* current = head;
        // Traverse until the end of the list (current == nullptr)::: head → [10] → [20] → [30] → nullptr
        while (current) { 
            if (current->data == key)  // Found the key
                return true;  
            current = current->next;
        }
        return false; // Key not found in the entire list
    }


    

    bool Im_Lsearch(int key) {
        if (!head) return false;             // List is empty
        if (head->data == key) return true;  // Key already at head of the linked list


        // prev moves always one step behind current
        // Initially : prev on the first and current on the second nodes 
        Node* prev = head;
        Node* current = head->next;

        while (current) {
            if (current->data == key) {
                prev->next = current->next;
                current->next = head;
                head = current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;  // Key not found
    }



    void Insert_first(int x) {
        Node* t = new Node(x);
        t->next = head;
        head = t;
    }

    void Insert_middle(int pos, int x) {
        int len = count();
        if (pos < 0 || pos > len) {
            cout << "Invalid position!\n";
            return;
        }


        // If position is 0, just insert at the beginning.
        if (pos == 0) {
            Insert_first(x);
            return;
        }

        Node* t = new Node(x); // Create new node t with data x
        Node* current = head;
        // If the position is 4, current should move 3 times or equivalently should point to the 3rd node !
        // i=0 : moves current from first node to the second node ! 
        for (int i = 0; i < pos - 1; i++)
            current = current->next;

        t->next = current->next;
        current->next = t;
    }

    void Insert_last(int x) {
        Node* t = new Node(x);
        if (!head) {
            head = t; 
            return;
        }

        Node* current = head;
        // While the next node exists! 
        // head -> [10] -> [20] -> [30] -> nullptr
        // current is 30, next is nullptr → stop.
        while (current->next)
            current = current->next;

        current->next = t;
    }



    void Delete(int x) {
        if (!head) return;

        if (head->data == x) {
            Node* temp = head;  // Temporary pointer temp is needed to "safely" delete the first node without losing access to it.
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;             // points to first node  
        Node* current = head->next;    // points to second node

        while (current) {
            if (current->data == x) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }




    void bubble_Sort() {
        int len = count();
        if (len < 2) return; // If the list has less than 2 nodes, no need to sort.
        
        // (i): how many passes (len-1 passes)
        // (j): compares adjacent nodes up to the last unsorted element.
        // In each pass, the bigesst element is sorted !
        // The largest remaining element "bubbles up" to its correct position.

        for (int i = 0; i < len - 1; i++) {
            Node* current = head;
            for (int j = 0; j < len - i - 1; j++) {
                if (current->data > current->next->data)
                    swap(current->data, current->next->data);
                current = current->next;
            }
        }
    }


    
    
    void sort(){
        head = RecursiveMergeSort(head);
        
    }
    
    
    
    void Remove_duplicate(){
        
        if (!head)return;
        
        Node *current = head;
        // If current->next is nullptr, then I am at the last node and there’s no next node to compare with — so stop.
        while(current && current->next != nullptr){
            if (current->data == current->next->data){
                cout << "DUPLICATE IS FOUND AND REMOVED FROM THE LIST: " << current->next->data << endl;
                Node *temp = current->next;
                current->next = current->next->next; // current->next = temp->next
                delete temp;
            }else{
                // Move to the next node as no deletion occured !
                current = current->next;
            }
        }
    }



    
    void Reverse_Array(){
        
        int *Array;
        int Length = count();
        // C: Array = (int *)malloc(sizeof(int)*Length);
        //C++
        Array = new int[Length];
        
        Node* current = head;
        int i = 0;

        // Copy from LL to array 
        while(current != nullptr){
            Array[i] = current->data;
            current  = current->next;
            i++;
        }
    
        current= head;  // Reset current back to the beginning of the list.
        i--;            // brings i back to the last element of the array.


        // Copy from array to LL 
        while(current != nullptr){
            current->data = Array[i];
            i--;
            current = current->next;
        }
    }



        
        

    void Reverse_pointers(){

        // previous --- current --- next 
        
        Node *previuos = nullptr;
        Node *current  = head;
        
        while(current != nullptr){
            Node *next = current->next;  // dynamically choose next !
            current->next = previuos;    // reverse the link
            // slide three pointers 
            previuos = current;
            current  = next;
        }
        
        // New head is the last node 
        head = previuos;
        
    }
    
    

    void Concate(Linked_List &object){
        
        // If the first list is empty, use the second list.
        if (!head){
            head = object.head;
            return ;
        }
        
        Node *current=head;

        // Stop at last node whose next is null !
        while(current->next != nullptr){
            current= current->next;
        }
        
        // Link last node of first list to head of second list
        current->next = object.head;
    }



    
    

        
        
        
     int Minimum(){
         
         int minimum = head->data;
         Node *current = head->next;
         
         
         while(current != nullptr){
             
             if (current->data < minimum){
                 minimum = current->data;
             }
             
             current=current->next;
         }
         
         return minimum;
     }   
        
        
        
    int Maximum(){
         
         int maximum = head->data;
         Node *current = head->next;
         
         
         while(current != nullptr){
             
             if (current->data > maximum){
                 maximum = current->data;
             }
             
             current=current->next;
         }
         
         return maximum;
     }   


    // If the list contains a loop, slow and fast will eventually meet inside the loop.
    // If no loop exists, fast will reach nullptr.
    int Is_Loop(){
        Node *slow = head;
        Node *fast = head;
    
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;  
            if (slow == fast)  // Pointers meet while traversing the loop
                 return 1;  // loop detected
        }
    
        return 0;  // loop NOT detected
    }
    
                
    void Make_Circular(){
        
        if (head==nullptr)return;
        
        Node *current = head;
        
        while(current->next != nullptr){
            current = current->next;
        }
        
        current->next= head;
    }
        
        
        
        
    int Get_Nth_Node(int n){
        
        Node *current = head;
        
        if (n<0){
            cout << "Invalid index!" <<  endl;
            return -1;
        }
        
        
        if (n==0){
            return current->data;
        }
        
        
        for (int i=0; i < n-1 ; i++){
            current =current->next;
        }


        return  current->data;
        
    }
    
    
    
        
        
    void Display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    } 
        



    void Display_Circular(){
        
        Node *current= head;
        
        do{
            cout << current->data << " ";
            current=current->next;
        }while(current != head);
        
        cout << endl;

    }



    
};// End of the class



int main() {
    Linked_List list;
    Linked_List list2;
    Linked_List list3;

    // Linked list : 4 -> 2 -> 1-> 3
    list.Insert_last(4);
    list.Insert_last(2);
    list.Insert_last(1);
    list.Insert_last(3);
    
    // Circular list: 4 -> 2 -> 1
    list3.Insert_last(4);
    list3.Insert_last(2);
    list3.Insert_last(1);
    list3.Make_Circular();// 1->4
    
    


    cout << "Original:\n"<< endl;
    cout << "number of Nodes counted recursively: " << list.Count_recursive() << endl;
    cout << "Summation of Nodes counted recursively: " << list.Summation_recursive() << endl;

    int Number_of_node;
    Number_of_node=3;
    cout << "Please tell me which node?" << endl;
    //cin >> Number_of_node;
    
    if (Number_of_node < 0){
        
        cout << "Invalid index" << endl;

    }else{
        cout << "Data stored in Node  " << Number_of_node+1 << " is :  " << list.Get_Nth_Node(Number_of_node) << endl;

    }

    
    
    
    cout << "Minimum: " << list. Minimum() << endl;
    cout << "Maximum: " << list. Maximum() << endl;

    cout << "Loop (Linear): " << list. Is_Loop() << endl;
    cout << "Loop (Circular): " << list3. Is_Loop() << endl;

    list.Display() ;
    list3.Display_Circular() ;

    
    list2.Insert_last(6);
    list2.Insert_last(7);
    list2.Insert_last(8);
    list2.Insert_last(9);
    list2.Insert_last(10);
    
    
    
    
    list.Concate(list2);
    cout << "Concatenated list: ";
    list.Display();
    
    
    
    

    cout << "Original list: ";
    list.Display();

    cout << "Number of nodes: " << list.count() << endl;
    cout << "Sum of values: " << list.Summation() << endl;
    
    list.Reverse_Array();
    
    cout << "reversed list: ";
    list.Display();
    


    list.Insert_first(9);
    list.Insert_middle(3, 7);
    list.Insert_last(0);

    cout << "List after insertions: ";
    list.Display();

    list.Delete(3);
    cout << "List after deleting 3: ";
    list.Display();

    list.bubble_Sort();
    cout << "Sorted list: ";
    list.Display();
    
    
    list.Remove_duplicate();
    cout << "Removing duplicates from Sorted list: ";
    list.Display();
    
    

    int key = 5;
    cout << (list.search(key) ? "Found " : "Not found ") << key << endl;
    

    list.Im_Lsearch(2);
    cout << "After improved linear search for 2: ";
    list.Display();

    return 0;
}

