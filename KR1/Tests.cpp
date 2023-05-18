#include "Tests.h"

#define test_amount 5     
#define result_faculty_amount 2
#define result_facultyAndCourse_amount 2
#define result_year_amount 3
#define test_faculty 2
#define test_course 2
#define test_year 2001


bool TestSortByFaculty()
{
	Student test_arr[test_amount];
	Student result_arr[result_faculty_amount];
	Student* sorted_arr = nullptr;
	int sorted_amount = 0;

	test_arr[0].Set("A", "Aa", "Aaa", 1, 1, 1, "a", "aa", "aaa", "8888", 1, 1);
	test_arr[1].Set("B", "Bb", "Bbb", 2, 2, 2, "b", "bb", "bbb", "8999", 2, 2);
	test_arr[2].Set("C", "Cc", "Ccc", 3, 3, 3, "c", "cc", "ccc", "8989", 3, 3);
	test_arr[3].Set("D", "Dd", "Ddd", 4, 4, 4, "d", "dd", "ddd", "8787", 2, 4);
	test_arr[4].Set("E", "Ee", "Eee", 5, 5, 5, "e", "ee", "eee", "8978", 4, 1);

	result_arr[0].Set("B", "Bb", "Bbb", 2, 2, 2, "b", "bb", "bbb", "8999", 2, 2);
	result_arr[1].Set("D", "Dd", "Ddd", 4, 4, 4, "d", "dd", "ddd", "8787", 2, 4);

	SortByFaculty(test_arr, sorted_arr, test_amount, sorted_amount, test_faculty);


	for (int i = 0; i < sorted_amount; i++)
	{
		if (sorted_arr[i] == result_arr[i])
			continue;
		else
			return false;
	}
	delete[] sorted_arr;
	sorted_arr = nullptr;
	return true;
}


bool TestSortByFacultyAndCourse()
{
	Student test_arr[test_amount];
	Student result_arr[result_facultyAndCourse_amount];
	Student* sorted_arr = nullptr;
	int sorted_amount = 0;

	test_arr[0].Set("A", "Aa", "Aaa", 1, 1, 1, "a", "aa", "aaa", "8888", 1, 1);
	test_arr[1].Set("B", "Bb", "Bbb", 2, 2, 2, "b", "bb", "bbb", "8999", 2, 2);
	test_arr[2].Set("C", "Cc", "Ccc", 3, 3, 3, "c", "cc", "ccc", "8989", 3, 3);
	test_arr[3].Set("D", "Dd", "Ddd", 4, 4, 4, "d", "dd", "ddd", "8787", 2, 4);
	test_arr[4].Set("E", "Ee", "Eee", 5, 5, 5, "e", "ee", "eee", "8978", 2, 2);

	result_arr[0].Set("B", "Bb", "Bbb", 2, 2, 2, "b", "bb", "bbb", "8999", 2, 2);
	result_arr[1].Set("E", "Ee", "Eee", 5, 5, 5, "e", "ee", "eee", "8978", 2, 2);

	SortByFacultyAndCourse(test_arr, sorted_arr, test_amount, sorted_amount, test_faculty, test_course);


	for (int i = 0; i < sorted_amount; i++)
	{
		if (sorted_arr[i] == result_arr[i])
			continue;
		else
			return false;
	}
	delete[] sorted_arr;
	sorted_arr = nullptr;
	return true;
}

bool TestSortByYear()
{
	Student test_arr[test_amount];
	Student result_arr[result_year_amount];
	Student* sorted_arr = nullptr;
	int sorted_amount = 0;

	test_arr[0].Set("A", "Aa", "Aaa", 1, 1, 1999, "a", "aa", "aaa", "8888", 1, 1);
	test_arr[1].Set("B", "Bb", "Bbb", 2, 2, 2000, "b", "bb", "bbb", "8999", 2, 2);
	test_arr[2].Set("C", "Cc", "Ccc", 3, 3, 2001, "c", "cc", "ccc", "8989", 3, 3);
	test_arr[3].Set("D", "Dd", "Ddd", 4, 4, 2002, "d", "dd", "ddd", "8787", 2, 4);
	test_arr[4].Set("E", "Ee", "Eee", 5, 5, 2003, "e", "ee", "eee", "8978", 2, 2);

	result_arr[0].Set("C", "Cc", "Ccc", 3, 3, 2001, "c", "cc", "ccc", "8989", 3, 3);
	result_arr[1].Set("D", "Dd", "Ddd", 4, 4, 2002, "d", "dd", "ddd", "8787", 2, 4);
	result_arr[2].Set("E", "Ee", "Eee", 5, 5, 2003, "e", "ee", "eee", "8978", 2, 2);

	SortByYear(test_arr, sorted_arr, test_amount, sorted_amount, test_year);


	for (int i = 0; i < sorted_amount; i++)
	{
		if (sorted_arr[i] == result_arr[i])
			continue;
		else
			return false;
	}
	delete[] sorted_arr;
	sorted_arr = nullptr;
	return true;
}