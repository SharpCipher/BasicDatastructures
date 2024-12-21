#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void postOrder(TreeNode* node) {
    if(node == nullptr) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

void preOrder(TreeNode* node) {
    if(node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(TreeNode* node) {
    if(node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

int main()
{
    TreeNode* t1 = new TreeNode(4);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(6);
    TreeNode* t2 = new TreeNode(5);
    TreeNode* t3 = new TreeNode(1);

    t1->left->left = t2;
    t1->left->right = t3;

    std::cout << "Post Order: ";
    postOrder(t1);

    std::cout << "\nPre Order: ";
    preOrder(t1);

    std::cout << "\nIn Order: ";
    inOrder(t1);

    std::cout << '\n';

    return 0;
}