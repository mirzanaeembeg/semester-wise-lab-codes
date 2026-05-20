#include<bits/stdc++.h>
using namespace std;
vector<int>v={16,24,30,34,39,50,54};
int n=v.size();
int temp=v[n-1];
void insertion(int key){
    int j=n-1;
    while(v[j]>key && j>=0){
        v[j+1]=v[j];
        j--;
    }
    v[j+1]=key;
}
int main(){
    int y;
    cout<<"Enter key:\n";
    cin>>y;
    insertion(y);
    v.push_back(temp);
    cout<<"After insertion..\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}