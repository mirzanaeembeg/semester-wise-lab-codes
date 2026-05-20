#include<bits/stdc++.h>
using namespace std;

void polynomialRegression()
{
    int i,j,k,n,N;
    cout.precision(4);
    cout.setf(ios::fixed);
    cout<<"\nEnter the no. of data pairs to be entered:\n";
    cin>>N;
    double x[N],y[N];
    cout<<"\nEnter the x-axis values:\n";
    for (i=0; i<N; i++)
        cin>>x[i];
    cout<<"\nEnter the y-axis values:\n";
    for (i=0; i<N; i++)
        cin>>y[i];
    cout<<"\nWhat degree of Polynomial do you want to use for the fit?\n";
    cin>>n;
    double X[2*n+1];
    for (i=0; i<2*n+1; i++)
    {
        X[i]=0;
        for (j=0; j<N; j++)
            X[i]=X[i]+pow(x[j],i);
    }
    double B[n+1][n+2],a[n+1];
    for (i=0; i<=n; i++)
        for (j=0; j<=n; j++)
            B[i][j]=X[i+j];
    double Y[n+1];
    for (i=0; i<n+1; i++)
    {
        Y[i]=0;
        for (j=0; j<N; j++)
            Y[i]=Y[i]+pow(x[j],i)*y[j];
    }
    for (i=0; i<=n; i++)
        B[i][n+1]=Y[i];
    n=n+1;
    cout<<"\nThe Normal(Augmented Matrix) is as follows:\n";
    for (i=0; i<n; i++)
    {
        for (j=0; j<=n; j++)
            cout<<B[i][j]<<setw(16);
        cout<<"\n";
    }
    for (i=0; i<n; i++)
        for (k=i+1; k<n; k++)
            if (B[i][i]<B[k][i])
                for (j=0; j<=n; j++)
                {
                    double temp=B[i][j];
                    B[i][j]=B[k][j];
                    B[k][j]=temp;
                }

    for (i=0; i<n-1; i++)
        for (k=i+1; k<n; k++)
        {
            double t=B[k][i]/B[i][i];
            for (j=0; j<=n; j++)
                B[k][j]=B[k][j]-t*B[i][j];
        }
    for (i=n-1; i>=0; i--)
    {

        a[i]=B[i][n];
        for (j=0; j<n; j++)
            if (j!=i)
                a[i]=a[i]-B[i][j]*a[j];
        a[i]=a[i]/B[i][i];
    }
    cout<<"\nThe values of the coefficients are as follows:\n";
    for (i=0; i<n; i++)
        cout<<"x^"<<i<<"="<<a[i]<<endl;
    cout<<"\nHence the fitted Polynomial is given by:\ny=";
    for (i=0; i<n; i++)
        cout<<" + ("<<a[i]<<")"<<"x^"<<i;
    cout<<"\n";
}


int main()
{
    polynomialRegression();
    return 0;
}
/*
Enter the no. of data pairs to be entered:
10

Enter the x-axis values:
78.1
55
39.9
44.1
42.1
45
57
46.9
43
48.9

Enter the y-axis values:
1704
1646
526
521
1416
1885
1276
1982
504
1447

*/

