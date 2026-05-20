#include<stdio.h>
#include<string.h>
void strCount(char ch[])
{
    int i,nCh=0,nUCh=0,nLCh=0;
    int nN=0,nSpc=0,nTab=0;
    int x=strlen(ch);
    int sp=0;
    for(i=0;i<x;i++)
    {
        nCh++;
        if(ch[i]==' ')
        {
           sp++;
           nSpc++;
        }
        if(ch[i]>=65 && ch[i]<=122)
        {
            if(sp==3)
                nTab++;
            sp=0;
        }


        if(ch[i]>=65 && ch[i]<=90)
            nUCh++;
        if(ch[i]>=97 && ch[i]<=122)
            nLCh++;
        if(ch[i]>=48 && ch[i]<=57)
            nN++;
    }
    printf("\nNumber of characters = %d",nCh);
    printf("\nNumber of uppercase = %d",nUCh);
    printf("\nNumber of lowercase = %d",nLCh);
    printf("\nNumber of number = %d",nN);
    printf("\nNumber of tabs = %d\n",nTab);
}

int main()
{
    char ch[]="my   Name is   Naeem123 ";
    strCount(ch);
    return 0;
}
