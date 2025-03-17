#include<string>
#include<iostream>
#include "Person.h"
using namespace std;

Person::Person()
{
	lastname = "";
	firstname = "";
	patronymic = "";
}

Person::Person(const string ln, const string& fn, const string& pn)
{
	lastname = ln;
	firstname = fn;
	patronymic = pn;
}

void Person::Show()
{
	if (patronymic == "")
	{
		cout << "LastName: " << lastname << endl;
		cout << "FirstName: " << firstname << endl << endl;
	}
}

void Person::ShowFormal()
{
	if (patronymic != "")
	{
		cout << "LastName:" << lastname << endl;
		cout << "FirstName:" << firstname << endl;
		cout << "Patronimic:" << patronymic << endl << endl;
	}
}

