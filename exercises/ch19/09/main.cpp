#include <iostream>
#include <stdexcept>

using namespace std;

#include "allocator.hpp"
#include "vector.hpp"

int main()
try {
	vector::vector<double> vd(3);
	vector::print(vd);

	vector::vector<double> vd2(5);
	for (int i = 0; i < vd2.size(); ++i)
		vd2[i] = i;

	vd = vd2;
	vector::print(vd);

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
