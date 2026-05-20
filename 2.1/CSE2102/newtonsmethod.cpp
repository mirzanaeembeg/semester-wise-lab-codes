#include <stdio.h>
#include<math.h>

double f(double arr[],int n,double x)
{
    double result=arr[0];
    int i;
    for(i=1;i<=n;i++)
    {
        result=result*x+arr[i];
    }
    return result;
}

double f_der(double arr[],int n,double x)
{
    double result=0;
    int i;
    for(i=0;i<n;i++)
    {
        result=result*x+(n-i)*arr[i];
    }
    return result;
}

int main()
{
    double x0=10,x1,e=0.01;
    double a[]={1,-6,11,-6};
    double b[4];
    int n=3;
    int temp=n;
    while(n>1)
    {
        int count=0;
        do
        {
            x1=x0-(f(a,n,x0)/f_der(a,n,x0));
            printf("%f %f f(x0)=%f f(x1)=%f\n",x0,x1,f(a,n,x0),f(a,n,x1));
            x0=x1;
            count++;
            if(count==100)
                break;

        }while(fabs(f(a,n,x0))>e);
        printf("\n %d root = %f\n",temp-n+1, x0);

        b[0]=a[0];
        //printf("\n%f ", b[0]);
        int i;
        for(i=1;i<=n;i++)
        {
            b[i]=a[i]+x0*b[i-1];
            //printf("%f ", b[i]);
        }
        printf("\n");
        n--;
        for(i=0;i<=n;i++)
        {
            a[i]=b[i];
            //printf("%f ", a[i]);
        }
    }
    double x2=-a[0]/a[1];
    printf("\n %d root = %f\n",temp-n+1,x2);

    return 0;
}