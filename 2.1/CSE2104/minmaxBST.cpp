#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
};

int findMin(node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

int findMax(node* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int main()
{
    node *root = new node();
    root->data = 5;
    root->left = new node();
    root->left->data = 3;
    root->right = new node();
    root->right->data = 8;
    root->left->left = new node();
    root->left->left->data = 2;
    root->left->right = new node();
    root->left->right->data = 4;
    root->right->left = new node();
    root->right->left->data = 7;
    root->right->right = new node();
    root->right->right->data = 9;

    int minValue = findMin(root);
    int maxValue = findMax(root);

    cout << "Minimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue << endl;
    return 0;
}