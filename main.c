#include "stdio.h"
#include "System.h"

int main()
{
    // Student *s; 
    // for (int i = 0; i < 2; i++)
    // {
    //     if (i < numOfStudent)
    //     {
    //         printf("Student number %d:\n", i + 1);
    //         s = readStudent();
    //         addStudentRecord(s);
    //     }
    // }
    // viewAllStudentRecord();
    while (1){
        unsigned int choice =3;
        printf("Enter\n \
        0-Admin\n\
        1-user\n\
        2-Exit\n\
        ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            Admin();
            break;
        
        default:
            break;
        }
    }
}