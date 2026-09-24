#include<stdio.h>
#include <string.h>
int main()
{
    FILE *class;
    char name[50];
    int age,num,phNo;
    class = fopen("studentD.txt","w");

    if(class==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened\n");
        printf("Enter total number of student:");
        scanf("%d",&num);
       for(int i=0;i<num;i++)
        {
            getchar();
              printf("Enter name:");
              fgets(name,sizeof(name),stdin);
              name[strcspn(name, "\n")] = '\0';

              printf("Enter age:");
              scanf("%d",&age);

              printf("Enter phNo:");
              scanf("%d",&phNo);

              fprintf(class,"%s\t\t %d\t\t %d \n",name,age,phNo);
        }

       
        fclose(class);
    }

    return 0;
}