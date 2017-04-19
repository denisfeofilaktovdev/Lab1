#pragma once
#include "Person.h"

class Staff
{
public:
	Staff();
	~Staff();
	void AddPerson(Person*);
	void CalculateAll();
	string GetAllData();

private:
	Person* staff;
	void (Person::*func)(double);
	int count;
	double avarage;
	double finance;
};
