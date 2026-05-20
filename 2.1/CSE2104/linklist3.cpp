#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

node* root = NULL;

void printing()
{
    node* curr_node = root;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
}

void delete_first()
{
    if (root == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    node* temp = root;
    root = root->next;
    delete temp;
}

void delete_last()
{
    if (root == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    if (root->next == NULL)
    {
        delete root;
        root = NULL;
        return;
    }

    node* curr_node = root;
    while (curr_node->next->next != NULL)
    {
        curr_node = curr_node->next;
    }

    delete curr_node->next;
    curr_node->next = NULL;
}

void delete_anywhere(int position)
{
    if (root == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    if (position == 0)
    {
        delete_first();
        return;
    }

    node* curr_node = root;
    node* prev_node = NULL;
    int count = 0;

    while (curr_node != NULL && count < position)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
        count++;
    }

    if (curr_node == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    prev_node->next = curr_node->next;
    delete curr_node;
}

int main()
{
    node* A = new node();
    node* B = new node();
    node* C = new node();
    node* D = new node();

    A->data = 10;
    A->next = C;
    B->data = 30;
    B->next = NULL;
    C->data = 40;
    C->next = D;
    D->data = 20;
    D->next = B;

    root = A;
    
    delete_first();
    delete_last();
    delete_anywhere(2);

    cout << "After deletion, the list:" << endl;
    printing();
    cout << endl;

    return 0;
}
