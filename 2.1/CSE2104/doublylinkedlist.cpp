#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
node *root=NULL;
node *tail=NULL;
void printing(){
    node *curr_node=root;
    while(curr_node!=NULL){
        cout<<curr_node->data<<" ";
        curr_node=curr_node->next;
    }
    cout<<endl;
    curr_node=tail;
    while(curr_node!=NULL){
        cout<<curr_node->data<<" ";
        curr_node=curr_node->prev;
    }
}
void searching(int val){
    node *curr_node=root;
    while(curr_node!=NULL){
        if(curr_node->data==val){
            cout<<"Found"<<endl;;
            return;
        }
        curr_node=curr_node->next;
    }
    cout<<"Not Found"<<endl;
}
int counting(){
    node *curr_node=root;
    int cnt=0;
    while(curr_node!=NULL){
        cnt++;
        curr_node=curr_node->next;
    }
    return cnt;
}
void insert_last(int val){
    node* temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    if(root==NULL){
        root=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void delete_last(){
    tail=tail->prev;
    tail->next=NULL;
}
void delete_first(){
    root=root->next;
    root->prev=NULL;
}
void insert_first(int val){
    node *temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    if(root==NULL){
        root=temp;
        tail=temp;
    }
    else{
        temp->next=root;
        root->prev=temp;
        root=temp;
    }
}
void insert_anywhere(int pos,int val){
    int n=counting();
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    if(root==NULL){
        root=temp;
        tail=temp;
    }
    else if(pos==1){
        insert_first(val);
    }
    else if(pos>n){
        insert_last(val);
    }
    else{
        node *curr_node=root;
        //while(curr_node!=NULL){
            //int cnt=0;
            for(int i=1;i<=pos-1;i++){
                curr_node=curr_node->next;
            }
            temp->next=curr_node->next;
            curr_node->next->prev=temp;
            curr_node->next=temp;
            temp->prev=curr_node;
            /*if(cnt!=(pos-1)){
                tail->next=temp;
                temp->prev=tail;
                tail=temp;
                temp->next=root;
                root->prev=temp;
                root=temp;

                cnt++;
            }*/
            //curr_node=curr_node->next;

    }
}
int main(){
    insert_last(10);
    insert_last(20);
    insert_last(30);
    insert_last(40);
    printing();
    cout<<endl;
    insert_anywhere(3,60);
    printing();

}
