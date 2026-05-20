#include <stdio.h>
int main()

{
    //i) 3+11+19+...+1691
    int i, sum=0;

    for(i = 3; i <= 1691; i+=8)
    {
        sum = sum + i;
    }

    //ii) 7+20+33+..+(up to 100th term)
    int j, nsum= 0;

    for(j = 7; j <= 1294; j+=13)
    {
        nsum = nsum + j;
    }

    //iii) 5-11+17-..(up to 75th term)
    int k, xsum=5, tsum = 0;

    for(k = 1; k <= 75; k ++)
    {   xsum += 6;
        if(k%2 == 0)
           tsum = tsum - xsum + 6;
        else
           tsum = tsum + xsum - 6;
    }

    //vi) 2*7*12*...*37
    int usum=1;

    for(int i=2; i<=37; i+=5)
    {
        usum = usum * i;
    }

    printf("7+20+...+1294 = %d\n", nsum);
    printf("3+11+...+1691 = %d\n", sum);
    printf("5-11+17-...+444 = %d\n", tsum);
    printf("2*7*12*...*37 = %d\n", usum);

    return 0;
}
