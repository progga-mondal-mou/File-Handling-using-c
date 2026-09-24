#include<stdio.h>
#include<string.h>
int main()
{
    FILE *class;
    char name[20]="Mondal ";
    int length=strlen(name);
    
    class=fopen("section.txt","a");

    if(class ==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened/n");
        for(int i=0;i<length;i++)
        {
           fputc(name[i],class);
        }
        fclose(class);
    }
    
}