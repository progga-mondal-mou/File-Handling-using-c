#include<stdio.h>
int main()
{
    int c;
    int tmp = 1;
    do{
        printf("\nSTUDENT RECORD MANAGEMENT\n");
        printf("1. Add Student\n");
        printf("2. View Student\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1:
                // addStudent();
                printf("Adding Student");
                break;
            
            case 2:
                // viewStudent();
                printf("Viewing Student");
                break;
            
            case 3:
                // searchStudent();
                printf("Searching Student");
                break;
            
            case 4:
                // updateStudent();
                printf("Updating Student");
                break;
            
            case 5:
                // deleteStudent();
                printf("Deleting Student");
                break;
    
            case 6:
                printf("Program exited successfully\n ");
                // exit(0);
                tmp = 0;
                break;
            
            default:
                printf("Invalid choice!!!");
                printf("Please try again.");
            }
    }while(tmp);
}