#include <stdio.h>
int main()
{
    int bsal;
    double gsal;
    printf("Enter Rahim's basic salary:");
    scanf("%d",&bsal);
    gsal=bsal+.3*bsal+.05*bsal+1000;
    printf("Rahim's gross salary=%.2lf",gsal);
    return 0;
}
