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
void viewAllStudentRecord(){
    for (int i = 0; i <classSize ; ++i) {
        viewStudentRecord(allRecords[i]->id);
    }
}