#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

int height(Node *root) {
    if (root == NULL) {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    int height = 0;

    while (!q.empty()) {
        int n = q.size();
        height++;

        for (int i = 0; i < n; i++) {
            Node *node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }
        }
    }

    return height;
}

int main() {
    Node *root = new Node();
    root->data=1;
    root->left = new Node();
    root->left->data=2;
    root->right = new Node();
    root->right->data=3;
    root->left->left = new Node();
    root->left->left->data=4;
    root->left->right = new Node();
    root->left->right->data=5;
    root->right->left = new Node();
    root->right->left->data=6;
    root->right->right = new Node();
    root->right->right->data=7;

    cout << "Height of the binary tree is: " << height(root) << endl;
    return 0;
}
