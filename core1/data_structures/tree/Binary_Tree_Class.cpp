/******************************************************************************

                              Binary Trees.

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
    
    
    void Build_Tree(){
        
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);

        
 
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
    
    
    
    
    
    Node* Search_BST(Node *node, int key){
        
        if (node == nullptr){
            return nullptr;   // unsuccessful search 
        }
        
        if (key == node->data){
            return node;  // we found the key 
        }
        
        
        if (key < node->data){
            return Search_BST(node->left,key);
        } else {
            return Search_BST(node->right,key);
            
        }
        
    }
    
    
    
      
    Node* Search_Binary(Node *node, int key){
        
        if (node == nullptr){
            return nullptr;   // unsuccessful search 
        }
        
        if (key == node->data){
            return node;  // we found the key 
        }
        
        
        // search left 
        Node* left_result= Search_Binary(node->left,key);
        
        if(left_result!=nullptr)
            return left_result;
        
        return Search_Binary(node->right,key);

    }  
    
    
    
    
    
    
};


int main()
{
    Binary_tree object;

    object.Build_Tree();
    
    cout << "Preorder (Root-Left-Right) traverse:"<< endl;
    object.Preorder(object.root);
    
    cout << endl;
    
        
    cout << "Inorder (Left-Root-Right) traverse:"<< endl;
    object.Inorder(object.root);
    
    cout << endl;
    
        
    cout << "Postorder (Left-Right-Root) traverse:"<< endl;
    object.Postorder(object.root);
    
    
    
    
    Node *Result = object.Search_BST(object.root,4);
    
    if (Result!=nullptr){
        
        cout << "\n The address of the node contaning the key is" << Result << endl;
        cout << "\n The vale inside the node is" << Result->data << endl;
    } else {
        cout << "\n key not found!" << endl; 
    }
    
    
    return 0;
}





