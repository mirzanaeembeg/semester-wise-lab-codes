#include <stdio.h>
int main ()
       {
           int rnum;
           float mPhy,mChe,mHm,mEng,mBio,total,avg;
           char n;
           printf("Enter student name's first later:\n");
           scanf("%c", &n);
           printf("Enter roll number:\n");
           scanf("%d", &rnum);
           printf("Enter marks in 5 subject:\n");
           printf("Number in Physics:\n");
           scanf("%f", &mPhy);
           printf("Number in Chemistry:\n");
           scanf("%f", &mChe);
           printf("Number in Higher math:\n");
           scanf("%f", &mHm);
           printf("Number in English:\n");
           scanf("%f", &mEng);
           printf("Number in Biology:\n");
           scanf("%f", &mBio);
                total=mPhy+mChe+mHm+mEng+mBio;
                avg=total/5;
           printf("Student info:\n");
           printf("Name: %c\n", n);
           printf("roll number: %d\n", rnum);
           printf("Number in\nPhysics %f\nChemistry %f\nHigher math %f\nEnglish %f\nBiology %f\n",mPhy,mChe,mHm,mEng,mBio);
           printf("Total number:%f",total);
           printf("\nAverage number:%f",avg);
           return 0;
       }

