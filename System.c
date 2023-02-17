#include "System.h"
static int tries = 0;
Adminpass *ad;
void Admin()
{
    for (int i = 0; i < 3 && tries < 3; i++)
    {
        char *pass = (char *)malloc(strlen(ad->password) + 1);
        printf("Enter Admin Passwords\n");
        scanf(" %[^\n]s", pass);
        if (strcmp(pass, ad->password) == 0)
        {
            while (1)
            {
                printf("Welcome ,Admin \n\
                    1. Add student record\n\
                    2. Remove student record\n\
                    3. View student record\n\
                    4. View all records\n\
                    5. Edit admin password\n\
                    6. Edit student grade\n\
                    7. Exit\
                    ");
                unsigned int choice = 3;
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    Student *std = readStudent();
                    // viewStudentRecord(std->id);
                    break;
                }
                case 2:
                {
                    printf("Enter ID to Remove\n");
                    int id = 0;
                    scanf("%d", &id);
                    removeStudentRecord(id);
                    break;
                }
                case 3:
                {
                    printf("Enter ID to View\n");
                    int id = 0;
                    scanf("%d", &id);
                    viewStudentRecord(id);
                    break;
                }
                case 4:
                    viewAllStudentRecord();
                    break;
                case 5:
                    editAdminPassword();
                    break;
                case 6:
                    editStudentGrade();
                    break;
                case 7:
                    return;
                default:
                    printf("Enter Valid Choice");
                }
            }
        }
        else
        {
            tries++;
            printf("Invalid Password\n");
        }
    }
    if (tries == 3)
    {
        printf("U run out of tries\n");
        printf("U can't Enter Admin Mode\n");
    }
    return;
}
void User(int id)
{
    int useraction = 4;
    printf("Welcome in user mode.\n");
rechoose:
    printf("Please, Choose the number for a certain action.\n"
           "1- View your record \n2- Edit your password \n3- Edit your name /n0- Exit");
    scanf("%d", &useraction);
    int i = findPosition(id);
    switch (useraction)
    {
    case 0:
        // exit();              // break
    case 1:
        viewStudentRecord(id);
        break;
    case 2:

        editStudentPassword(i);
        break;
    case 3:
        editStudentName(i);
        break;
    default:
    {
        printf("Invalid mode number. \nPlease, Enter a valid number");
        goto rechoose;
    }
    }
}
void ChooseControl()
{
    printf("WelCome To Student Record System:  \t\n");
    unsigned int choice = 3;
    while (1)
    {
        printf("\n 0 -Admin \n 1-User \n 2-Exit\n");
        scanf("%u", &choice);
        switch (choice)
        {
        case 0:
            Admin();
            break;
        case 1:
            checkmethod();
            break;
        case 2:
            return;
        default:
            printf("Enter Valid Choice");
        }
    }
}
void checkmethod()
{
    int id;
    char *pass;
    printf("Please enter your ID: \t\n");
    scanf("%d", &id);
    for (int i = 0; i < classSize; ++i)
    {
        if (allRecords[i] != 0 || allRecords[i] != NULL)
        {
            if (id == allRecords[i]->id)
            {
                int count = 0;
            re_pass:
                printf("Please enter your password: \t\n");
                scanf(" %[^\n]%*c", pass);
                if (strcmp(pass, allRecords[i]->password))
                {
                    User(id);
                }
                else
                {
                    printf("Invalid password");
                    count++;
                    if (count < 4)
                    {
                        goto re_pass;
                    }
                    else
                    {
                        break; // break
                    }
                }
            }
            else
            {
                printf("Invalid ID");
                checkmethod();
            }
        }
    }
}