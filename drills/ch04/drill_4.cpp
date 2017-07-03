#include "../../std_lib_facilities.h"
#include <cfloat>

double convert_to_meters(double number, string units)
{
	if (units == "m")
		return number;
	else if (units == "cm")
		return number*0.01;
	else if (units == "ft")
		return number*0.3048;
	else if (units == "in")
		return number*0.3048/12.0;

	error("Unknown unit.");
	return -1;
}

int main()
{
	vector<double> limits_m = { DBL_MAX, DBL_MIN },
	               numbers_m;
	cout << "Please enter numbers with units (cm, in, ft, m) until you are satisfied.\n";

	int    number_entered { 0 };
	double number,
	       sum { 0.0 };
	string units;
	for (; cin >> number >> units; ) {
		cout << "The value entered was: " << number << units << ". ";

		double number_m = convert_to_meters(number,units);
		if (number_m < limits_m[0]) {
			cout << "The smallest so far. ";
			limits_m[0] = number_m;
		}

		if (number_m > limits_m[1]) {
			cout << "The largest so far. ";
			limits_m[1] = number_m;
		}
		cout << "\n";

		sum += number_m;
		++number_entered;

		numbers_m.push_back(number_m);
	}

	sort(numbers_m);
	cout << "The numbers entered were (in meters): ";
	for (auto x : numbers_m)
		cout << x << " ";
	cout << "\n";

	return 0;
}
