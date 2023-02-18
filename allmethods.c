//
// Created by mr hendy on 2/14/2023.
//
#include "allmethods.h"

Student *allRecords[classSize];
Adminpass *ad;
static int numOfStudent = 0;
void addStudentRecord(Student *st)
{
    int found = 0;
    if (numOfStudent == classSize)
    {
        printf("ClassRoom is full!!!\n");
        return;
    }
    // check if student has already registered
    for (int i = 0; i < classSize; ++i)
    {
        if (allRecords[i] != 0 || allRecords[i] != NULL)
        {
            if (allRecords[i]->id == st->id)
            {
                found = 1;
                printf("This student has already registed please try again with another id!\n");
                break;
            }
        }
    }
    // if not found ,then add
    if (found == 0)
    {
        // allRecords[numOfStudent] = st;
        // numOfStudent++;
        for (int i = 0; i < classSize; ++i)
        {
            if (allRecords[i] == 0 || allRecords[i] == NULL)
            {
                allRecords[i] = st;
                return;
            }
        }
        printf("Addetion Done corectly!.\n");
    }
}
void editStudentGrade()
{
    char *pass = malloc(10 * sizeof(char));
    printf("Enter Admin PassWord: ");
    scanf(" %[^\n]%*c", pass);
    if (strcmp(pass, ad->password) == 0)
    {
        int id, grade;
        printf("Enter Student id: ");
        scanf("%d", &id);
        for (int i = 0; i < classSize; i++)
        {
            if (allRecords[i] != 0 || allRecords[i] != NULL)
            {
                if (allRecords[i]->id == id)
                {
                    printf("Enter grade of student with id=%d new grade: ", id);
                    scanf("%d", &grade);
                    allRecords[i]->Grade = grade;
                    return;
                }
            }
        }
        printf("Student not found!");
    }
    else
    {
        printf("The password is false please try again!");
    }
}
void editAdminPassword()
{
    char *pass = (char *)malloc(strlen(ad->password) + 1);
    char *NewPass = (char *)malloc(strlen(ad->password) + 1);
    printf("Enter Admin Passwords\n");
    scanf(" %[^\n]s", pass);
    printf("admin Password at struct %s\n", ad->password);
    printf("admin Password u entered %s\n", pass);
    // getchar();
    //ad->password=NULL;
    if (strcmp(pass, ad->password) == 0)
    {
        ad->password=NULL;
        printf("Please enter new password :\n");
        scanf(" %[^\n]s", NewPass);
        printf("admin Password %s\n", NewPass);
        ad->password = NewPass;
        printf("admin Password %s\n", ad->password);
    }
    else
    {
        printf("The password is false please try again!");
    }
}
Student *readStudent()
{
    Student *st = (Student *)malloc(sizeof(Student));
    printf("Enter Name\n");
    st->name = malloc(30 * sizeof(char));
    fflush(stdin);
    fgets(st->name, 30 * sizeof(char), stdin);
    printf("Enter ID\n");
    scanf("%d", &(st->id));
    printf("Enter age\n");
    scanf("%d", &(st->age));
    readGrade:
    printf("Enter Grade range between [0,100]\n");
    scanf("%d", &(st->Grade));
    if(st->Grade >100 || st->Grade <0){
        goto readGrade;
    }
    printf("\
            Enter Gender\n\
            0-male\n\
            1-female\n");
    scanf("%d", &(st->gender));
    fflush(stdin);
    printf("Enter password: \n");
    // char *pass = (char *)malloc(strlen(ad->password) + 1);
    st->password = malloc( sizeof(char) *passwordsize);
    scanf(" %s", st->password);
    addStudentRecord(st);
    return st;
}
void viewStudentRecord(int targetId)
{
    int found = 0;
    for (int i = 0; i < classSize; ++i)
    {
        if (allRecords[i] != 0 || allRecords[i] != NULL)
        {
            if (targetId == allRecords[i]->id)
            {
                //printf("%u\n", allRecords[i]);
                printf("Name : %s", allRecords[i]->name);
                printf(", ID : %d", allRecords[i]->id);
                printf(", age : %d", allRecords[i]->age);
                printf(", Grade : %d", allRecords[i]->Grade);
                printf(", Gender : %s\n", allRecords[i]->gender == 0 ? "Male" : "Female");
                //printf(" , Password %s \n", allRecords[i]->password);
                found = 1;
                return;
            }
        }
    }
    if (found == 0)
    {
        printf("Student not Found ,Enter Valid ID\n");
    }
}
void removeStudentRecord(int id)
{
    int found = 0;
    for (int i = 0; i < classSize; ++i)
    {
        if (allRecords[i] != 0 || allRecords[i] != NULL)
        {
            if (id == allRecords[i]->id)
            {
                free(allRecords[i]);
                allRecords[i] = NULL;
                found = 1;
                numOfStudent--;
                return;
            }
        }
    }
    if (found == 0)
    {
        printf("Student not Found ,Enter Valid ID");
    }
}

void viewAllStudentRecord()
{
    for (int i = 0; i < classSize; ++i)
    {
        if (allRecords[i] != 0 || allRecords[i] != NULL)
        {
            viewStudentRecord(allRecords[i]->id);
        }
    }
}

int findPosition(int id)
{
    for (int i = 0; i < classSize; i++)
    {
        if (allRecords[i]->id == id)
        {
            return i;
        }
    }
}
void editStudentPassword(int i)
{
    printf("Please, enter your new password: \n");
    scanf(" %[^\n]s", allRecords[i]->password);
    printf("The password has been updated");
}
void editStudentName(int i)
{
    printf("Please, enter your name: \n");
    scanf(" %[^\n]s", allRecords[i]->name);
    printf("Your name has been updated");
}