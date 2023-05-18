#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Input.h"

using namespace std;

////////////////////////////////////////////////////////////
//		класс дата (день, мес€ц, год)
class date {
private:
	int day = 0,
		month = 0,
		year = 0;
public:
	void SetDay();
	void SetMonth();
	void SetYear();
	void Set(int day_, int month_, int year_);
	void SetDay(istream& input);
	void SetMonth(istream& input);
	void SetYear(istream& input);

	int GetDay();
	int GetMonth();
	int GetYear();

	bool operator == (const date& dateB) const
	{
		return this->day == dateB.day
			&& this->month == dateB.month
			&& this->year == dateB.year;
	}

	bool operator != (const date& dateB) const
	{
		return !(*this == dateB);
	}
};
////////////////////////////////////////////////////////////
//		класс полное им€ (им€, фамили€, отчество)
class fullName {
private:
	string name = "",
		surname = "",
		patronymic = "";
public:
	void SetName();
	void SetSurname();
	void SetPatronymic();
	void Set(string surname_, string name_, string patronymic_);
	void SetName(istream& input);
	void SetSurname(istream& input);
	void SetPatronymic(istream& input);
	string GetName();
	string GetSurname();
	string GetPatronymic();
	bool operator == (const fullName& nameB) const
	{
		return this->surname == nameB.surname
			&& this->name == nameB.name
			&& this->patronymic == nameB.patronymic;
	}

	bool operator != (const fullName& nameB) const
	{
		return !(*this == nameB);
	}

};
////////////////////////////////////////////////////////////
//		класс адресс (город, улица, дом)
class address {
private:
	string	city = "",
		street = "",
		apart = "";
public:
	void SetCity();
	void SetStreet();
	void SetAppart();
	void Set(string city_, string street_, string apart_);
	void SetCity(istream& input);
	void SetStreet(istream& input);
	void SetAppart(istream& input);
	string GetCity();
	string GetStreet();
	string GetAppart();
	bool operator == (const address& addressB) const
	{
		return this->city == addressB.city
			&& this->street == addressB.street
			&& this->apart == addressB.apart;
	}

	bool operator != (const address& addressB) const
	{
		return !(*this == addressB);
	}
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		класс студент (‘амили€, »м€, отчество, дата рождени€, адресс, номер телефона, номер факультета, номер курса)
class Student {
private:
	fullName Name{};
	date DateOfBirth{};
	address Address{};
	string Phone = "";
	int Faculty = 0;
	int Course = 0;
public:
	void SetName();
	void SetDateOfBirth();
	void SetAddress();
	void SetPhone();
	void SetFaculty();
	void SetCourse();
	void Set(string surname_, string name_, string patronymic_, int day, int month_, int year_, string city_, string street_, string apart_, string phone_, int faculty_, int course_);

	void SetName(istream& input);
	void SetDateOfBirth(istream& input);
	void SetAddress(istream& input);
	void SetPhone(istream& input);
	void SetFaculty(istream& input);
	void SetCourse(istream& input);

	fullName GetName();
	date GetDateOfBirth();
	address GetAddress();
	string GetPhone();
	int GetFaculty();
	int GetCourse();

	bool IsEmpty();
	void Show();

	bool operator == (const Student& studentB) const
	{
		return this->Name == studentB.Name
			&& this->DateOfBirth == studentB.DateOfBirth
			&& this->Address == studentB.Address
			&& this->Phone == studentB.Phone
			&& this->Faculty == studentB.Faculty
			&& this->Course == studentB.Course;
	}

	bool operator != (const Student& studentB) const
	{
		return !(*this == studentB);
	}

};