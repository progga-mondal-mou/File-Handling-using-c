#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    int ID;
    char Name[49];
    int Age;
    char Department[20];
};

void addstudent(){
    struct Student student;
    FILE * file;
    file=fopen("student.dat","ab"); // append + binary mode
    
    if(file==NULL)
    {
        printf("File does not existed!!!\n");
        return;
    }
    else
    {
        printf("Add new student's data:\n");
        
        printf("New student's ID: ");
        scanf("%d", &student.ID);//for struct

        printf("New student's name: ");
        scanf(" %[^\n]", student.Name);//for space soho name

        printf("New student's Age: "); 
        scanf("%d", &student.Age);

        printf("New student's department: ");
        scanf(" %[^\n]",student.Department);

        fwrite(&student,sizeof(struct Student),1,file);//dat file er jonno,txtte fprintf
        
        printf("New student's data entered successfully \n"); 
    }
    fclose(file);
}

void viewStudent(){
    struct Student student;
    FILE * file;
    file=fopen("student.dat","rb"); 
    
    if(file==NULL)
    {
        printf("File has no record!!!\n");
        return;
    }
    else
    {
        printf("=======STUDENT'S  RECORDS=====\n");
        while(fread(&student,sizeof(struct Student),1,file)==1)
        {
            printf("\n ID: %d",student.ID);
            printf("\n Name: %s",student.Name);
            printf("\n Age:%d",student.Age);
            printf("\n Department: %s",student.Department);
        }
    }
    fclose(file);
}


void searchStudent(){
    struct Student student;
    FILE * file;
    int searchID;
    int found=0;
    file =fopen("student.dat","rb");

    if(file==NULL)
    {
        printf("File has no record!!!\n");
        return;
    }
    else
    {
        printf("Enter search id:");
        scanf("%d",&searchID);

        while(fread(&student,sizeof(struct Student),1,file)==1){
            if(searchID==student.ID){
                printf("Student found\n");
                found=1;
                break;
            }
            if (found==0)
            {
                printf("Student not found\n");
                return;
            }
        }
    }
    fclose(file);
}

int main()
{
    addstudent();
    viewStudent();
}
