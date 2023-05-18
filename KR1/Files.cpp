#include "Files.h"

using namespace filesystem;

//������� ���������, �������� �� ������, ����������� �� �����
bool IsDataCorrect(ifstream& file)
{
	string test_string{};

	int test_int{};

	while (!file.eof())
	{
		getline(file, test_string);
		getline(file, test_string);
		getline(file, test_string);

		file >> test_int; if (file.fail()) return false; if (test_int > MaxDay) return false; file.get();
		file >> test_int; if (file.fail()) return false; if (test_int > MaxMonth) return false; file.get();
		file >> test_int; if (file.fail()) return false; file.get();

		getline(file, test_string);
		getline(file, test_string);
		getline(file, test_string);

		getline(file, test_string);
		file >> test_int; if (file.fail()) return false; if (test_int > LastFaculty) return false; file.get();
		file >> test_int; if (file.fail()) return false; if (test_int > LastCourse) return false; file.get();

	}
	//���� �� ������ �������, �� ���������� ��������� � ������ �����
	file.seekg(0, ios::beg);

	return true;
}

string CheckFile()
{
	error_code error{};

	string path{};
	bool isLoaded = false;

	ifstream file;

	do
	{
		cout << "������� ���� � �����: ";
		getline(cin, path);

		if (!ifstream(path))
		{
			cout << "��������� ���� �� ������!" << endl;
			continue;
		}

		if (!is_regular_file(path, error))
		{
			cout << "������, ������������ ����� �����!" << endl;
			continue;
		}

		file.open(path);

		if (!file)
		{
			cout << "�������� ���������. ��������� ����." << endl;
			file.close();
		}
		else if (!IsDataCorrect(file))
		{
			cout << "������ ����������." << endl;
			file.close();
		}
		else
			isLoaded = true;
	} while (!isLoaded);

	cout << "���� ������." << endl;
	file.close();

	return path;
}

void GetListFromFile(Student List[], int amount, string path)		// ������� ��������� ������ �� �����
{
	fstream file(path);
	for (int i = 0; i < amount && !file.eof(); i++)
	{
		if (List[i].IsEmpty())
		{
			List[i].SetName(file);
			List[i].SetDateOfBirth(file);
			List[i].SetAddress(file);
			List[i].SetPhone(file);
			List[i].SetFaculty(file);
			List[i].SetCourse(file);
		}
	}

	cout << "������ ��������!" << endl;

	file.close();
}

int CountStrings(string path)		// ������� ������� ���������� ����� � �����
{
	int stringsAmount{};

	ifstream file;
	file.open(path);
	string tmp{};

	while (!file.eof())
	{
		getline(file, tmp);
		stringsAmount++;
	}

	return stringsAmount;
}

void SaveToFile(Student List[], int amount) {					//������� ���������� ������ � ����
	string path = "";
	bool isDataSaved = false;
	do {
		cout << "��������� �:" << endl;
		getline(cin, path);

		if (ifstream(path)) {
			cout << "���� ��� ����������." << endl;
			cout << "[0] - ������������ ������������ ����." << endl;
			cout << "[1] - ��������� ����." << endl;
			int tryAnotherFile = GetBool();
			if (tryAnotherFile) {
				continue;
			}
		}

		ofstream myFile(path, ofstream::app);

		error_code ec{};
		if (!is_regular_file(path, ec)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			continue;
		}

		if (!myFile) {
			cout << "������ ���������. ��������� ����." << endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(path, ofstream::trunc);

		fullName outputName{};
		date outputBirthday{};
		address outputAddress{};
		string outputPhone = "";
		int outputFaculty = 0;
		int outputCource = 0;

		for (int i = 0; i < amount && !List[i].IsEmpty(); i++)
		{
			outputName = List[i].GetName();
			outputBirthday = List[i].GetDateOfBirth();
			outputAddress = List[i].GetAddress();
			outputPhone = List[i].GetPhone();
			outputFaculty = List[i].GetFaculty();
			outputCource = List[i].GetCourse();
			if (i != 0)
				myFile << endl;

			myFile << outputName.GetSurname() << endl << outputName.GetName() << endl << outputName.GetPatronymic() << endl;
			myFile << outputBirthday.GetDay() << endl << outputBirthday.GetMonth() << endl << outputBirthday.GetYear() << endl;
			myFile << outputAddress.GetCity() << endl << outputAddress.GetStreet() << endl << outputAddress.GetAppart() << endl;
			myFile << outputPhone << endl;
			myFile << outputFaculty << endl;
			myFile << outputCource;
		}

		myFile.close();
		cout << "������ ���������." << endl;
		isDataSaved = true;
	} while (!isDataSaved);
}