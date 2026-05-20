#include<bits/stdc++.h>
using namespace std;
void selectionsort(vector<int>v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(v[min]>v[j]){
                min=j;
            }
        }
        swap(v[i],v[min]);
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
    cout<<"Enter vector elements:\n";
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    selectionsort(a);
    return 0;
}