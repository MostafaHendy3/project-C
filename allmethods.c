//
// Created by mr hendy on 2/14/2023.
//
#include "stdio.h"
#include "allmethods.h"
Student *allRecords[classSize];
char* Adminpassword;

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
    // printf("%d\n",st->id);
    // for (int i = 0; i < classSize; i++)
    // {
    //     if(allRecords[i]==0||allRecords[i]==NULL){
    //         allRecords[i]=st;
    //         break;
    //     }
    // }
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
    
    strcpy(Adminpassword,"1234");

    char * pass=(char*) malloc(strlen(Adminpassword)+1);
    char * NewPass=(char*) malloc(strlen(Adminpassword)+1);
    printf("Enter Admin Passwords\n");
    scanf(" %[^\n]s",pass);
    //getchar();
    if (strcmp(pass,Adminpassword)==0)
        {
            
            //fflush(stdin);
        printf("Please enter new password :\n");
        scanf(" %[^\n]s", NewPass);
        strcpy(Adminpassword,NewPass);
        //printf("Enter Name\n");
        // getchar();
        //fgets(Adminpassword,10,stdin);
        // int x =0;
        // scanf("%d",&x);
        
        }
    else{
        printf("The password is false please try again!");
    }
    free(pass);
    free(NewPass);
}
Student *readStudent()
{
    Student *st=(Student *)malloc(sizeof(Student));
    printf("Enter Name\n");
    scanf(" %[^\n]s", st->name);
    printf("name : %s", st->name);
    printf("Enter ID\n");
    scanf("%d", &(st->id));
    printf("Enter age\n");
    scanf("%d", &(st->age));
    printf("Enter Grade\n");
    scanf("%d", &(st->Grade));
    printf("Enter Gender\n");
    scanf("%d", &(st->gender));
    printf("Enter passwordn\n");
    fflush(stdin);
    scanf(" %[^\n]s", st->password);
    // scanf("%c",(char *)stdin);
    // fgets(st->password,20,stdin);
    //st->password ="1111";
    // printf(", ID : %d", st->id);
    // printf(", age : %d", st->age);
    // printf(", Grade : %d", st->Grade);
    // printf(", Gender : %s\n", st->gender == 1 ? "Male" : "Female");
    //addStudentRecord(st);
    return st;
}
void readStudent2(Student *st)
{
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

void viewAllStudentRecord(){
    for (int i = 0; i <classSize ; ++i) {
        viewStudentRecord(allRecords[i]->id);
    }
}

void removeStudentRecord(int id){
   int found =0;
    for (int i = 0; i < classSize; ++i) {
        if(allRecords[i]!=0 || allRecords[i]!=NULL){
            if(id == allRecords[i]->id){
                free(allRecords[i]);
                allRecords[i]=NULL;
                found =1;
            }
        }
    }
    if(found==0){
        printf("Student not Found ,Enter Valid ID");
    }
}
int findPosition(int id){
    for (int i = 0; i < classSize; i++)
    {
        if(allRecords[i]->id==id){
            return i;
        }
    }
}
void editStudentPassword(int i){
    printf("Please, enter your new password: \n");
    gets(allRecords[i]->password);
    printf("The password has been updated");
}


void editStudentName(int i){
    printf("Please, enter your name: \n");
    gets(allRecords[i]->name);
    printf("Your name has been updated");
}
