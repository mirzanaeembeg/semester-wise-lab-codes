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
void insert_first(int val) {
    node* temp = new node();
    temp->data = val;
    temp->next = NULL;

    if (root == NULL) {
        root = temp;
        temp->next = root;
    } else {
        node* curr_node = root;
        while (curr_node->next != root) {
            curr_node = curr_node->next;
        }
        curr_node->next = temp;
        temp->next = root;
        root = temp;
    }
}
void insert_last(int val) {
    node* temp = new node();
    temp->data = val;
    temp->next = NULL;

    if (root == NULL) {
        root = temp;
        temp->next = root;
    } else {
        node* curr_node = root;
        while (curr_node->next != root) {
            curr_node = curr_node->next;
        }
        curr_node->next = temp;
        temp->next = root;
    }
}
void insert_anywhere(int val, int position) {
    int n=counting();
    node* temp = new node();
    temp->data = val;
    temp->next = NULL;

    if (root == NULL) {
        root = temp;
        temp->next = root;
    } else {
        if (position==1) {
            insert_first(val);
        } else if(position>n){
            insert_last(val);
        }else{
            node* curr_node=root;
            for(int i=1;i<position-1;i++){
                curr_node=curr_node->next;
            }
            temp->next=curr_node->next;
            curr_node->next=temp;
        }
    }
}
int main(){
    insert_first(10);
    insert_first(20);
    insert_first(30);
    insert_first(40);
    insert_last(70);
    insert_last(80);
    insert_last(90);
    insert_last(100);
    insert_anywhere(50,4);
    insert_anywhere(60,5);
    printing();

}
