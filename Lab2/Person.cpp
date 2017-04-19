#include "Person.h"

Person::Person()
{
	name = "name";
	position = "position";
}

Person::Person(string aName, string aPosition)
{
	name = aName;
	position = aPosition;

	SetRate();
}

string Person::GetName()
{
	return name;
}

string Person::GetPosition()
{
	return position;
}

double Person::GetRate()
{
	return rate;
}

double Person::GetPremium()
{
	return premium;
}

double Person::GetSalary()
{
	return salary;
}

void Person::SetRate()
{
	if(position == "���������")
		rate = 100;
	else if(position == "��������� 1 �������")
		rate = 120;
	else if (position == "��������� 2 �������")
		rate = 140;
	else if (position == "��������� ���� �������")
		rate = 200;
	else if (position == "��������� �����")
		rate = 300;
	else if (position == "��������")
		rate = 450;
	else rate = 0;
}

void Person::SetSalary(double avarage)
{
	if (rate < avarage)
		premium = rate*0.5;
	else
		premium = rate*0.3;

	salary = rate + premium;
}

Person::~Person()
{
}
