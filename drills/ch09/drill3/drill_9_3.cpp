#include "std_lib_facilities.h"

namespace chrono {

/*enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};*/

class Date {
	int y, m, d;
public:
	class Invalid_Date{};

	Date(int yy, int mm, int dd);

	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }

	void add_day(int n);
	bool is_valid();
};

bool Date::is_valid()
{
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > 31) return false;

	return true;
}

Date::Date(int yy, int mm, int dd)
	: y{yy}, m{mm}, d{dd}
{
	if (!is_valid()) throw Invalid_Date{};
}

void Date::add_day(int n)
{
	// Obviously needs improvement for more complicated days
	d++;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

}

int main()
try {
	chrono::Date today {1978, 6, 25},
	             tomorrow {today};
	tomorrow.add_day(1);

	cout << "Today: " << today << '\n';
	cout << "Tomorrow: " << tomorrow << '\n';

	chrono::Date test_invalid_m {1978, 13, 25};
	chrono::Date test_invalid_d {1978, 12, 35};

	return 0;
} catch (chrono::Date::Invalid_Date) {
	cout << "Invalid date entered.\n";
	return 1;
} catch (...) {
	cout << "Unhandled error.\n";
	return 2;
}
