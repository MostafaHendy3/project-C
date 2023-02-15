//
// Created by mr hendy on 2/13/2023.
//

#ifndef UNTITLED11_ALLMETHODS_H
#define UNTITLED11_ALLMETHODS_H
#include "struct.h"
#include "data.h"
char* Adminpassword="1234";
//1 aya
void addStudentRecord(Student *st);
void editStudentGrade();
void editAdminPassword();

//2 salma
void removeStudentRecord(int id);
void editStudentPassword();
void editStudentName();

//3 me
void viewStudentRecord(int id);
void viewAllStudentRecord();
Student * readStudent();

#endif //UNTITLED11_ALLMETHODS_H
