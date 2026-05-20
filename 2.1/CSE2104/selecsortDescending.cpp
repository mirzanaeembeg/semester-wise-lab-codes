#include<bits/stdc++.h>
using namespace std;
void selectionsort(vector<int>v,int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(v[max]<v[j]){
                max=j;
            }
        }
        swap(v[i],v[max]);
    }
    cout<<"After doing selection sort..\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    int x,n;
    vector<int>a;
    cout<<"Enter vector size:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    selectionsort(a,n);
    return 0;
}