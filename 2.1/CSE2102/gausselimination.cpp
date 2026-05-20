#include<bits/stdc++.h>
using namespace std;

const int Max=5;
int itterator1=0;
int itterator2=0;

void gauss_Eli(int n, double t[Max][Max + 1])
{

    for (int k=0; k<n-1; ++k)
    {
        itterator1++;
        for (int i=k+1; i<n; ++i)
        {
            double fac = t[i][k] / t[k][k];
            for (int j=k; j<n+1; ++j)
            {
                t[i][j]-=fac*t[k][j];
            }
        }
    }
    double x[Max];
    x[n-1] = t[n-1][n] / t[n-1][n-1];
    for (int i = n-2; i>=0; --i)
    {
        itterator2++;
        double sum=0.0;
        for (int j = i+ 1; j<n; ++j)
        {

            sum += t[i][j] * x[j];

        }
        x[i]=(t[i][n]-sum) / t[i][i];
    }

    cout << "Distance of the three places from Hotel Hilton using Gauss elimination are: \n";
    cout << "X"<< " = " << x[0] << endl;
    cout << "Y"<< " = " << x[1] << endl;
    cout << "Z"<< " = " << x[2] << endl;
    cout<<"Number of iterations required: "<<itterator1+itterator2<<endl;
}

int main()
{
    int order;
    cout<<"Enter the order : ";
    cin >> order;

    double coeff[Max][Max+1];
    for (int i = 0; i < order; ++i)
    {
        for (int j = 0; j < order + 1; ++j)
        {
            cin>>coeff[i][j];
        }
    }

    gauss_Eli(order, coeff);

    return 0;
}


