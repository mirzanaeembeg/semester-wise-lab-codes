#include<bits/stdc++.h>
using namespace std;
int lenearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,key;
    cout<<"Enter array size:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter key:\n";
    cin>>key;
    cout<<"Key at index:"<<lenearSearch(arr,n,key);
    return 0;
}