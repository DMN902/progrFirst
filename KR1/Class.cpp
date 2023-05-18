#include "Class.h"

////////////////////////////////////////////////////////////
//		����� ���� (����, �����, ���)	
void fullName::SetName() {
	cin >> name;
}
void fullName::SetSurname() {
	cin >> surname;
}
void fullName::SetPatronymic() {
	cin >> patronymic;
}
void fullName::Set(string surname_, string name_, string patronymic_) {
	surname = surname_;
	name = name_;
	patronymic = patronymic_;
}
void fullName::SetName(istream& input) {
	getline(input, name);
}
void fullName::SetSurname(istream& input) {
	getline(input, surname);
}
void fullName::SetPatronymic(istream& input) {
	getline(input, patronymic);
}
string fullName::GetName() {
	return name;
}
string fullName::GetSurname() {
	return surname;
}
string fullName::GetPatronymic() {
	return patronymic;
}
////////////////////////////////////////////////////////////
//		����� ������ ��� (���, �������, ��������)
void date::SetDay() {
	day = GetUnsInt();
}
void date::SetMonth() {
	month = GetUnsInt();
}
void date::SetYear() {
	year = GetUnsInt();
}
void date::Set(int day_, int month_, int year_) {
	day = day_;
	month = month_;
	year = year_;
}
int date::GetDay() {
	return day;
}
int date::GetMonth() {
	return month;
}
int date::GetYear() {
	return year;
}
void date::SetDay(istream& input) {
	input >> day; input.get();
}
void date::SetMonth(istream& input) {
	input >> month; input.get();
}
void date::SetYear(istream& input) {
	input >> year; input.get();
}
////////////////////////////////////////////////////////////
//		����� ������ (�����, �����, ���)
void address::SetCity() {
	cin >> city;
}
void address::SetStreet() {
	cin >> street;
}
void address::SetAppart() {
	cin >> apart;
}
void address::Set(string city_, string street_, string apart_) {
	city = city_;
	street = street_;
	apart = apart_;
}
void address::SetCity(istream& input) {
	getline(input, city);
}
void address::SetStreet(istream& input) {
	getline(input, street);
}
void address::SetAppart(istream& input) {
	getline(input, apart);
}
string address::GetCity() {
	return city;
}
string address::GetStreet() {
	return street;
}
string address::GetAppart() {
	return apart;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		����� ������� (�������, ���, ��������, ���� ��������, ������, ����� ��������, ����� ����������, ����� �����)
void Student::SetName() {
	cout << "�������\t\t";
	Name.SetSurname();

	cout << "���\t\t";
	Name.SetName();

	cout << "��������\t";
	Name.SetPatronymic();
}
void Student::SetDateOfBirth() {
	bool correctDay = false;
	bool correctMonth = false;
	cout << "���� ��������" << endl;
	do {
		cout << "����\t\t";
		DateOfBirth.SetDay();

		if (DateOfBirth.GetDay() > MaxDay) {
			cout << "������� ������� �����." << endl;
		}
		else correctDay = true;
	} while (!correctDay);
	do {
		cout << "�����\t\t";
		DateOfBirth.SetMonth();

		if (DateOfBirth.GetMonth() > MaxMonth) {
			cout << "������� ������� �����." << endl;
		}
		else correctMonth = true;
	} while (!correctMonth);
	cout << "���\t\t";
	DateOfBirth.SetYear();
}
void Student::SetAddress() {
	cout << "������" << endl;
	cout << "�����\t\t";
	Address.SetCity();
	cout << "�����\t\t";
	Address.SetStreet();
	cout << "���\t\t";
	Address.SetAppart();
}
void Student::SetPhone() {
	cout << "����� ��������\t";
	cin >> Phone;
}
void Student::SetFaculty() {
	bool correctFaculty = false;
	do {
		cout << "���������\t";
		Faculty = GetUnsInt();

		if (Faculty > LastFaculty) {
			cout << "������� ������� �����." << endl;
		}
		else correctFaculty = true;
	} while (!correctFaculty);
}
void Student::SetCourse() {
	bool correctCourse = false;
	do {
		cout << "����\t\t";
		Course = GetUnsInt();

		if (Course > LastCourse) {
			cout << "������� ������� �����." << endl;
		}
		else correctCourse = true;
	} while (!correctCourse);
}
void Student::Set(string surname_, string name_, string patronymic_, int day_, int month_, int year_, string city_, string street_, string apart_, string phone_, int faculty_, int course_) {
	Name.Set(surname_, name_, patronymic_);
	DateOfBirth.Set(day_, month_, year_);
	Address.Set(city_, street_, apart_);
	Phone = phone_;
	Faculty = faculty_;
	Course = course_;
}
//////////////////////////////////////////////////////////////////////
void Student::SetName(istream& input) {
	Name.SetSurname(input);
	Name.SetName(input);
	Name.SetPatronymic(input);
}
void Student::SetDateOfBirth(istream& input) {
	DateOfBirth.SetDay(input);
	DateOfBirth.SetMonth(input);
	DateOfBirth.SetYear(input);
}
void Student::SetAddress(istream& input) {
	Address.SetCity(input);
	Address.SetStreet(input);
	Address.SetAppart(input);
}
void Student::SetPhone(istream& input) {
	getline(input, Phone);
}
void Student::SetFaculty(istream& input) {
	input >> Faculty; input.get();
}
void Student::SetCourse(istream& input) {
	input >> Course; input.get();
}
//////////////////////////////////////////////////////////////////////
fullName Student::GetName() {
	return Name;
}
date Student::GetDateOfBirth() {
	return DateOfBirth;
}
address Student::GetAddress() {
	return Address;
}
string Student::GetPhone() {
	return Phone;
}
int Student::GetFaculty() {
	return Faculty;
}
int Student::GetCourse() {
	return Course;
}
//////////////////////////////////////////////////////////////////////
bool Student::IsEmpty()
{
	if (!Name.GetSurname().empty())
		return false;
	if (!Name.GetName().empty())
		return false;
	if (!Name.GetPatronymic().empty())
		return false;

	if (DateOfBirth.GetDay() != 0)
		return false;
	if (DateOfBirth.GetMonth() != 0)
		return false;
	if (DateOfBirth.GetYear() != 0)
		return false;

	if (!Address.GetCity().empty())
		return false;
	if (!Address.GetStreet().empty())
		return false;
	if (!Address.GetAppart().empty())
		return false;

	if (!Phone.empty())
		return false;
	if (Faculty != 0)
		return false;
	if (Course != 0)
		return false;

	return true;
}
//////////////////////////////////////////////////////////////////////
void Student::Show() {
	cout << "_________________________________" << endl;
	cout << Name.GetSurname() << endl;
	cout << Name.GetName() << endl;
	cout << Name.GetPatronymic() << endl << endl;
	cout << "���� ��������:\t" << DateOfBirth.GetDay() << "." << DateOfBirth.GetMonth() << "." << DateOfBirth.GetYear() << endl;
	cout << "������:\t\t" << Address.GetCity() << ", " << Address.GetStreet() << " " << Address.GetAppart() << endl;
	cout << "���������:\t" << Faculty << endl;
	cout << "����:\t\t" << Course << endl;
	cout << "_________________________________" << endl;
}

