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
    void insertValue(int value) {
        root = insertRec(root, value);
    }

    // Search for a value in the BST
    bool searchValue(int value) {
        return searchRec(root, value);
    }

    // Delete a value from the BST
    void deleteValue(int value) {
        root = deleteRec(root, value);
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

    Node* deleteRec(Node* node, int value) {
        if(node == nullptr) {
            return node; // Tree is empty
        }

        // Traverse the tree to find the node to delete
        if(value < node->data) {
            node->left = deleteRec(node->left, value);
        }
        else if(value > node->data) {
            node->right = deleteRec(node->right, value);
        }
        else {
            // Node found

            // Case 1: Node has no children(leaf node)
            if(node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            // Case 2: Node has one child
            else if(node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Node has two childern
            else {
                // Find the in-order successor (Smallest in the right subtree)
                Node* successor = findMin(node->right);
                node->data = successor->data; // Replace with successor's data
                node->right = deleteRec(node->right, successor->data); // Delete successor
            }
        }

        return node;
    }

    // Helper function to find the minimum node in a subtree
    Node* findMin(Node* node) {
        while(node->left != nullptr) {
            node = node->left;
        }

        return node;
    }
};

int main()
{
    BinarySearchTree bst;

    bst.insertValue(5);
    bst.insertValue(3);
    bst.insertValue(7);
    bst.insertValue(1);
    bst.insertValue(4);

    std::cout << "Search for 4: " << (bst.searchValue(4) ? "Found" : "Not Found") << '\n';
    std::cout << "Search for 6: " << (bst.searchValue(6) ? "Found" : "Not Found") << '\n';

    bst.deleteValue(4);
    std::cout << "After deletion of value 4:\n";
    std::cout << "Search for 4: " << (bst.searchValue(4) ? "Found" : "Not Found") << '\n';
    std::cout << "Search for 3: " << (bst.searchValue(3) ? "Found" : "Not Found") << '\n';

    return 0;
}