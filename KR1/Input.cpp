#include "Input.h"
using namespace std;

//Создание шаблона с параметром типа Т
template<typename T>
T GetInput() {
	T userInput;
	cin >> userInput;
	while (cin.fail()) {										//cin.fail() - определяет соответствует ли введеное значение значению, определенному в переменной
		cout << "Повторите ввод." << endl;
		cin.clear();											//Сброс ошибки
		cin.ignore(INT_MAX, '\n');								//Извлечение символов из входного потока, извлеченные символы не используются
		cin >> userInput;
	}
	cin.ignore(INT_MAX, '\n');
	return userInput;
}


int GetInt() {
	return GetInput<int>();
}

SecondMenu SecondMenuChoice()
{
	return static_cast<SecondMenu>(GetInt());
}

bool GetBool() {
	return GetInput<bool>();
}

int GetUnsInt() {
	int input = GetInput<int>();
	if (input < 0) {
		cout << "Взято значение по модулю." << endl;
		input = abs(input);
	}
	return input;
}
