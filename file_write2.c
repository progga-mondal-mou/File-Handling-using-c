#include<stdio.h>
int main()
{
    FILE *parents;
    char address[50];
    parents = fopen("child.txt","a");

    if(parents==NULL)
    {
        printf("file does not existed");
    }
    else
    {
        printf("file is opened\n");
        printf("Enter address\n");
        gets(address);

        fputs(address,parents);
        fputs("\n",parents);
        fclose(parents);
    }
    getchar();

    return 0;
}