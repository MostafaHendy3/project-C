#include "System.h"

void Admin(){
    Student * st;
    st = (Student *)malloc(sizeof (Student));
    st->name ="Sasa";
    st->id = 1000;
    st->Grade =100;
    st->age=21;
    st->gender =1;
    allRecords[0]=st;
    free(st);
    st  =NULL;
    viewStudentRecord(1000);
}
void ChooseControl(){
    printf("WelCome To Student Record System \t");

}
