#include "System.h"
static int tries =0;
void Admin(){
//    Student * st;
//    st = (Student *)malloc(sizeof (Student));
//    st->name ="my_name1";
//    st->id = 1000;
//    st->Grade =100;
//    st->age=21;
//    st->gender =1;
//    allRecords[0]=st;
//    free(st);
//    st  =NULL;
//    viewStudentRecord(1000);
    for (int i=0;i<3 && tries <3;i++){
        char * pass=(char*) malloc(strlen(Adminpassword)+1);;
        printf("Enter Admin Passwords\n");
        scanf(" %[^\n]s",pass);
        if (strcmp(pass,Adminpassword)==0)
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
            ");
            unsigned int choice=3;
            scanf("%d",&choice);
            switch (choice) {
            case 1:{
                Student* std;
                std = (Student *)malloc(sizeof(Student));
                std =readStudent();
                addStudentRecord(std);
                break;}
            case 2:{
                printf("Enter ID\n");
                int id =0;
                scanf("%d", &id);
                removeStudentRecord(id);
                break;}
            case 3:{
                printf("Enter ID\n");
                int id =0;
                scanf("%d", &id);
                viewStudentRecord(id);
                break;}
            case 4:
                viewAllStudentRecord();
                break;
            case 5:
                editAdminPassword();
                break;
            default:
                printf("Enter Valid Choice");
            }
        }
            break;
        }else{
            tries++;
            printf("Invalid Password\n");
        }
    }
    if(tries==3){
        printf("U run out of tries\n");
        printf("U can't Enter Admin Mode\n");
    }
    return;
    
}
void User(){
    printf("User");
}
void ChooseControl(){
    printf("WelCome To Student Record System:  \t\n");
    while (1){
        printf("\n 0 -Admin \n 1-User \n 2-Exit\n");
        unsigned int choice=3;
        scanf("%d",&choice);
        switch (choice) {
            case 0:
                Admin();
                break;
            case 1:
                User();
                break;
            case 2:
                break;
            default:
                printf("Enter Valid Choice");
        }
        if(choice==2){
            break;
        }
    }
}
