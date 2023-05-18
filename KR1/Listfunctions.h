#pragma once
#include "Class.h"

void GetCorrectFaculty(int& FacultyNumber);
void GetCorrectCourse(int& CourseNumber);
void GetCorrectYear(int& Year);
//bool IsFacultyMatch(Student current, int FacultyNumber);
//bool IsCourseMatch(Student current, int CourseNumber);
//bool IsYearMatch(Student current, int Year);
void SortByFaculty(Student* List, Student*& SortedList, int amount, int& newAmount, int FacultyNumber);
void SortByFacultyAndCourse(Student* List, Student*& SortedList, int amount, int& newAmount, int FacultyNumber, int CourseNumber);
void SortByYear(Student* List, Student*& SortedList, int amount, int& newAmount, int Year);

bool IsListEmpty(Student List[], int amount);
void ManualInput(Student Stud_List[], int count);
void Push_back(Student*& List, int& amount, int number);
void Show_List(Student* List, int amount);