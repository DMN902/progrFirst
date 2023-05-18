#include <iostream>
#include <clocale>
#include "MenuInterface.h"
#include "Tests.h"

using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "Контрольная работа №1" << endl
		<< "Вариант №1" << endl
		<< "Агишев Даниил" << endl
		<< "группа 423" << endl << endl 
		<< "Задача: Разработать класс для указанной предметной области." << endl
		<< "Доступ к данным реализовать с помощью методов Set, Get, Show." <<  endl
		<< "Студент: фамилия, имя, отчество, дата рождения, адрес, телефон, факультет, курс." << endl
		<< "Создать массив объектов. Реализовать возможность получения:" << endl
		<< "- списка студентов заданного факультета," << endl
		<< "- списков студентов для каждого факультета и курса," << endl
		<< "- списка студентов, родившихся после заданного года." << endl;

	if (TestSortByFaculty() && TestSortByFacultyAndCourse() && TestSortByYear()) {
		cout << "Тесты успешно пройдены" << endl;
		StartProgram();
	}
	else {
		cout << "Тесты провалены" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
