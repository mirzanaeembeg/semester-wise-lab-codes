#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *root = NULL;

void printing() {
    if (root == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* curr_node = root;
    do {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    } while (curr_node != root);

    cout << endl;
}
int counting() {
    if (root == NULL) {
        return 0;
    }

    int cnt = 0;
    node* curr_node = root;
    do {
        cnt++;
        curr_node = curr_node->next;
    } while (curr_node != root);

    return cnt;
}

void delete_first(){
    node* curr_node = root;
    while (curr_node->next != root) {
        curr_node = curr_node->next;
    }
    root=root->next;
    curr_node->next=root;
}
void delete_last(){
    node* curr_node = root;
    while (curr_node->next->next != root) {
        curr_node = curr_node->next;
    }
    curr_node->next=root;
}
void delete_anywhere(int pos) {
    if (root == NULL) {
        cout << "Circular linked list is empty." << endl;
        return;
    }

    int n = counting();
    if (pos < 1 || pos > n) {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 1) {
        delete_first();
        return;
    }

    if (pos == n) {
        delete_last();
        return;
    }

    node* prev_node = NULL;
    node* curr_node = root;
    int count = 1;

    while (count < pos) {
        prev_node = curr_node;
        curr_node = curr_node->next;
        count++;
    }

    prev_node->next = curr_node->next;
}

int main(){
    node* A = new node();
    node* B = new node();
    node* C = new node();
    node* D = new node();

    A->data = 10;
    A->next = B;
    B->data = 20;
    B->next = C;
    C->data = 30;
    C->next = D;
    D->data = 40;
    D->next = A;

    root = A;
    delete_anywhere(2);
    delete_first();
    delete_last();
    printing();

    return 0;
}
