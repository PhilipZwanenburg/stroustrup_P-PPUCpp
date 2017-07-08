#include <iostream>
#include <cmath> // Note: math library linked by default with gcc

using namespace std;


int main()
try {
	cout << "Testing cmath.\n";
	cout << "cos(1.0) = " << std::cos(1.0) << '\n';

	return 0;
} catch (...) {
	cerr << "Error: Unhandled exception.\n";
}
