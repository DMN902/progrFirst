//#include <iostream>
#include "MenuInterface.h"



using namespace std;

void ShowMainMenu()
{
	cout << endl << "�������� ����� ����:" << endl;
	cout << "1 - ��������� ������ �� �����." << endl;
	cout << "0 - ������ ������ � �������." << endl;
	cout << "��� �����: ";
}

void ShowSecondMenu()
{
	cout << endl << "�������� ����� ����:" << endl;
	cout << "1 - �������� ������." << endl;
	cout << "2 - �������� ������ ��������� ��������� ����������." << endl;
	cout << "3 - �������� ������ ��������� ��������� ���������� � �����." << endl;
	cout << "4 - �������� ������ ���������, ���������� ����� ��������� ����." << endl;
	cout << "5 - �������� ��������." << endl;
	cout << "6 - ��������� ������ � ����." << endl;
	cout << "7 - ������� ���������." << endl;
	cout << "��� �����: ";
}

void Show_Save_Menu(Student* List, int amount) {
	cout << "��������� ������ � ����?" << endl
		<< "1 - ��		0 - ���" << endl;
	if (GetBool()) {
		SaveToFile(List, amount);
	}
}

int StartProgram() {
	int students_amount = 0;
	int sorted_amount = 0;
	int number = 0;
	int inFaculty = 0;
	int inCourse = 0;
	int inYear = 0;
	Student* Stud_List = nullptr;
	Student* Sorted_List = nullptr;
	string file_path = "";
	/////////////////////////////////////////////////////////////////
	ShowMainMenu();
	if (GetBool()) {
		file_path = CheckFile();
		students_amount = CountStrings(file_path) / 12;
		cout << "���������� ���������: " << students_amount << endl;

		Stud_List = new Student[students_amount];

		if (Stud_List == nullptr)
		{
			cout << "������ ��������� ������." << endl;
			return EXIT_FAILURE;
		}

		GetListFromFile(Stud_List, students_amount, file_path);
	}
	else {
		cout << "������� ����� ���������: ";
		students_amount = GetUnsInt();
		Stud_List = new Student[students_amount];
		if (Stud_List == nullptr)
		{
			cout << "������ ��������� ������." << endl;
			return EXIT_FAILURE;
		}
		for (int i = 0; i < students_amount; i++)
		{
			ManualInput(Stud_List, i);
		}
		Show_Save_Menu(Stud_List, students_amount);
	}
	SecondMenu UserChoise2 = static_cast<SecondMenu>(0);
	do
	{
		ShowSecondMenu();
		UserChoise2 = SecondMenuChoice();

		switch (UserChoise2)
		{
		case ShowList:
			if (!IsListEmpty(Stud_List, students_amount))
				Show_List(Stud_List, students_amount);
			else
				cout << "������ ����." << endl;

			break;

		case List_Faculty:
			if (!IsListEmpty(Stud_List, students_amount)) {
				if (Sorted_List != nullptr) {
					delete[] Sorted_List;
					Sorted_List = nullptr;
				}
				GetCorrectFaculty(inFaculty);
				SortByFaculty(Stud_List, Sorted_List, students_amount, sorted_amount, inFaculty);
				if (sorted_amount != 0) {
					Show_List(Sorted_List, sorted_amount);
					Show_Save_Menu(Sorted_List, sorted_amount);
				}
			}
			else cout << "������ ����." << endl;
			break;

		case List_FacultyAndCourse:
			if (!IsListEmpty(Stud_List, students_amount)) {
				if (Sorted_List != nullptr) {
					delete[] Sorted_List;
					Sorted_List = nullptr;
				}
				GetCorrectFaculty(inFaculty);
				GetCorrectCourse(inCourse);
				SortByFacultyAndCourse(Stud_List, Sorted_List, students_amount, sorted_amount, inFaculty, inCourse);
				if (sorted_amount != 0) {
					Show_List(Sorted_List, sorted_amount);
					Show_Save_Menu(Sorted_List, sorted_amount);
				}
			}
			else
				cout << "������ ����." << endl;
			break;

		case List_Year:
			if (!IsListEmpty(Stud_List, students_amount)) {
				if (Sorted_List != nullptr) {
					delete[] Sorted_List;
					Sorted_List = nullptr;
				}
				GetCorrectYear(inYear);
				SortByYear(Stud_List, Sorted_List, students_amount, sorted_amount, inYear);
				if (sorted_amount != 0) {
					Show_List(Sorted_List, sorted_amount);
					Show_Save_Menu(Sorted_List, sorted_amount);
				}
			}
			else
				cout << "������ ����." << endl;
			break;

		case Modify_List:
			cout << "������� ����������, ������� ����� ��������:";
			number = GetUnsInt();
			Push_back(Stud_List, students_amount, number);
			Show_Save_Menu(Stud_List, students_amount);
			break;
		case Save:
			SaveToFile(Stud_List, students_amount);
			break;
		case QUIT:
			cout << "���������� ���������." << endl;
			break;
		default:
			cout << "������ ������ ���� ���." << endl << endl;
			break;
		}
	} while (UserChoise2 != QUIT);

	cout << "������������ ������..." << endl;
	delete[] Stud_List;
	Stud_List = nullptr;
	delete[] Sorted_List;
	Sorted_List = nullptr;

	return EXIT_SUCCESS;
}
