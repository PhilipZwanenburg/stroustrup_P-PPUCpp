#include "std_lib_facilities.h"

namespace chrono {

/*enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};*/

struct Date {
	class Invalid_Date{};

	int y, m, d;

	Date(int yy, int mm, int dd);
};

Date::Date(int yy, int mm, int dd)
	: y{yy}, m{mm}, d{dd}
{
	if (mm < 1 || mm > 12) throw Invalid_Date{};
	if (dd < 1 || dd > 31) throw Invalid_Date{};
}

void add_day(Date& d)
{
	// Obviously needs improvement for more complicated days
	(d.d)++;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

}


int main()
try {
	chrono::Date today {1978, 6, 25},
	             tomorrow {today};
	chrono::add_day(tomorrow);

	cout << "Today: " << today << '\n';
	cout << "Tomorrow: " << tomorrow << '\n';

	chrono::Date test_invalid_m {1978, 13, 25};
	chrono::Date test_invalid_d {1978, 12, 35};

	return 0;
} catch (chrono::Date::Invalid_Date) {
	cout << "Invalid date entered.\n";
	return -1;
} catch (...) {
	cout << "Unhandled error.\n";
}
