#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter your first name and age in years\n";
	string first_name {"???"};
	double age {-1.0};
	cin >> first_name >> age;
	cout << "Hello, " << first_name << " (age " << age*12 << " (in months))\n";
	return 0;

	// Did not do the other 'Try this' exercises which seemed simple enough.
}
