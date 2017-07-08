#include "Simple_window.h"
#include "Graph.h"

#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace Graph_lib;

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) {return slope(x)+cos(x); }

int main()
try {
	constexpr int xmax = 600;
	constexpr int ymax = 600;

	constexpr int x_orig = xmax/2;
	constexpr int y_orig = ymax/2;

	Simple_window win {Point{50,50},xmax,ymax,"Function graphs"};

	constexpr int xlen = 400;
	constexpr int ylen = 400;

	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	Axis x {Axis::x,Point{x_orig-xlen/2,y_orig},xlen,xlen/x_scale,"one notch == 20"};
	Axis y {Axis::y,Point{x_orig,y_orig+ylen/2},ylen,ylen/y_scale,"one notch == 20"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);


	constexpr int r_min = -10;
	constexpr int r_max =  11;

	Point orig {x_orig,y_orig};

	Function s0 {one,r_min,r_max,orig,400,1,1};
	win.attach(s0);

	constexpr int xscale = 20;
	constexpr int yscale = 20;

	Function s1 {one,r_min,r_max,orig,400,xscale,yscale};
	win.attach(s1);

	Function s2 {slope,r_min,r_max,orig,400,xscale,yscale};
	win.attach(s2);
	Text ts2 {Point{100,380},"x/2"};
	win.attach(ts2);

	Function s3 {square,r_min,r_max,orig,400,xscale,yscale};
	win.attach(s3);

	Function s4 {cos,r_min,r_max,orig,400,xscale,yscale};
	win.attach(s4);
	s4.set_color(Color::blue);

	Function s5 {sloping_cos,r_min,r_max,orig,400,xscale,yscale};
	win.attach(s5);

	win.wait_for_button();



	return 0;
} catch (exception &e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception\n";
	return 2;
}
