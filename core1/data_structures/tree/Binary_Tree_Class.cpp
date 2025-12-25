/******************************************************************************

                              Binary Trees.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    Node *left;
    int data;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    Node *root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void CreateTree() {
        int x;
        cout << "Enter root value: ";
        cin >> x;

        root = new Node(x);  // memory address where this node is stored
        queue<Node*> q;
        q.push(root);       // The queue contains one element: the root node’s address

        while (!q.empty()) {
            Node *p = q.front();
            q.pop();

            cout << "Enter left child of " << p->data << " (-1 for none): ";
            cin >> x;
            if (x != -1) {
                Node *t = new Node(x); 
                p->left = t;
                t->left=t->right=nullptr;
                q.push(t);
            }

            cout << "Enter right child of " << p->data << " (-1 for none): ";
            cin >> x;
            if (x != -1) {
                Node *t = new Node(x); 
                p->right = t;
                t->left=t->right=nullptr;
                q.push(p->right);
            }
        }
        cout << "\nTree created successfully!\n";
    }

    // ---- Traversal Wrappers ----
    void Preorder()  { 
        Preorder(root);   // call the recursive function starting at root
        cout << endl;     
    }
    void Inorder()   { Inorder(root);    cout << endl; }
    void Postorder() { Postorder(root);  cout << endl; }
    void LevelOrder(){ LevelOrder(root); cout << endl; }

    // ---- Traversal Implementations ----
    void Preorder(Node *p) {
        if (p){
            cout << p->data << " ";
            Preorder(p->left);
            Preorder(p->right);
        }
    }

    void Inorder(Node *p) {
        if (!p) return;
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }

    void Postorder(Node *p) {
        if (!p) return;
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data << " ";
    }

    void LevelOrder(Node *p) {
        if (!p) return;
        queue<Node*> q;
        q.push(p);
        while (!q.empty()) {
            Node *t = q.front();
            q.pop();
            cout << t->data << " ";
            if (t->left)  q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }

    // ---- Height of Tree ----
    int Height(Node *p) {
        if (!p) return 0;
        int hl = Height(p->left);
        int hr = Height(p->right);
        return max(hl, hr) + 1;
    }

    int Height() {
        return Height(root);
    }
};

int main() {
    BinaryTree myTree;
    myTree.CreateTree();

    cout << "\nPreorder: ";  myTree.Preorder();
    cout << "Inorder: ";    myTree.Inorder();
    cout << "Postorder: ";  myTree.Postorder();
    cout << "LevelOrder: "; myTree.LevelOrder();
    cout << "Height: " << myTree.Height() << endl;

    return 0;
}
