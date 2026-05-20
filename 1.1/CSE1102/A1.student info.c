#include <stdio.h>
int main ()
       {
           int rnum, phone;
           char name;
           double mark;
           printf("Enter student name's first later:\n");
           scanf("%c", &name);
           printf("Enter roll number:\n");
           scanf("%d", &rnum);
           printf("Enter phone number:\n");
           scanf("%d", &phone);
           printf("Enter marks:\n");
           scanf("%lf", &mark);
           printf("Student info:\n");
           printf("Name: %c\n", name);
           printf("roll number: %d\n", rnum);
           printf("phone number: %d\n", phone);
           printf("marks: %lf\n", mark);
           return 0;
       }
