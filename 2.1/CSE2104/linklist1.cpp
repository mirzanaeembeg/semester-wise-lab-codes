#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *A = new node();
node *B = new node();
node *C = new node();
node *D = new node();
void printing()
{
    node *curr_node = A;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
}

void searching(int val)
{
    node *curr_node = A;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
        {
            cout << "Found" << endl;
            return;
        }
        curr_node = curr_node->next;
    }
    cout << "Not found" << endl;
}
int sizeOfList()
{
    int count = 0;
    node *curr_node = A;
    while (curr_node != NULL)
    {
        count++;
        curr_node = curr_node->next;
    }
    return count;
}

int main()
{
    A->data = 10;
    A->next = C;
    B->data = 30;
    B->next = NULL;
    C->data = 40;
    C->next = D;
    D->data = 20;
    D->next = B;

    cout << "Printing the list:" << endl;
    printing();
    cout<<endl;
    cout << "Searching for value 50:" << endl;
    searching(50);
    int size = sizeOfList();
    cout << "Size of the list: " << size << endl;

    return 0;
}