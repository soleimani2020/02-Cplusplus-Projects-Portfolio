/******************************************************************************

                              Binary Trees.

*******************************************************************************/

#include <iostream>
using namespace std;

class Node{
    
public:
    int data;
    Node *lchild;   // this points to a node (left to the root)
    Node *rchild;  // this points to a node (right to the root)
    
    Node(int val){
        data=val;
        lchild=rchild=nullptr;
    }
};






