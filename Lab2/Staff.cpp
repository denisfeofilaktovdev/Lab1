#include "Staff.h"

Staff::Staff()
{
	count = 0;
	func = &Person::SetSalary;
	avarage = 0;
	finance = 0;
	staff = nullptr;
}

Staff::~Staff()
{
	count > 1 ? delete[] staff : delete staff;
}

void Staff::AddPerson(Person* aPerson)
{
	if (count == 0)
	{
		staff = new Person[1];
		staff = aPerson;
	}
	else
	{
		Person* tmp;
		tmp = staff;

		staff = new Person[count + 1];

		for (int i = 0; i < count; i++)
			*(staff + i) = *(tmp + i);

		*(staff + count) = *aPerson;

		count > 1 ? delete[] tmp : delete tmp;
	}

	finance += (staff + count)->GetRate();
	count++;
}

string Staff::GetAllData()
{
	string text = "Ініціали - Позиція - Ставка - Премія - З.П.\n";

	for (int i = 0; i < count; i++)
		text += (staff + i)->GetName() + " | " +
			    (staff + i)->GetPosition() + " | " +
	  to_string((int)(staff + i)->GetRate()) + " | " +
	  to_string((int)(staff + i)->GetPremium()) + " | " +
	  to_string((int)(staff + i)->GetSalary()) + "\n";

	return text;

}

void Staff::CalculateAll()
{
	for (int i = 0; i < count; i++)
	{
		((staff + i)->*func)(finance / count);
	}
}
