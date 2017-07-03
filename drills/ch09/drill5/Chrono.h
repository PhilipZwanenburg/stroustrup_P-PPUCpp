#ifndef PZwan_Chrono_h
#define PZwan_Chrono_h

namespace Chrono {

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

ostream& operator<<(ostream& os, const Month m);
ostream& operator<<(ostream& os, const Date& d);

} // Chrono

#endif
