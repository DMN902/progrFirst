#include "listfunctions.h"

//Функция коррекного ввода номера факультета
void GetCorrectFaculty(int& FacultyNumber)
{
	bool isCorrectFaculty{};

	do
	{
		cout << "Введите номер факультета." << endl;
		FacultyNumber = GetUnsInt();
		//Проверка номера факултета
		if (FacultyNumber > LastFaculty)
		{
			cout << "Слишком большое значение факультета" << endl;
			continue;
		}
		else
			isCorrectFaculty = true;
	} while (!isCorrectFaculty);
	cout << endl;
}

//Функция коррекного ввода номера курса
void GetCorrectCourse(int& CourseNumber)
{
	bool isCorrectCourse{};

	do
	{
		cout << "Введите номер курса." << endl;
		CourseNumber = GetUnsInt();
		//Проверка номера курса
		if (CourseNumber > LastCourse)
		{
			cout << "Слишком большое значение курса" << endl;
			continue;
		}
		else
			isCorrectCourse = true;
	} while (!isCorrectCourse);
	cout << endl;
}

//Функция коррекного ввода года рождения
void GetCorrectYear(int& Year)
{
	bool isCorrectFaculty{};
	do
	{
		cout << "Введите год." << endl;
		Year = GetUnsInt();
		isCorrectFaculty = true;
	} while (!isCorrectFaculty);
	cout << endl;
}

//Функция проверки соответствия номера факультета 
bool IsFacultyMatch(Student current, int FacultyNumber)
{
	int StudentFaculty = current.GetFaculty();

	if (FacultyNumber == StudentFaculty)
		return true;
	else
		return false;
}

//Функция проверки соответствия номера курса
bool IsCourseMatch(Student current, int CourseNumber)
{
	int StudentCourse = current.GetCourse();

	if (CourseNumber == StudentCourse)
		return true;
	else
		return false;
}

//Функция проверки соответствия года рождения
bool IsYearMatch(Student current, int Year)
{
	date StudentDate = current.GetDateOfBirth();

	if (Year <= StudentDate.GetYear())
		return true;
	else
		return false;
}

//Функция сортировки массива студентов по факультету
void SortByFaculty(Student* List, Student*& SortedList, int amount, int& newAmount, int FacultyNumber)
{
	newAmount = 0;
	//Подсчет количества студентов в новом массиве
	for (int i = 0; i < amount; i++) {
		if (IsFacultyMatch(List[i], FacultyNumber))
		{
			newAmount++;
		}
	}
	if (newAmount != 0) {
		//Выделение памяти под новый массив
		SortedList = new Student[newAmount];
		for (int i = 0, j = 0; i < amount; i++) {
			if (IsFacultyMatch(List[i], FacultyNumber)) {
				//Заполнение отсортированного массива 
				SortedList[j] = List[i];
				j++;
			}
		}
	}
	else {
		cout << "Студенты данного факультета отсутствуют в списке" << endl;
	}
}

//Функция сортировки массива студентов по факультету и курсу
void SortByFacultyAndCourse(Student* List, Student*& SortedList, int amount, int& newAmount, int FacultyNumber, int CourseNumber) {
	newAmount = 0;
	for (int i = 0; i < amount; i++) {
		//Подсчет количества студентов в новом массиве
		if ((IsFacultyMatch(List[i], FacultyNumber)) && (IsCourseMatch(List[i], CourseNumber)))
		{
			newAmount++;
		}
	}
	if (newAmount != 0) {
		//Выделение памяти под новый массив
		SortedList = new Student[newAmount];
		for (int i = 0, j = 0; i < amount; i++) {
			//Заполнение отсортированного массива 
			if ((IsFacultyMatch(List[i], FacultyNumber)) && (IsCourseMatch(List[i], CourseNumber))) {
				SortedList[j] = List[i];
				j++;
			}
		}
	}
	else {
		cout << "Студенты данного факультета/курса отсутствуют в списке" << endl;
	}
}

//Функция сортировки массива студентов родившихся после заданного года
void SortByYear(Student* List, Student*& SortedList, int amount, int& newAmount, int Year)
{
	newAmount = 0;

	for (int i = 0; i < amount; i++) {
		//Подсчет количества студентов в новом массиве
		if (IsYearMatch(List[i], Year))
		{
			newAmount++;
		}
	}
	if (newAmount != 0) {
		//Выделение памяти под новый массив
		SortedList = new Student[newAmount];
		for (int i = 0, j = 0; i < amount; i++) {
			//Заполнение отсортированного массива
			if (IsYearMatch(List[i], Year)) {
				SortedList[j] = List[i];
				j++;
			}
		}
	}
	else
		cout << "Соответствующие студенты отсутствуют в списке" << endl;
}


bool IsListEmpty(Student List[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (!List[i].IsEmpty())
			return false;
	}
	return true;
}

//Функция ручного заполнения данных о студенте в массив
void ManualInput(Student Stud_List[], int count) {
	cout << "==================================" << endl;
	Stud_List[count].SetName();
	Stud_List[count].SetDateOfBirth();
	Stud_List[count].SetAddress();
	Stud_List[count].SetPhone();
	Stud_List[count].SetFaculty();
	Stud_List[count].SetCourse();
}

//Функция увеличения массива
void Push_back(Student*& List, int& amount, int number) {
	Student* newList = nullptr;
	int newAmount = amount + number;
	newList = new Student[newAmount];
	if (newList == nullptr) {
		cout << "Ошибка выделения памяти." << endl;
	}
	for (int i = 0; i < newAmount; i++) {
		if (i < amount) {
			newList[i] = List[i];
		}
		else {
			ManualInput(newList, i);
		}
	}
	amount = newAmount;
	delete[] List;
	List = newList;
	newList = nullptr;
}

// Функция выводит массив
void Show_List(Student* List, int amount) {
	for (int i = 0; i < amount; i++) {
		List[i].Show();
	}
}

