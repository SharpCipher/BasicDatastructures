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

        bool search(TreeNode* root, int data) {
            if (root == nullptr) {
                return false;
            }

            if (root->data == data) {
                return true;
            }

            if (data < root->data) {
                return search(root->left, data);
            } else {
                return search(root->right, data);
            }
        }

        void searchBT(int elem) {
            if(search(root, elem)) {
                std::cout << "element " << elem << " found!\n";
            }
            else {
                std::cout << "element " << elem << " not found!\n";
            }
        }

        int findMin() {
            while(root->left != nullptr)
                root = root->left;

            return root->data;
        }

        TreeNode* findMin(TreeNode* root) {
            while(root->left != nullptr){
                root = root->left;
            }
            return root;
        }

        TreeNode* deleteNode(TreeNode* root, int data) {
            if(root == nullptr)
                return root;
            if(data < root->data) {
                root->left = deleteNode(root->left, data);
            }
            else if(data > root->data) {
                root->right = deleteNode(root->right, data);
            }
            else {
                if(root->left == nullptr) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
                else if(root->right == nullptr) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }

                TreeNode* tn = findMin(root->right);
                root->data = tn->data;
                root->right = deleteNode(root->right, tn->data);
            }

            return root;
        }

        void deleteTreeNode(int data) {
            TreeNode* del = deleteNode(root, data);
            std::cout << "deleted " << del->data << '\n';
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
    tree.insert(1);
    
    std::cout << "PreOrder Traversal: ";
    tree.displayPreOrder();

    std::cout << "InOrder Traversal: ";
    tree.displayInOrder();

    std::cout << "PostOrder Traversal: ";
    tree.displayPostOrder();

    tree.searchBT(7);
    tree.searchBT(1);

    std::cout << "Minimum element: " << tree.findMin() << '\n';

    tree.deleteTreeNode(7);
    tree.displayInOrder();

    return 0;
}