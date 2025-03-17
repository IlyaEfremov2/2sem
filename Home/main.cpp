#include<string>
#include<iostream>
#include "Person.h"
using namespace std;

int main()
{
	Person package = Person("Lagutin", "Vladimir", "Sergeevich");
	package.Show();
	package.ShowFormal();

	return 0;
}