//
// Created by mr hendy on 2/14/2023.
//

#include "allmethods.h"
Student * allRecords[classSize];
void viewStudentRecord(int id){
    int found =0;
    for (int i = 0; i < classSize; ++i) {
        if(allRecords[i]!=0|| allRecords[i]!=NULL){
            if(id == allRecords[i]->id){
                printf("Name : %s",allRecords[i]->name);
                printf(", ID : %d",allRecords[i]->id);
                printf(", age : %d",allRecords[i]->age);
                printf(", Grade : %d",allRecords[i]->Grade);
                printf(", Gender : %s",allRecords[i]->gender==1?"Male":"Female");
                found =1;
            }
        }
    }
    if(found==0){
        printf("Student not Found ,Enter Valid ID");
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