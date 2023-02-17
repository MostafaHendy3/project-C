#include "stdio.h"
#include "System.h"
Adminpass *ad;
Student *allRecords[classSize];
int main()
{
    ad=(Adminpass*)malloc(sizeof(Adminpass));
    ad->password="1234";
    ChooseControl();
}