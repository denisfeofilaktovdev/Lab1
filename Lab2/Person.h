#pragma once
#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(string, string);
	string GetName();
	string GetPosition();
	double GetRate();
	double GetSalary();
	double GetPremium();
	void SetSalary(double);
	~Person();

private:
	string name;    // ініціали
	string position;// позиція з тарифної сітки
	double salary;  // заробітня плата
	double premium; // премія
	double rate;    // ставка
	void SetRate();
};
