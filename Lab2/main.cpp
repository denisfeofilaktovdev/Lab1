#include <iostream>
#include "Person.h"
#include "Staff.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void GetInfo();

Staff staff;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GetInfo();

	staff.CalculateAll();
	cout << staff.GetAllData();

	system("pause");
	return 0;
}

void GetInfo()
{
	string buffName, buffPos;

	ifstream input("data.txt");

	while(!input.eof())
	{
		getline(input, buffName, '|');
		getline(input, buffPos, '\n');

		staff.AddPerson(new Person(buffName, buffPos));
	}

	input.close();
}
