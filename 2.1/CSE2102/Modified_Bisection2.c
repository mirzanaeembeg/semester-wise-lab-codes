#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define error 0.00001

float f(float p[],int n,float x)
{
    float result=0;
    int i;
    for(i=0;i<=n;i++)
    {
        result=result*x+p[i];
    }
    return result;
}

int main()
{
    printf("\n Enter the highest degree of the equation: ");
    int n,i;
    scanf("%d",&n);

    float a,b,x0,x1,x2,f0,f1,f2,e,ds=0.1;

    float coeff[n+1];

    printf("\n Enter values of coefficients: ");
    for(i=0;i<=n;i++)
    {
        printf("\n Coefficient x^%d = ",n-i); // 2×3 – 6×2 + 2x – 1
        scanf("%f",&coeff[i]);
    }

    float xmax=sqrt(pow((coeff[1]/coeff[0]),2)-2*(coeff[2]/coeff[0]));
    printf("Possible interval %f and %f\n",-xmax,xmax);
    b=xmax;
    for(a=-xmax;a<=xmax;a+=.005)
    {
        int itrCount=0;
        int rootCount=1;
        float err;
        x0=a;
        x1=x0+ds;

        printf("Number of Root\tApproximate Root\tNumber of Iteration \t Relative Error\n");
        while(x1<b)
        {
            x0=a;
            x1=x0+ds;
            f0=f(coeff,n,x0);
            f1=f(coeff,n,x1);

            if(f0*f1>0)
            {
                //printf("Wrong Guess\n");
            }
            else
            {

                do{
                        x2=(x0+x1)/2;
                        f2=f(coeff,n,x2);

                        if((f0*f2)<0)
                        {
                            x1=x2;
                        }
                        else
                        {
                            x0=x2;
                            //f0=f2;
                        }
                        err=fabs((x1-x0)/x1);

                }while(fabs((x1-x0)/x1)>=error);

                printf("%d \t\t %f \t\t %d \t\t\t %f\n",rootCount,x2,itrCount,err);
                rootCount++;
                if(x1>b)
                {
                    break;
                }
            }
            itrCount++;
            a=x1;
        }
   }
}
