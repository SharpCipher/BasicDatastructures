#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root) {
    // Base case : If the tree is empty, the height is 0
    if(root == nullptr)
        return 0;
    
    // Recursively find the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // The height of the current node is the maximum of the heights of its left and right subtrees plus 1
    return std::max(leftHeight, rightHeight) +1 ;
}

void deleteAllTreeNodes(TreeNode* root) {
    if(root == nullptr)
        return;

    deleteAllTreeNodes(root->left);
    deleteAllTreeNodes(root->right);

    delete root;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);

    int treeHeight = height(root);

    std::cout << "Height of the Binary Tree: " << treeHeight << '\n';

    deleteAllTreeNodes(root);

    return 0;
}