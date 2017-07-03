#include "../../std_lib_facilities.h"

int main()
{
	int part {7};

	// Part 1
	cout << "Enter the name of the person you want to write to:\n";
	string first_name {""};
	cin >> first_name;

	// Part 2

	// Part 3
	cout << "Please enter the name of another friend:\n";
	string friend_name = {""};
	cin >> friend_name;

	// Part 4
	char friend_gender {'0'};
	cout << "Please enter the gender of the friend ('m' or 'f')\n";
	cin >> friend_gender;


	// Part 5
	int age {-1};

	cout << "Please enter the age of the recipient:\n";
	cin >> age;

	if (age <= 0 || age >= 110)
		simple_error("you're kidding!");

	// Part 6

	// Part 7


	// Output
	if (part >= 1)
		cout << "\n\nDear " << first_name << ",\n";
	if (part >= 2)
		cout << "\tLong time no speak. Lots of monkeys. More monkeys. Too many monkeys? ";
	if (part >= 3)
		cout << "Have you seen " << friend_name << " lately? ";
	if (part >= 4) {
		cout << "If you see " << friend_name << " please ask";
		if (friend_gender == 'm')
			cout << " him";
		else if (friend_gender == 'f')
			cout << " her";
		else
			cout << " them (unusual gender)";

		cout << " to call me. ";
	}
	if (part >= 5)
		cout << "I hear you just had a birthday and you are " << age << " years old. ";
	if (part >= 6) {
		if (age < 12)
			cout << "Next year you will be " << age+1 << ". ";
		else if (age == 17)
			cout << "Next year you will be able to vote. ";
		else if (age > 70)
			cout << "I hope you are enjoying retirement. ";
	}

	if (part >= 7)
		cout << "\n\nYours sincerely,\n\n\nPhilip\n";

	return 0;
}
