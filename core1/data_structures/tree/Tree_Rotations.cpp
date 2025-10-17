/******************************************************************************

                          Rotations in AVL Trees.

*******************************************************************************/
#include <iostream>
using namespace std;

class Node{
public:
int data;
int hight;
Node *right;
Node *left;

Node(int value){
    hight=1;
    data=value;
    right=left=nullptr;
}

};

class AVLTREE{
public:
Node *root;
AVLTREE(){
root=nullptr;
}

// hight 
int get_hight(Node *node){
    if (!node)return 0;
    return node->hight;
}


// balance

int get_balance(Node *node){
    if (!node)return 0;
    return get_hight(node->left)-get_hight(node->right);
}


// update hight 

void update_hight(Node *node){
    if (!node)return 0;
    node->hight= 1 + max(get_hight(node->left),get_hight(node->right));
}


// do the rotations  


Node* Right_Rotation(Node *node){
    // node =30 | x = 20
    Node *x = node->left;
    Node *y = x->right;
    x->right = node ;
    node->left = y;
    update_hight(x);
    update_hight(node);
    return x;
}



Node* Left_Rotation(Node *node){
    // node 10 , x = 20
    Node *x = node ->right;
    Node *y = x->left;
    x->left= node;
    node->right = y;
    update_hight(x);
    update_hight(node);
    return x;
}



Node* Left_Right_Rotation(Node *node){
    node->left = Left_Rotation(node->left);
    return Right_Rotation(node);
}



Node* Right_Left_Rotation(Node *node){
    node->right = Right_Rotation(node->right);
    return Left_Rotation(node);
}




};// End





int main()
{

return 0;

}
