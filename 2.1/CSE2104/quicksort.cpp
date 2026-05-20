#include<bits/stdc++.h>
using namespace std;
vector<int>A;
int Partition(int low,int hi){
    int pivot=A[low];
    int i=low,j=hi;
    while(i<j){
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            swap(A[i],A[j]);
        }
    }
    swap(A[low],A[j]);
    return j;
}
void quicksort(int low,int hi){
    if(low<hi){
        int pos=Partition(low,hi);
        quicksort(low,pos-1);
        quicksort(pos+1,hi);
    }
}
int main(){
    int x,y;
    cout<<"Enter vector size:";
    cin>>x;
    cout<<"Enter vector elements:\n";
    for(int i=0;i<x;i++){
        cin>>y;
        A.push_back(y);
    }
    quicksort(0,A.size()-1);
    cout<<"After quick sort..\n";
    for(int i=0;i<x;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}