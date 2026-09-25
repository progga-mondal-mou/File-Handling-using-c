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
        scanf(" %48[^\n]", student.Name);//for space soho name

        printf("New student's Age: "); 
        scanf("%d", &student.Age);

        printf("New student's department: ");
        scanf(" %19[^\n]",student.Department);

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
                printf("ID: %d\n", student.ID);
                printf("Name: %s\n", student.Name);
                printf("Age: %d\n", student.Age);
                printf("Department: %s\n", student.Department);
                found=1;
                break;
            }
        }
        if (found==0)
         {
                printf("Student not found\n");
                return;
         }
    }
    fclose(file);
}

void updateStudent(){
    struct Student Student;
    FILE *file;
    FILE *tempfile;

    int found=0;
    int searchID;

    file=fopen("student.dat","rb");

    if(file==NULL)
    {
        printf("No student record found!!!\n");
        return;
    }

    else
    {
    tempfile=fopen("temp.dat","wb");

    if(tempfile==NULL)
    {
        printf("No information to update!!!\n");
        fclose(file);
        return;
    }
    else{
        printf("Enter student ID to update:");
        scanf("%d",&searchID);

        while(fread(&Student,sizeof(struct Student),1,file)==1){
            if(searchID==Student.ID){
                printf("Student foound!!!\n");

                printf("Current Name: %s\n", Student.Name);
                printf("Current Age: %d\n", Student.Age);
                printf("Current Department: %s\n", Student.Department);

                printf("Enter information to update:\n");

                printf("Enter name to update:");
                scanf(" %48[^\n]",Student.Name);

                printf("Enter age to update:");
                scanf(" %d",&Student.Age);

                printf("Enter department to update:");
                scanf(" %19[^\n]",Student.Department);

                found=1;
            }
            fwrite(&Student,sizeof(struct Student),1,tempfile);
            }
        fclose(file);
        fclose(tempfile);

        if(found==1){
            remove("student.dat");
            rename("temp.dat","student.dat");
            printf("Updated information successfully!!!\n");
            }
        else
        {
            remove("temp.dat");
            printf("Student not found!!!\n");
            }
        }
    }   
}

void deleteStudent(){
    struct Student student;
    FILE *file;
    FILE *tempfile;
    
    int found=0;
    int deleteID;

    file=fopen("student.dat","rb");
    if(file ==NULL){
        printf("No student record found!!!\n");
        return;
    }
    
    else
    {  
        tempfile=fopen("temp.dat","wb");
        if(tempfile ==NULL){
            printf("Unable to create temp file!!!\n");
            fclose(file);
            return;
    }

        else
        {
            printf("Enter ID to delete: ");
            scanf("%d",&deleteID);

            while(fread(&student,sizeof(struct Student ),1,file)==1){
                if(deleteID==student.ID){
                    printf("Student found!!!\n");
                    printf("ID: %d\n", student.ID);
                    printf("Name: %s\n", student.Name);
                    printf("Age: %d\n", student.Age);
                    printf("Department: %s\n", student.Department);
      
                    found=1; //mille just fread
                }
                else
                {
                    fwrite(&student,sizeof(struct Student),1,tempfile);     //na mille fwrite in tempfile
                }
            }
        }

        fclose(file);
        fclose(tempfile);

        if(found ==1){
            remove("student.dat");
            rename("temp.dat","student.dat");
            printf("Deleted student successfully!!!\n");
        }
        else
        {
            remove("temp.dat");
            printf("Student not found!!!\n");
        }
    }
}

int main()
{
    addstudent();
    viewStudent();
    updateStudent();
    deleteStudent();
}
