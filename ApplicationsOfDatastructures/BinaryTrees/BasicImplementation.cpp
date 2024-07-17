#include <iostream>

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    TreeNode* root;

    void preOrder(TreeNode* node) const {
        if(node) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inorderTraversal(TreeNode* root) const {
        if (root != nullptr) {
            inorderTraversal(root->left);
            std::cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
    void postorderTraversal(TreeNode* root) const{
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            std::cout << root->data << " ";
        }
    }   



    public:
        BinaryTree() : root(nullptr) {}

        ~BinaryTree() {
            destroyTree(root); 
        }

        void destroyTree(TreeNode* node) {
            if(node) {
                destroyTree(node->left);
                destroyTree(node->right);
            }
        }

        void insert(int value) {
            if(!root) {
                root = new TreeNode(value);
            }
            else {
                insert(value, root);
            }
        }

        void insert(int value, TreeNode* node) {
            if(value < node->data) {
                if(node->left) {
                    insert(value, node->left);
                }
                else {
                    node->left = new TreeNode(value);
                }
            }
            else {
                if(node->right) {
                    insert(value, node->right);
                }
                else {
                    node->right = new TreeNode(value);
                }
            }
        }

        void displayPreOrder() const {
            preOrder(root);
            std::cout << '\n';
        }

        void displayInOrder() const {
            inorderTraversal(root);
            std::cout << '\n';
        }

        void displayPostOrder() const {
            postorderTraversal(root);
            std::cout << '\n';
        }

};

int main()
{
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(8);
    
    std::cout << "PreOrder Traversal: ";
    tree.displayPreOrder();

    std::cout << "InOrder Traversal: ";
    tree.displayInOrder();

    std::cout << "PostOrder Traversal: ";
    tree.displayPostOrder();

    return 0;
}