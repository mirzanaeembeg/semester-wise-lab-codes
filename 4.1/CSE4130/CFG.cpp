#include<bits/stdc++.h>
using namespace std;
string str;
bool found;
int length, i;
void B(){
    if(str[i] == 'b'){
        found = true;
        i++;
    }
    else{
        found = false;
        return;
    }
}
//aaaab
void A(){
    if(str[i] == 'a'){
        i++;
        found = true;
    }
    else{
        found = false;
        return;
    }
    if (i < length-1)
        A();

}
void S(){
    if(str[i] == 'b'){
        found = true;
        i++;
        return;
    }
    else{
        A();
        if(found){
            B();
        }
    }
}



int main(){
    while(1){
        found = true;
        i = 0;
        cout << "Enter a string: ";
        cin >> str;
        cout << endl;
        length = str.size();
        S();
        if(!found || i != length){
            cout << "Invalid String!" << endl;
        }
        else{
            cout << "Valid String!" << endl;
        }
    }

}
