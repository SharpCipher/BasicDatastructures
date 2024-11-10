#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    // Insert a value into BST
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Search for a value in the BST
    bool search(int value) {
        return searchRec(root, value);
    }

private:
    Node* insertRec(Node* node, int value) {
        if(node == nullptr) {
            return new Node(value);
        }

        if(value <= node->data) {
            node->left = insertRec(node->left, value);
        }
        else if(value > node->data){
            node->right = insertRec(node->right, value);
        }

        return node;

    }

    bool searchRec(Node* node, int value) {
        if(node == nullptr) {
            return false;
        }

        if(node->data == value) {
            return true;
        }

        if(value < node->data) {
            return searchRec(node->left, value);
        }

        return searchRec(node->right, value);
    }
};

int main()
{
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);

    std::cout << "Search for 4: " << (bst.search(4) ? "Found" : "Not Found") << '\n';
    std::cout << "Search for 6: " << (bst.search(6) ? "Found" : "Not Found") << '\n';

    return 0;
}