#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Program to sort an structure with the help of pointers
struct student{
    char name[100];
    int marks,roll;
};
int main()
{
    struct student s[100],*p;
    p=s;
    int n,i,j,t1,t2;
    char t[100];
    printf("Enter total number of student\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter name of %d student\n",i+1);
        fflush(stdin);
        gets((p+i)->name);
        printf("Enter marks of %s student\n",(p+i)->name);
        scanf("%d",&(p+i)->marks);
        if((p+i)->marks>500 || (p+i)->marks<=0)
        {
            printf("Incorrect marks\n");
            exit(0);
        }
        printf("Enter roll no of %s student\n",(p+i)->name);
        scanf("%d",&(p+i)->roll);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((p+i)->marks==(p+j)->marks)
            {
                printf("Roll no of the students can't be the same\n");
                exit(1);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((p+i)->marks>(p+j)->marks)
            {
                t1=(p+i)->marks;
                (p+i)->marks=(p+j)->marks;
                (p+j)->marks=t1;
                t2=(p+i)->roll;
                (p+i)->roll=(p+j)->roll;
                (p+j)->roll=t2;
                strcpy(t,(p+i)->name);
                strcpy((p+i)->name,(p+j)->name);
                strcpy((p+j)->name,t);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s student is having %d marks with %d roll no\n",(p+i)->name,(p+i)->marks,(p+i)->roll);
    }

    return 0;
}