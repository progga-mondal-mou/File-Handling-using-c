#include<stdio.h>
int main()
{
    FILE *book;
    book = fopen("chapter1.txt","w");

    if(book==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened");
        fclose(book);
    }
    getchar();
}