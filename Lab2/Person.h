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
	string name;    // �������
	string position;// ������� � ������� ����
	double salary;  // �������� �����
	double premium; // �����
	double rate;    // ������
	void SetRate();
};
