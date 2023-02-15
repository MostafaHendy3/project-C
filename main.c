#include "stdio.h"
#include "System.h"
#include "allmethods.c"
#include "struct.h"
int main()
{
    Student *s; 
    for (int i = 0; i < 2; i++)
    {
        if (i < numOfStudent)
        {
            printf("Student number %d:\n", i + 1);
            s = readStudent();
            addStudentRecord(s);
        }
    }
    viewAllStudentRecord();
}