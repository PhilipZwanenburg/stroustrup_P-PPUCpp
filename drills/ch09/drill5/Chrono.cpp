#include "std_lib_facilities.h"
#include "Chrono.h"

namespace Chrono {

Date::Date(int yy, Month mm, int dd)
	: y{yy}, m{mm}, d{dd}
{
	if (!is_valid()) throw Invalid_Date{};
}

bool Date::is_valid()
{
	if (m < Month::jan || m > Month::dec) return false;
	if (d < 1 || d > 31) return false;

	return true;
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

} // Chrono
