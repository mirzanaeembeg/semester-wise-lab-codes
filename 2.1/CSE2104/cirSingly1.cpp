#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* root = NULL;

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

void searching(int val) {
    if (root == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* curr_node = root;
    do {
        if (curr_node->data == val) {
            cout << "Found" << endl;
            return;
        }
        curr_node = curr_node->next;
    } while (curr_node != root);

    cout << "Not Found" << endl;
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

int main() {
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

    printing();
    searching(50);
    cout << "Size: " << counting() << endl;
    return 0;
}
