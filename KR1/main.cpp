#include <iostream>
#include <clocale>
#include "MenuInterface.h"
#include "Tests.h"

using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	cout << "����������� ������ �1" << endl
		<< "������� �1" << endl
		<< "������ ������" << endl
		<< "������ 423" << endl << endl 
		<< "������: ����������� ����� ��� ��������� ���������� �������." << endl
		<< "������ � ������ ����������� � ������� ������� Set, Get, Show." <<  endl
		<< "�������: �������, ���, ��������, ���� ��������, �����, �������, ���������, ����." << endl
		<< "������� ������ ��������. ����������� ����������� ���������:" << endl
		<< "- ������ ��������� ��������� ����������," << endl
		<< "- ������� ��������� ��� ������� ���������� � �����," << endl
		<< "- ������ ���������, ���������� ����� ��������� ����." << endl;

	if (TestSortByFaculty() && TestSortByFacultyAndCourse() && TestSortByYear()) {
		cout << "����� ������� ��������" << endl;
		StartProgram();
	}
	else {
		cout << "����� ���������" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
