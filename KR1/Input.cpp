#include "Input.h"
using namespace std;

//�������� ������� � ���������� ���� �
template<typename T>
T GetInput() {
	T userInput;
	cin >> userInput;
	while (cin.fail()) {										//cin.fail() - ���������� ������������� �� �������� �������� ��������, ������������� � ����������
		cout << "��������� ����." << endl;
		cin.clear();											//����� ������
		cin.ignore(INT_MAX, '\n');								//���������� �������� �� �������� ������, ����������� ������� �� ������������
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
		cout << "����� �������� �� ������." << endl;
		input = abs(input);
	}
	return input;
}
