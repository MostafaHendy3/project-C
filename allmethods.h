//
// Created by mr hendy on 2/13/2023.
//

#ifndef UNTITLED11_ALLMETHODS_H
#define UNTITLED11_ALLMETHODS_H
#include "struct.h"
#include "data.h"
#include <stdlib.h>
#include <string.h>

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
void readStudent2(Student *st);

#endif //UNTITLED11_ALLMETHODS_H
