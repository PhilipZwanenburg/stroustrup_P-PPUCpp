#include "Geometry.h"

#include "std_lib_facilities.h"

namespace Geometry {

Point::Point() : x{0.0}, y{0.0} {}
Point::Point(double xx, double yy) : x{xx}, y{yy} {}

void Point::print() const
{
	cout << "( " << x << " , " << y << " )" << '\n';
}

bool operator==(Point const &a, Point const &b)
{
	if (a.x==b.x && a.y==b.y)
		return true;
	return false;
}

bool operator!=(Point const &a, Point const &b)
{
	return !(a==b);
}

istream& operator>>(istream& is, Point& p)
// read a point from is into p
// format: ( 1.0 1.0 )
{
	char ch1;
	is >> ch1;
	if (ch1!='(') {
		// Provide an opportunity for recovery in calling function if the first character is invalid.
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	char ch2;
	vector<double> points(2,0.0);
	is >> points[0] >> points[1] >> ch2;
	if (!is || ch2!=')') error("bad point");

	p.x = points[0];
	p.y = points[1];
	return is;
}

void print(vector<Point> const &points)
{
	for (auto const &p : points)
		p.print();
}

void write(ofstream &ofs, vector<Point> const &points)
{
	for (auto const &p : points)
		ofs << "( " << p.x << " " << p.y << " )" << '\n';
}


void read(ifstream& ifs, vector<Point>& points)
{
	while (true) {
		Geometry::Point p;
		if (!(ifs >> p))
			break;

		points.push_back(p);
	}
}

bool are_equal(vector<Point> const &a, vector<Point> const &b)
{
	if (a.size() != b.size())
		return false;

	for (auto i = 0; i < a.size(); ++i)
		if (a[i] != b[i])
			return false;

	return true;
}


} // Geometry
