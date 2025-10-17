#include <iostream>
using namespace std;

// High and balance factor calcualtion

class Node{
public:
  int data;
  int hight;
  Node *right;
  Node *left;
 
  Node(int val){
      hight = 1;
      data  = val;
      right=left=nullptr;
  }
};

// Node : node : node->left || node->right

int get_hight(Node *node){
    if (!node)return 0;
    return node->hight;
}
 
 int get_balance(Node *node){
     if (!node)return 0;
     return get_hight(node->left) - get_hight(node->right);
}

void update_hight(Node *node){
    if (node){
       
        node->hight = 1+ max(get_hight(node->left),get_hight(node->right));
    }
   
   
}  
 
 
 
void Node_Display(Node *node){
    if (!node) return;
   
    Node_Display(node->left);
    cout << "Node " << node->data << endl;
    cout << "Hight= " << get_hight(node) << "." << endl;
    cout << "BF= " << get_balance(node) << "." << endl;
    Node_Display(node->right);
}
 
 
 int main(){
     
     Node *root = new Node(1);
     root->left = new Node(2);
     root ->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);
     
     update_hight(root->left->left);
     cout << "------"<< endl;
     update_hight(root->left->right);
     cout << "------"<< endl;
     update_hight(root->left);
     cout << "------"<< endl;
     update_hight(root->right);
     cout << "------"<< endl;
     update_hight(root);
     
     Node_Display(root);
     
     
     
     
 }

 
  
