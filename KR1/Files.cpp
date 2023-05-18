#include "Files.h"

using namespace filesystem;

//Функция проверяет, подходят ли данные, загруженные из файла
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
	//Если всё прошло успешно, то возвращает указатель в начало файла
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
		cout << "Введите путь к файлу: ";
		getline(cin, path);

		if (!ifstream(path))
		{
			cout << "Указанный файл не найден!" << endl;
			continue;
		}

		if (!is_regular_file(path, error))
		{
			cout << "Ошибка, недопустимый адрес файла!" << endl;
			continue;
		}

		file.open(path);

		if (!file)
		{
			cout << "Загрузка запрещена. Повторите ввод." << endl;
			file.close();
		}
		else if (!IsDataCorrect(file))
		{
			cout << "Данные повреждены." << endl;
			file.close();
		}
		else
			isLoaded = true;
	} while (!isLoaded);

	cout << "Файл открыт." << endl;
	file.close();

	return path;
}

void GetListFromFile(Student List[], int amount, string path)		// Функция заполняет массив из файла
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

	cout << "Список загружен!" << endl;

	file.close();
}

int CountStrings(string path)		// Функция считает количество строк в файле
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

void SaveToFile(Student List[], int amount) {					//Функция записывает массив в файл
	string path = "";
	bool isDataSaved = false;
	do {
		cout << "Сохранить в:" << endl;
		getline(cin, path);

		if (ifstream(path)) {
			cout << "Файл уже существует." << endl;
			cout << "[0] - Перезаписать существующий файл." << endl;
			cout << "[1] - Повторить ввод." << endl;
			int tryAnotherFile = GetBool();
			if (tryAnotherFile) {
				continue;
			}
		}

		ofstream myFile(path, ofstream::app);

		error_code ec{};
		if (!is_regular_file(path, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
			continue;
		}

		if (!myFile) {
			cout << "Запись запрещена. Повторите ввод." << endl;
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
		cout << "Запись завершена." << endl;
		isDataSaved = true;
	} while (!isDataSaved);
}