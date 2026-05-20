#include <stdio.h>
int main()

{
    int   n, r, x = 1;
    int factnr = 1,  factr = 1;
    int  nCr, nPr,factn = 1;

    printf("enter x: ");
    scanf("%d", &x);
    printf("enter n: ");
    scanf("%d", &n);
    printf("enter r: ");
    scanf("%d", &r);

    for(int i = 1; i < n ; i++)
    {
        x = x * x;
    }
    for(int i = 1; i <= n; i++) //fact n;
    {
        factn = factn * i;
    }
    for(int i = 1; i <= r; i++) //fact r;
    {
        factr = factr * i;
    }
    for(int i = 1; i <= (n-r); i++) //fact n-r;
    {
        factnr = factnr * i;
    }

    nCr = factn/(factr * factnr);
    nPr = factn/factnr;

    printf(" x^n = %d\n", x);
    printf(" n! = %d\n", factn);
    printf(" nCr = %d\n", nCr);
    printf(" nPr = %d\n", nPr);

    return 0;
}
