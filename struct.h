//
// Created by mr hendy on 2/13/2023.
//

#ifndef Students
#define Students
#include "stdio.h"
#define classSize 20
typedef struct student
{
    char *name;
    int Grade;
    int id;
    int age;
    char *password;
    int gender;
} Student;
typedef struct admin
{
    char *password;
} Adminpass;

#endif
