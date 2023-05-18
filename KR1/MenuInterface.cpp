//#include <iostream>
#include "MenuInterface.h"



using namespace std;

void ShowMainMenu()
{
	cout << endl << "Выберите пункт меню:" << endl;
	cout << "1 - Загрузить список из файла." << endl;
	cout << "0 - Ввести список в консоль." << endl;
	cout << "Ваш выбор: ";
}

void ShowSecondMenu()
{
	cout << endl << "Выберите опцию меню:" << endl;
	cout << "1 - Показать список." << endl;
	cout << "2 - Показать список студентов заданного факультета." << endl;
	cout << "3 - Показать список студентов заданного факультета и курса." << endl;
	cout << "4 - Показать список студентов, родившихся после заданного года." << endl;
	cout << "5 - Добавить студента." << endl;
	cout << "6 - Сохранить список в файл." << endl;
	cout << "7 - Закрыть программу." << endl;
	cout << "Ваш выбор: ";
}

void Show_Save_Menu(Student* List, int amount) {
	cout << "Сохранить список в файл?" << endl
		<< "1 - ДА		0 - НЕТ" << endl;
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
		cout << "Загруженно студентов: " << students_amount << endl;

		Stud_List = new Student[students_amount];

		if (Stud_List == nullptr)
		{
			cout << "Ошибка выделения памяти." << endl;
			return EXIT_FAILURE;
		}

		GetListFromFile(Stud_List, students_amount, file_path);
	}
	else {
		cout << "Введите число студентов: ";
		students_amount = GetUnsInt();
		Stud_List = new Student[students_amount];
		if (Stud_List == nullptr)
		{
			cout << "Ошибка выделения памяти." << endl;
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
				cout << "Список пуст." << endl;

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
			else cout << "Список пуст." << endl;
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
				cout << "Список пуст." << endl;
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
				cout << "Список пуст." << endl;
			break;

		case Modify_List:
			cout << "Введите количество, которое нужно добавить:";
			number = GetUnsInt();
			Push_back(Stud_List, students_amount, number);
			Show_Save_Menu(Stud_List, students_amount);
			break;
		case Save:
			SaveToFile(Stud_List, students_amount);
			break;
		case QUIT:
			cout << "Завершение программы." << endl;
			break;
		default:
			cout << "Такого пункта меню нет." << endl << endl;
			break;
		}
	} while (UserChoise2 != QUIT);

	cout << "Освобождение памяти..." << endl;
	delete[] Stud_List;
	Stud_List = nullptr;
	delete[] Sorted_List;
	Sorted_List = nullptr;

	return EXIT_SUCCESS;
}
