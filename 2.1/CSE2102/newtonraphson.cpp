#include<bits/stdc++.h>
using namespace std;
float f_der(float x)
{
    return (pow((1-x),2)*2*x+(2*x*x*(1-x)))*70-(0.0016*pow((1-x),4));
}
float fn(float x)
{
    return (x*x*70/pow((1-x),2))-0.0016*(2+x);
}
int main()
{
    float x0=-1,x1;
    if(f_der(x0)==0){
        cout<<"Wrong guess";
    }
    else
    {
        int i=0;
        do
        {
            x1=x0-fn(x0)/f_der(x0);
            i++;
            cout<<"Iteration = "<<i<<", x1 = "<<x1<<" f(x0) = "<<fn(x0)<<" f'(x0) = "<<f_der(x0)<<endl;
            x0=x1;
        }
        while(fabs(fn(x0))>0.01);
        cout<<"Final root = "<<x1<<endl;
    }
    return 0;
}
