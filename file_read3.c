#include<stdio.h>
int main()
{
    FILE *book;
    char name[20];

    book = fopen("student.txt","r");

    if(book==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened\n");
        while(!feof(book))
        {
        fgets(name,19,book);
        printf("%s\n",name);
        }
        
        fclose(book);
    }
    getchar();

    return 0;
}