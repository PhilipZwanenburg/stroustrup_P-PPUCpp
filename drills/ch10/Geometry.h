#ifndef PZwan_Geometry_h
#define PZwan_Geometry_h

#include "std_lib_facilities.h"

namespace Geometry {


struct Point {
	double x, y;

	Point();
	Point(double xx, double yy);

	void print() const;
};

bool operator==(Point const &a, Point const &b);
bool operator!=(Point const &a, Point const &b);

istream& operator>>(istream& is, Point& p);

void print(vector<Point> const &points);
void write(ofstream& ofs, vector<Point> const &points);
void read(ifstream& ifs, vector<Point> &points);
bool are_equal(vector<Point> const &a, vector<Point> const &b);


} // Geometry

#endif
