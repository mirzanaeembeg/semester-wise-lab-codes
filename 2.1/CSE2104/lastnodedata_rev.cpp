#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *A,*B,*C,*D;
int lastnode(){
    node *curr_node=A;
    while(curr_node->next!=NULL){
        curr_node=curr_node->next;
    }
    return curr_node->data;
}
void reverse() {
    node *prev_node = NULL, *curr_node = A, *next_node = NULL;
    while (curr_node != NULL) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    A = prev_node;
}
void printing()
{
    node *curr_node = A;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
}
int main(){

    A=new node();
    B=new node();
    C=new node();
    D=new node();
    A->data=10;
    A->next=C;
    B->data=20;
    B->next=NULL;
    C->data=30;
    C->next=D;
    D->data=40;
    D->next=B;
    cout<<"Data of the last node:"<<lastnode()<<endl;
    cout<<"After reverse the node:\n";
    reverse();
    printing();
    return 0;
}