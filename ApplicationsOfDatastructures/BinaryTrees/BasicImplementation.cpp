#include <iostream>

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        TreeNode* root;
        
        void preOrder(TreeNode* node) const {
            if(node) {
                std::cout << node->data << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }

        void inOrder(TreeNode* node) const {
            if(node) {
                inOrder(node->left);
                std::cout << node->data << " ";
                inOrder(node->right);
            }
        }

        void postOrder(TreeNode* node) const {
            if(node) {
                postOrder(node->left);
                postOrder(node->right);
                std::cout << node->data << " ";
            }
        }

        void destroyTree(TreeNode* node) {
            if(node) {
                destroyTree(node->left);
                destroyTree(node->right);

                delete node;
            }
        }

        TreeNode* findMin(TreeNode* node) const {
            while(node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        TreeNode* deleteNode(TreeNode* root, int data) {
            if(root == nullptr) {
                return root;
            }

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

                TreeNode* temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }

            return root;

        }

        bool search(TreeNode* node, int data) const {
            if(node == nullptr) {
                return false;
            }

            if(node->data == data) {
                return true;
            }

            if(data < node->data) {
                return search(node->left, data);
            }
            else {
                return search(node->right, data);
            }
        }

    public:
        BinaryTree() : root(nullptr) {}

        ~BinaryTree() {
            destroyTree(root);
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
            inOrder(root);
            std::cout << '\n';
        }

        void displayPostOrder() const {
            postOrder(root);
            std::cout << '\n';
        }

        void searchBT(int data) const {
            if(search(root, data)) {
                std::cout << "Data " << data << " found\n";
            }
            else {
                std::cout << "Data " << data << " not found!\n";
            }
        }

        int findMin() const {
            if(root == nullptr) {
                throw std::runtime_error("Tree is empty!");
            }
            else {
                return findMin(root)->data;
            }
        }

        void deleteTreeNode(int data) {
            root = deleteNode(root, data);
            std::cout << "Deleted " << data << '\n';
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