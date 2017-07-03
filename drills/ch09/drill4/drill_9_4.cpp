#include "std_lib_facilities.h"

namespace chrono {

enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
	int y, d;
	Month m;
public:
	class Invalid_Date{};

	Date(int yy, Month mm, int dd);

	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }

	void add_day(int n);
	bool is_valid();
};

bool Date::is_valid()
{
	if (m < Month::jan || m > Month::dec) return false;
	if (d < 1 || d > 31) return false;

	return true;
}

Date::Date(int yy, Month mm, int dd)
	: y{yy}, m{mm}, d{dd}
{
	if (!is_valid()) throw Invalid_Date{};
}

void Date::add_day(int n)
{
	// Obviously needs improvement for more complicated days
	d++;
}

ostream& operator<<(ostream& os, const Month m)
{
	// Alternate of output operator defined on p. 224.
	return os << static_cast<int>(m);
}

ostream& operator<<(ostream& os, const Date& d)
{
	// Requires that a Month output operator be defined.
	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

}

int main()
try {
	chrono::Date today {1978, chrono::Month::jun, 25},
	             tomorrow {today};
	tomorrow.add_day(1);

	cout << "Today: " << today << '\n';
	cout << "Tomorrow: " << tomorrow << '\n';

	chrono::Date test_invalid_d {1978, chrono::Month::dec, 35};

	return 0;
} catch (chrono::Date::Invalid_Date) {
	cout << "Invalid date entered.\n";
	return 1;
} catch (...) {
	cout << "Unhandled error.\n";
	return 2;
}
