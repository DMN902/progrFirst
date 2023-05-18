#pragma once
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include "Class.h"

using namespace std;

bool IsDataCorrect(ifstream& file);
string CheckFile();
void GetListFromFile(Student List[], int amount, string path = CheckFile());
int CountStrings(string path);
void SaveToFile(Student List[], int amount);