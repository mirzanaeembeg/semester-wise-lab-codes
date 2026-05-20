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
void print_last_data() {
    if (root == NULL) {
        cout << "Circular linked list is empty." << endl;
        return;
    }

    node* curr_node = root;
    while (curr_node->next != root) {
        curr_node = curr_node->next;
    }

    cout << "Last data: " << curr_node->data << endl;
}
void delete_first(){
    node* curr_node = root;
    while (curr_node->next != root) {
        curr_node = curr_node->next;
    }
    root=root->next;
    curr_node->next=root;
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
    //delete_first();
    printing();
    cout<<endl;
    print_last_data();
    

}
