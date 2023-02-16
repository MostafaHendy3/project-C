#include "stdio.h"
#include "System.h"
char * Adminpassword;
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
    Adminpassword =(char*) malloc( 10*sizeof(char));
    strcpy(Adminpassword,"1234");
    ChooseControl();
}