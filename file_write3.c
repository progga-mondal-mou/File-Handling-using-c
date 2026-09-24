#include<stdio.h>
#include<string.h>

int main()
{
    FILE *school;
    char name[20];
    int age;

    school = fopen("student.txt","r");

    if(school==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened\n");
        printf("Enter Student Name: ");
        fgets(name,sizeof(name),stdin);
        printf("\n");

        printf("Enter Age :");
        scanf("%d",&age);
        fprintf(school,"%s %d",name,age);
        fclose(school);
    }
    getchar();

    return 0;
}