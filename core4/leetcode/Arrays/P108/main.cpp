#include <iostream>
#include <vector>

using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BinaryTree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Public function to start building the tree
    void BuildTree(vector<int>& nums) {
        root = buildSubtree(nums, 0, nums.size() - 1);
    }

    // Public inorder traversal
    void Inorder() {
        Inorder(root);
        cout << endl;
    }

private:
    // Helper recursive function to build BST
    Node* buildSubtree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr; // base case: empty subarray
        }

        int mid = start + (end - start) / 2;
        Node* node = new Node(nums[mid]);

        // Recursively build left and right subtrees
        node->left  = buildSubtree(nums, start, mid - 1);
        node->right = buildSubtree(nums, mid + 1, end);

        return node;
    }

    // Helper recursive inorder traversal
    void Inorder(Node* node) {
        if (!node) return;
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }
};

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    BinaryTree tree;
    tree.BuildTree(nums);

    cout << "Inorder traversal of the BST: ";
    tree.Inorder(); // should print the sorted array
    return 0;
}
