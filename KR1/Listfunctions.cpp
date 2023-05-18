#include "listfunctions.h"

//������� ���������� ����� ������ ����������
void GetCorrectFaculty(int& FacultyNumber)
{
	bool isCorrectFaculty{};

	do
	{
		cout << "������� ����� ����������." << endl;
		FacultyNumber = GetUnsInt();
		//�������� ������ ���������
		if (FacultyNumber > LastFaculty)
		{
			cout << "������� ������� �������� ����������" << endl;
			continue;
		}
		else
			isCorrectFaculty = true;
	} while (!isCorrectFaculty);
	cout << endl;
}

//������� ���������� ����� ������ �����
void GetCorrectCourse(int& CourseNumber)
{
	bool isCorrectCourse{};

	do
	{
		cout << "������� ����� �����." << endl;
		CourseNumber = GetUnsInt();
		//�������� ������ �����
		if (CourseNumber > LastCourse)
		{
			cout << "������� ������� �������� �����" << endl;
			continue;
		}
		else
			isCorrectCourse = true;
	} while (!isCorrectCourse);
	cout << endl;
}

//������� ���������� ����� ���� ��������
void GetCorrectYear(int& Year)
{
	bool isCorrectFaculty{};
	do
	{
		cout << "������� ���." << endl;
		Year = GetUnsInt();
		isCorrectFaculty = true;
	} while (!isCorrectFaculty);
	cout << endl;
}

//������� �������� ������������ ������ ���������� 
bool IsFacultyMatch(Student current, int FacultyNumber)
{
	int StudentFaculty = current.GetFaculty();

	if (FacultyNumber == StudentFaculty)
		return true;
	else
		return false;
}

//������� �������� ������������ ������ �����
bool IsCourseMatch(Student current, int CourseNumber)
{
	int StudentCourse = current.GetCourse();

	if (CourseNumber == StudentCourse)
		return true;
	else
		return false;
}

//������� �������� ������������ ���� ��������
bool IsYearMatch(Student current, int Year)
{
	date StudentDate = current.GetDateOfBirth();

	if (Year <= StudentDate.GetYear())
		return true;
	else
		return false;
}

//������� ���������� ������� ��������� �� ����������
void SortByFaculty(Student* List, Student*& SortedList, int amount, int& newAmount, int FacultyNumber)
{
	newAmount = 0;
	//������� ���������� ��������� � ����� �������
	for (int i = 0; i < amount; i++) {
		if (IsFacultyMatch(List[i], FacultyNumber))
		{
			newAmount++;
		}
	}
	if (newAmount != 0) {
		//��������� ������ ��� ����� ������
		SortedList = new Student[newAmount];
		for (int i = 0, j = 0; i < amount; i++) {
			if (IsFacultyMatch(List[i], FacultyNumber)) {
				//���������� ���������������� ������� 
				SortedList[j] = List[i];
				j++;
			}
		}
	}
	else {
		cout << "�������� ������� ���������� ����������� � ������" << endl;
	}
}

//������� ���������� ������� ��������� �� ���������� � �����
void SortByFacultyAndCourse(Student* List, Student*& SortedList, int amount, int& newAmount, int FacultyNumber, int CourseNumber) {
	newAmount = 0;
	for (int i = 0; i < amount; i++) {
		//������� ���������� ��������� � ����� �������
		if ((IsFacultyMatch(List[i], FacultyNumber)) && (IsCourseMatch(List[i], CourseNumber)))
		{
			newAmount++;
		}
	}
	if (newAmount != 0) {
		//��������� ������ ��� ����� ������
		SortedList = new Student[newAmount];
		for (int i = 0, j = 0; i < amount; i++) {
			//���������� ���������������� ������� 
			if ((IsFacultyMatch(List[i], FacultyNumber)) && (IsCourseMatch(List[i], CourseNumber))) {
				SortedList[j] = List[i];
				j++;
			}
		}
	}
	else {
		cout << "�������� ������� ����������/����� ����������� � ������" << endl;
	}
}

//������� ���������� ������� ��������� ���������� ����� ��������� ����
void SortByYear(Student* List, Student*& SortedList, int amount, int& newAmount, int Year)
{
	newAmount = 0;

	for (int i = 0; i < amount; i++) {
		//������� ���������� ��������� � ����� �������
		if (IsYearMatch(List[i], Year))
		{
			newAmount++;
		}
	}
	if (newAmount != 0) {
		//��������� ������ ��� ����� ������
		SortedList = new Student[newAmount];
		for (int i = 0, j = 0; i < amount; i++) {
			//���������� ���������������� �������
			if (IsYearMatch(List[i], Year)) {
				SortedList[j] = List[i];
				j++;
			}
		}
	}
	else
		cout << "��������������� �������� ����������� � ������" << endl;
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

//������� ������� ���������� ������ � �������� � ������
void ManualInput(Student Stud_List[], int count) {
	cout << "==================================" << endl;
	Stud_List[count].SetName();
	Stud_List[count].SetDateOfBirth();
	Stud_List[count].SetAddress();
	Stud_List[count].SetPhone();
	Stud_List[count].SetFaculty();
	Stud_List[count].SetCourse();
}

//������� ���������� �������
void Push_back(Student*& List, int& amount, int number) {
	Student* newList = nullptr;
	int newAmount = amount + number;
	newList = new Student[newAmount];
	if (newList == nullptr) {
		cout << "������ ��������� ������." << endl;
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

// ������� ������� ������
void Show_List(Student* List, int amount) {
	for (int i = 0; i < amount; i++) {
		List[i].Show();
	}
}

