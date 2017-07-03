// Identical to drill_9_4.cpp as const member functions were already used, Chrono namespace defined in external files.

#include "std_lib_facilities.h"
#include "Chrono.h"

int main()
try {
	Chrono::Date today {1978, Chrono::Month::jun, 25},
	             tomorrow {today};
	tomorrow.add_day(1);

	cout << "Today: " << today << '\n';
	cout << "Tomorrow: " << tomorrow << '\n';

	Chrono::Date test_invalid_d {1978, Chrono::Month::dec, 35};

	return 0;
} catch (Chrono::Date::Invalid_Date) {
	cout << "Invalid date entered.\n";
	return 1;
} catch (...) {
	cout << "Unhandled error.\n";
	return 2;
}
