#include<stdio.h>
int main()
{
   FILE *fp;
   char ch, fname[30];
   int noOfChar=0, noOfSpace=0, noOfTab=0, noOfNewline=0;
   int noOfVowel=0, noOfConsonant=0, noOfNumber=0;
   printf("Enter file name with extension: ");
   gets(fname);
   fp = fopen(fname, "r");
   while(fp)
   {
      ch = fgetc(fp);
      if(ch==EOF)
         break;
      noOfChar++;
      if(ch>=65 && ch<=90)
      {
         noOfConsonant++;
         if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            noOfVowel++;
      }
      if(ch>=97 && ch<=122)
      {
         noOfConsonant++;
         if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            noOfVowel++;
      }
      if(ch>=48 && ch<=57)
         noOfNumber++;
      if(ch==' ')
         noOfSpace++;
      if(ch=='\t')
         noOfTab++;
      if(ch=='\n')
         noOfNewline++;
   }
   fclose(fp);
   printf("\nTotal Number of Characters = %d", noOfChar);
   printf("\nTotal Number of Spaces = %d", noOfSpace);
   printf("\nTotal Number of Tabs = %d", noOfTab);
   printf("\nTotal Number NewLines = %d", noOfNewline);
   printf("\nTotal Number Vowels = %d", noOfVowel);
   printf("\nTotal Number of Consonants = %d", noOfConsonant);
   printf("\nTotal Number of Numbers = %d", noOfNumber);
   return 0;
}
