#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node* root = NULL;

void printing()
{
    node *curr_node = root;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
}
void insert_first(int val){
    node *temp = new node();
    temp->data = val;
    temp->next = root;
    root = temp;
}
void insert_last(int val) {
    node* new_node = new node();
    new_node->data = val;
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        node* curr_node = root;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}
void insert_anywhere(int val, int position) {
    if (position <= 0) {
        insert_first(val);
        return;
    }

    node* new_node = new node();
    new_node->data = val;

    if (root == NULL) {
        root = new_node;
    } else {
        node* curr_node = root;
        node* prev_node = NULL;
        int count = 0;

        while (curr_node != NULL && count < position) {
            prev_node = curr_node;
            curr_node = curr_node->next;
            count++;
        }

        prev_node->next = new_node;
        new_node->next = curr_node;
    }
}

int main()
{
    node *A = new node();
    node *B = new node();
    node *C = new node();
    node *D = new node();

    A->data = 10;
    A->next = C;
    B->data = 30;
    B->next = NULL;
    C->data = 40;
    C->next = D;
    D->data = 20;
    D->next = B;

    root = A;

    insert_first(5);
    insert_last(15);
    insert_anywhere(25, 2);

    cout << "After insertion, the list:" << endl;
    printing();
    cout << endl;

    return 0;
}
