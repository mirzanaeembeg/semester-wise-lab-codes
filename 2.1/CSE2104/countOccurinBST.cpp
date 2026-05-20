#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
};

int countOccurrences(node *root, int target)
{
    if (root == nullptr)
    {
        return 0;
    }

    int count = 0;
    stack<node *> st;
    node *currentNode = root;

    while (!st.empty() || currentNode != nullptr)
    {
        if (currentNode != nullptr)
        {
            st.push(currentNode);
            currentNode = currentNode->left;
        }
        else
        {
            node *Node = st.top();
            st.pop();

            if (Node->data == target)
            {
                count++;
            }

            currentNode = Node->right;
        }
    }

    return count;
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

    int target = 5;
    int occurrences = countOccurrences(root, target);

    cout << "Number of occurrences of " << target << ": " << occurrences << endl;

    return 0;
}
