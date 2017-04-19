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
	if(position == "Спеціаліст")
		rate = 100;
	else if(position == "Спеціаліст 1 категорії")
		rate = 120;
	else if (position == "Спеціаліст 2 категорії")
		rate = 140;
	else if (position == "Спеціаліст вищої категорії")
		rate = 200;
	else if (position == "Начальник відділу")
		rate = 300;
	else if (position == "Директор")
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
