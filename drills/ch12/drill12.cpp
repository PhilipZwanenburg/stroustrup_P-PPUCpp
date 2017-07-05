#include "Simple_window.h"
#include "Graph.h"

#include <stdexcept>

using namespace Graph_lib;

int main()
try {
	Point tl {100,100};

	// 12.7.2
	Simple_window win {tl,600,400,"Canvas"};

	// 12.7.3
	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
	win.attach(xa);

	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);

	// 12.7.4
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	win.attach(sine);

	// 12.7.5
	sine.set_color(Color::blue);

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);

	// 12.7.6
	Rectangle r {Point{200,200}, 100, 50};
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);

	poly_rect.add(Point{50,75});

	// 12.7.7
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);

	// 12.7.8
	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);

	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(20);

	// 12.7.9
	Image ii {Point{100,50},"images/fractal_fern.jpg"};
	ii.set_mask(Point{240,240},200,150);
	win.attach(ii);
//	ii.move(100,200); // Getting segmentation fault with this enabled

	// 12.7.10
	// More of the same...

	win.set_label("Canvas");
	win.wait_for_button();

	return 0;
} catch (exception &e) {
	cout << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cout << "Error: unhandled exception\n";
	return 2;
}
