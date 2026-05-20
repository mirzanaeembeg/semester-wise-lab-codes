#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root=NULL;
void in_order(node *temp){
    if(temp!=NULL){
        in_order(temp->left);
        cout<<temp->data<<" ";
        in_order(temp->right);
    }
}

void post_order(node *temp){
    if(temp!=NULL){
        post_order(temp->left);
        post_order(temp->right);
        cout<<temp->data<<" ";
    }
}
void pre_order(node *temp){
    if(temp!=NULL){
        cout<<temp->data<<" ";
        pre_order(temp->left);
        pre_order(temp->right);
    }
}
int main(){
    node *A,*B,*C,*D,*E;
    A=new node();
    B=new node();
    C=new node();
    D=new node();
    E=new node();
    A->data=10;
    A->left=B;
    A->right=C;
    B->data=15;
    B->left=D;
    B->right=NULL;
    C->data=11;
    C->left=NULL;
    C->right=E;
    D->data=25;
    D->left=NULL;
    D->right=NULL;
    E->data=19;
    E->left=NULL;
    E->right=NULL;
    root=A;
    pre_order(root);
    cout<<endl;
    in_order(root);
    cout<<endl;
    post_order(root);
    return 0;
}
