/******************************************************************************

                              Binary Search Trees (BST)

*******************************************************************************/

#include <iostream>
using namespace std;

class Node{
    
public:
    int data;
    Node *left;   // this points to a node (left to the root)
    Node *right;  // this points to a node (right to the root)
    
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};


class Binary_tree{
public:
    
    Node *root;
    Binary_tree(){
        root=nullptr;
    }
    
    
    
    
    // Recursively insert following binary search trees (BST).
    
    Node* Insert(Node *node, int val){
        
        if (node==nullptr){
            // we create a node if the current node is empty
            Node *newNode = new Node(val);
            //cout << "node address" << newNode << " ||| node->data:" << val << endl;
            return newNode;
        }
        
        if (val < node->data){
            // insert left;
            node->left = Insert(node->left,val);
        }else if (val > node->data) {
            // insert right;
            node->right = Insert(node->right,val);
        }else{
            
            cout << "Duplicate value can not be inserted !" << endl;
            
        }
        
        
        return node;
 
    }
    
    
    
    // Traversal (Preorder,Inorder,Postorder)
    
    
    
    // Root - Left -Right
    void Preorder(Node *node){
        if (node==nullptr){
            return;
        }
        
        cout << node->data <<" ";
        Preorder(node->left);
        Preorder(node->right);

    } 
    

    
    // Left - Root - Right
    void Inorder(Node *node){
        if (node==nullptr){
            return;
        }
        
        Inorder(node->left);
        cout << node->data <<" ";
        Inorder(node->right);
    }
    
    
    
    
    // Left -Right-Root
    void Postorder(Node *node){
        if (node==nullptr){
            return;
        }
        
        Postorder(node->left);
        Postorder(node->right);
        cout << node->data <<" ";
    } 
    
    
    
};


int main()
{
    Binary_tree object;
    object.root = object.Insert(object.root,1);
    object.Insert(object.root,2);
    object.Insert(object.root,3);
    object.Insert(object.root,4);
    object.Insert(object.root,5);
    
    
    
    cout << "Preorder (Root-Left-Right) traverse:"<< endl;
    object.Preorder(object.root);
    
    cout << endl;
    
        
    cout << "Inorder (Left-Root-Right) traverse:"<< endl;
    object.Inorder(object.root);
    
    cout << endl;
    
        
    cout << "Postorder (Left-Right-Root) traverse:"<< endl;
    object.Postorder(object.root);
    
    
    return 0;
}




