//
// Created by mr hendy on 2/14/2023.
//
#include "stdio.h"
#include "allmethods.h"
Student *allRecords[classSize];
static int numOfStudent = 0;
void addStudentRecord(Student *st)
{
    int found = 0;
    if (numOfStudent == classSize)
    {
        printf("ClassRoom is full!!!\n");
        return;
    }
    for (int i = 0; i < numOfStudent; ++i)
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
    if (found == 0)
    {
        allRecords[numOfStudent] = st;
        numOfStudent++;
        printf("Addetion Done corectly!.\n");
    }
    else
    {
        printf("Current Class are full you can't add another student to it.\n");
    }
}
void editStudentGrade()
{
    char* pass;
    printf("Enter Admin PassWord: ");
    scanf(" %[^\n]%*c", pass);
    if (pass == Adminpassword)
    {
        int id, grade;
        printf("Enter Student id: ");
        scanf("%d", &id);
        for (int i = 0; i < numOfStudent; i++)
        {
            if (allRecords[i] != 0 || allRecords[i] != NULL)
            {
                if (allRecords[i]->id == id)
                {
                    printf("Enter grade of student with id=%d new grade: ",id);
                    grade = scanf("%d", &grade);
                    allRecords[i]->Grade=grade;
                    return;
                }
            }
        }
        printf("Student not found!");
    }else{
        printf("The password is false please try again!");
    }
}
void editAdminPassword(){
    char* pass;
    printf("Enter Admin PassWord: ");
    scanf(" %[^\n]%*c", pass);
    if (pass == Adminpassword)
    {
        printf("Please enter new password : ");
        Adminpassword=scanf(" %[^\n]%*c", pass);

    }else{
        printf("The password is false please try again!");
    }
}
Student *readStudent()
{
    Student *st;
    st = (Student *)malloc(sizeof(Student));
    
    printf("Enter Name\n");
    scanf(" %[^\n]s", st->name);
    printf("Enter ID\n");
    scanf("%d", &(st->id));
    printf("Enter age\n");
    scanf("%d", &(st->age));
    printf("Enter Grade\n");
    scanf("%d", &(st->Grade));
    printf("Enter Gender\n");
    scanf("%d", &(st->gender));
    printf("Enter passwordn\n");
    scanf(" %[^\n]%*c", st->password);
    // printf("%p\n",st);
    return st;
}
void viewStudentRecord(int id)
{
    int found = 0;
    for (int i = 0; i < classSize; ++i)
    {
        if (allRecords[i] != 0 || allRecords[i] != NULL)
        {
            if (id == allRecords[i]->id)
            {
                printf("Name : %s", allRecords[i]->name);
                printf(", ID : %d", allRecords[i]->id);
                printf(", age : %d", allRecords[i]->age);
                printf(", Grade : %d", allRecords[i]->Grade);
                printf(", Gender : %s\n", allRecords[i]->gender == 1 ? "Male" : "Female");
                found = 1;
            }
        }
    }
    if (found == 0)
    {
        printf("Student not Found ,Enter Valid ID\n");
    }
}


Student * readStudent(){
        Student * st;
        st = (Student *)malloc(sizeof (Student));
        printf("Enter Name\n");
        scanf(" %[^\n]s", st->name);
        printf("%s",st->name);
        printf("Enter ID\n");
        scanf("%d",&(st->id));
        printf("Enter age\n");
        scanf("%d",&(st->age));
        printf("Enter Grade\n");
        scanf("%d",&(st->Grade));
        printf("Enter Gender\n");
        scanf("%d",&(st->gender));
        printf("Enter passwordn\n");
        scanf(" %[^\n]%*c", st->name);
        //printf("%p\n",st);

        
        return st;
}
void viewAllStudentRecord(){
    for (int i = 0; i <classSize ; ++i) {
        viewStudentRecord(allRecords[i]->id);
    }
}

void removeStudentRecord(int id){
   int found =0;
    for (int i = 0; i < classSize; ++i) {
        if(allRecords[i]!=0|| allRecords[i]!=NULL){
            if(id == allRecords[i]->id){
               allRecords[i]->name = NULL;
               allRecords[i]->id = 0;
               allRecords[i]->age = 0;
               allRecords[i]->Grade = 0;
               allRecords[i]->gender = 0;
               allRecords[i]->password = NULL;
            printf("All data has been cleared");
                found =1;
            }
        }
    }
    if(found==0){
        printf("Student not Found ,Enter Valid ID");
    }
}

void editStudentPassword(){
            printf("Please, enter your new password: \n");
            gets(allRecords[i]->password);
            printf("The password has been updated");
            }


void editStudentname(){
            printf("Please, enter your name: \n");
            gets(allRecords[i]->name);
            printf("Your name has been updated");
            }


