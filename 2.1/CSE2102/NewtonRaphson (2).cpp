#include<bits/stdc++.h>
using namespace std;
float pi=3.1416;

float f_derivative(float h)
{
    int a[3]= {0, (-1)*30*pi, 3*pi};
    float co=a[2];
    for(int i=1; i>=0; i--)
        co=co*h+a[i];
    return co;
}

float horners(float h)
{
    int a[4]= {150, 0,(-1)*15*pi, pi};
    float co=a[3];
    for(int i=2; i>=0; i--)
        co=co*h+a[i];
    return co;
}


int main()
{
    float h0=10, h1;
    if(f_derivative(h0)==0)
        cout<<"Wrong Guess";
    else
    {
        int i=1;
        while(i<=6)
        {

            h1=h0-(horners(h0)/f_derivative(h0));
            float x=(fabs((h1-h0)/h1))*100;
            cout<<"Iterations: "<<i<<" H: "<<h1<<" Relative % error ="<<x<<"%"<<endl;
            h0=h1;
            i++;
        }

    }

    cout<<"Final Root: "<<h1<<endl;

}
