#include<stdio.h>
int main()
{
    FILE *book;
    char fast_name[20];
    char last_name[20];
    int age;

    book = fopen("student.txt","r");

    if(book==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened\n");
        fscanf(book,"%s %s %d",fast_name,last_name,&age);
        printf("%s %s %d",fast_name,last_name,age);
        fclose(book);
    }
    getchar();

    return 0;
}