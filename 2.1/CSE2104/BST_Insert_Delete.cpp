#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
};
node *root = NULL;
void insert(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *curr_node = root;
        node *prev_node = root;
        while (curr_node != NULL)
        {
            if (curr_node->data > temp->data)
            {
                prev_node = curr_node;
                curr_node = curr_node->left;
            }
            else
            {
                prev_node = curr_node;
                curr_node = curr_node->right;
            }
        }
        if (prev_node->data > temp->data)
        {
            prev_node->left = temp;
        }
        else
        {
            prev_node->right = temp;
        }
    }
}
void delete_node(int val)
{
    node *curr_node = root;
    node *prev_node = root;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
            break;
        prev_node = curr_node;
        if (curr_node->data < val)
        {
            curr_node = curr_node->right;
        }
        else
        {
            curr_node = curr_node->left;
        }
    }
    if (curr_node->left == NULL && curr_node->right == NULL)
    {
        if (prev_node->right == curr_node)
            prev_node->right = NULL;
        else
            prev_node->left = NULL;
    }
    else if (curr_node->left == NULL || curr_node->right == NULL)
    {
        node *child;
        if (curr_node->right == NULL)
            child = curr_node->left;
        else
            child = curr_node->right;
        if (prev_node->right == curr_node)
            prev_node->right = child;
        else
            prev_node->left = child;
    }
    else
    {
        node *temp = curr_node;
        prev_node = curr_node;
        curr_node = curr_node->right;
        while (curr_node->left != NULL)
        {
            prev_node = curr_node;
            curr_node = curr_node->left;
        }
        temp->data = curr_node->data;
        if (prev_node->left == curr_node)
        {
            prev_node->left = curr_node->right;
        }
        else
            prev_node->right = curr_node->right;
    }
}
void in_order(node *temp)
{
    if (temp != NULL)
    {
        in_order(temp->left);
        cout << temp->data << " ";
        in_order(temp->right);
    }
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);
    in_order(root);
    delete_node(20);
    cout << endl;
    in_order(root);
    return 0;
}