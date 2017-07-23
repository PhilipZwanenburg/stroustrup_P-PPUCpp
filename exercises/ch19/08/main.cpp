#include <iostream>
#include <stdexcept>

using namespace std;

#include "allocator.hpp"
#include "vector.hpp"

int main()
try {
	vector::vector<double> vd(3);

	vector::print(vd);

	vd.push_back(1.0);

	cout << vd.capacity() << '\n';
	vector::print(vd);

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
