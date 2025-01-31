#include <iostream>
#include <queue>

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

    // In-order traversal
    void inorder() const {
        inorderTraversal(root);
        std::cout << '\n';
    }

    // Pre-order traversal
    void preorder() const {
        preorderTraversal(root);
        std::cout << '\n';
    }

    // Post-order traversal
    void postorder() const {
        postorderTraversal(root);
        std::cout << '\n';
    }

    // Level-order traversal
    void levelorder() const {
        levelorderTraversal(root);
        std::cout << '\n';
    }

    // Find max element in the BST
    int findMax() const {
        return findMaxRec(root)->data;
    }

    // Find Min element in the BST
    int findMin() const {
        return findMinRec(root)->data;
    }

    // Find the Depth(Height) of the BST
    int height() const {
        return heightRec(root);
    }

    // Find the count of nodes in BST
    int countNodes() const {
        return countNodesRec(root);
    }

    // Check if a tree is BST
    bool isBST() const {
        return isBSTRec(root, nullptr, nullptr);
    }

    // Release or Clear all nodes
    void clear() {
        clearRec(root);
        root = nullptr;
    }

private:
    void clearRec(Node* node) {
        if(node == nullptr) {
            return;
        }
        clearRec(node->left);
        clearRec(node->right);

        delete node;
    }

    bool isBSTRec(Node* node, Node* minNode, Node* maxNode) const{
        if(node == nullptr)
            return true;
        if((minNode && node->data <= minNode->data) || (maxNode && node->data > maxNode->data)) {
            return false;
        }
        return isBSTRec(node->left, minNode, node) && isBSTRec(node->right, node, maxNode);
    }

    int countNodesRec(Node* node) const {
        if(node == nullptr) {
            return 0;
        }
        return 1 + countNodesRec(node->left) + countNodesRec(node->right);
    }

    int heightRec(Node* node) const {
        if(node == nullptr) {
            return -1;
        }
        return 1 + std::max(heightRec(node->left), heightRec(node->right));
    }
    Node* findMaxRec(Node* node) const{
        while(node->right != nullptr) {
            node = node->right;
        }

        return node;
    }

    void inorderTraversal(Node* node) const {
        if(node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);

    }

    void preorderTraversal(Node* node) const {
        if(node == nullptr) {
            return;
        }
        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) const {
        if(node == nullptr) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }

    void levelorderTraversal(Node* node) const {
        if(root == nullptr) {
            return;
        }
        std::queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()) {
            Node* current = nodeQueue.front();
            nodeQueue.pop();

            // Visit the current node
            std::cout << current->data << " ";

            // Enqueue the left child if it exists
            if(current->left != nullptr) {
                nodeQueue.push(current->left);
            }

            // Enqueue the right child if it exists
            if(current->right != nullptr) {
                nodeQueue.push(current->right);
            }
        }
        std::cout << '\n';
    }

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
                Node* successor = findMinRec(node->right);
                node->data = successor->data; // Replace with successor's data
                node->right = deleteRec(node->right, successor->data); // Delete successor
            }
        }

        return node;
    }

    // Helper function to find the minimum node in a subtree
    Node* findMinRec(Node* node) const{
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

    std::cout << "No.of nodes present in BST: " << bst.countNodes() << '\n';
    std::cout << "Search for 4: " << (bst.searchValue(4) ? "Found" : "Not Found") << '\n';
    std::cout << "Search for 6: " << (bst.searchValue(6) ? "Found" : "Not Found") << '\n';

    bst.deleteValue(4);
    std::cout << "After deletion of value 4:\n";
    std::cout << "Search for 4: " << (bst.searchValue(4) ? "Found" : "Not Found") << '\n';
    std::cout << "Search for 3: " << (bst.searchValue(3) ? "Found" : "Not Found") << '\n';
    std::cout << "No.of nodes present in BST: " << bst.countNodes() << '\n';

    bst.insertValue(18);
    bst.insertValue(56);
    bst.insertValue(23);
    std::cout << "No.of nodes present in BST: " << bst.countNodes() << '\n';
    
    std::cout << "BST in-order traversal: ";
    bst.inorder();

    std::cout << "BST pre-order traversal: ";
    bst.preorder();

    std::cout << "BST post-order traversal: ";
    bst.postorder();

    std::cout << "Current Maximum element in BST: " << bst.findMax() << '\n';
    std::cout << "Current Minimum element in BST: " << bst.findMin() << '\n';

    std::cout << "Length of the longest path from the root to leaf: " << bst.height() << '\n';
    
    bst.insertValue(2);
    bst.insertValue(245);
    bst.insertValue(168);
    std::cout << "No.of nodes present in BST: " << bst.countNodes() << '\n';
    std::cout << "Current Maximum element in BST: " << bst.findMax() << '\n';
    std::cout << "Current Minimum element in BST: " << bst.findMin() << '\n';
    std::cout << "Length of the longest path from the root to leaf: " << bst.height() << '\n';

    std::cout << "Is the current tree is a BST: " << (bst.isBST() ? "Yes" : "No")<< '\n';

    std::cout << "BST in-order traversal: ";
    bst.inorder();

    std::cout << "BST pre-order traversal: ";
    bst.preorder();

    std::cout << "BST post-order traversal: ";
    bst.postorder();

    std::cout << "BST level-order traversal: ";
    bst.levelorder();

    std::cout << "-------Delete the Tree----" << '\n';
    bst.clear();
    std::cout << "No.of nodes present in BST: " << bst.countNodes() << '\n';
    return 0;
}