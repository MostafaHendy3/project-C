#include "System.h"

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
    printf("Admin");
    
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
