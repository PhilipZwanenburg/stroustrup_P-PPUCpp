#include "Simple_window.h"
#include "Graph.h"

#include <stdexcept>

using namespace Graph_lib;


int main()
try {
	Point tl {50,50};

	Simple_window win {tl,1000,800,"Canvas"};

	Vector_ref<Rectangle> vr;

	constexpr int grid_size = 100;
	constexpr int grid_num  = 8;
	for (int i = 0; i < grid_num; ++i) {
	for (int j = 0; j < grid_num; ++j) {
		vr.push_back(new Rectangle{Point{i*grid_size,j*grid_size},grid_size,grid_size});
		if (i == j) {
			vr[vr.size()-1].set_color(Color::red);
			vr[vr.size()-1].set_fill_color(Color::red);
		}
		win.attach(vr[vr.size()-1]);
	}}

	int i = 0;
	Image i0 {Point{grid_size*(2*i+2),grid_size*(2*i)},"images/fractal_fern.jpg"};
	i0.set_mask(Point{240,240},200,200);
	win.attach(i0);

	++i;
	Image i1 {Point{grid_size*(2*i+2),grid_size*(2*i)},"images/fractal_fern.jpg"};
	i1.set_mask(Point{240,240},200,200);
	win.attach(i1);

	++i;
	Image i2 {Point{grid_size*(2*i+2),grid_size*(2*i)},"images/fractal_fern.jpg"};
	i2.set_mask(Point{240,240},200,200);
	win.attach(i2);

	Image i3 {Point{0,grid_size*2},"images/fractal_fern.jpg"};
	i3.set_mask(Point{200,200},100,100);
	win.attach(i3);

if (0) { // Getting segmentation fault when calling move
	for (int i = 0; i < 5; i++) {
		i3.move(grid_size,grid_size);
		win.wait_for_button();
	}
}

	win.wait_for_button();

	return 0;
} catch (exception &e) {
	cout << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cout << "Error: unhandled exception\n";
	return 2;
}
