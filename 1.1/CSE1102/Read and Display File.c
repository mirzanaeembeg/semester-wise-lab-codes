#include<stdio.h>
int main()
{
    char fname[20], str[500];
    FILE *fp;
    printf("Enter the Name of File: ");
    gets(fname);
    fp = fopen(fname, "r");
    if(fp==NULL)
        printf("Error Occurred while Opening the File!");
    else
    {
        fscanf(fp,"%[^\0]", str);
        printf("\nContent of File is:\n");
        printf("%s", str);
    }
	fclose(fp);
    return 0;
}
