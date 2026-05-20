#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* right;
    TreeNode* left;
};

bool searchBST(TreeNode* root, int val) {
    while (root != nullptr) {
        if (root->data == val) {
            return true;
        } else if (val < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return false;
}

int main() {
    TreeNode* root = new TreeNode();
    root->data = 5;
    root->left = new TreeNode();
    root->left->data = 3;
    root->right = new TreeNode();
    root->right->data = 8;
    root->left->left = new TreeNode();
    root->left->left->data = 2;
    root->left->right = new TreeNode();
    root->left->right->data = 4;
    root->right->left = new TreeNode();
    root->right->left->data = 7;
    root->right->right = new TreeNode();
    root->right->right->data = 9;

    int target = 10;

    if (searchBST(root, target)) {
        cout << "Value " << target << " found in the BST." << endl;
    } else {
        cout << "Value " << target << " not found in the BST." << endl;
    }

    return 0;
}
