#include<bits/stdc++.h>
using namespace std;
float fn(float x)
{
    return x*x*x-x-1;
}
int main()
{
    float a,b,c,e;
    cin>>a>>b>>e;
    if((fn(a)*fn(b))>0)
        cout<<"Wrong Interval!";
    else
    {
        do
        {
            c=a-((fn(a)*(a-b))/(fn(a)-fn(b)));
            if(fn(a)*fn(c)<0)
                b=c;
            else
                a=c;
        cout<<"Root = "<<c<<" f(x) = "<<fn(c)<<endl;
        }
        while(fabs(fn(c))>e);
        cout<<"Final root = "<<c<<endl;
    }
    return 0;
}
