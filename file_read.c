#include<stdio.h>
int main()
{
    FILE *book;
    char ch;
    book = fopen("child.txt","r");

    if(book==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened\n");
        while(!feof(book))
        {
            ch=fgetc(book);
            printf("%c",ch);
        }
        fclose(book);
    }
    getchar();
}