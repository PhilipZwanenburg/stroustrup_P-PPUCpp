#include <iostream>
#include <cmath>

using namespace std;


int main()
try {
	cout << "Testing cmath.\n";
	cout << "cos(1.0) = " << std::cos(1.0);

	return 0;
} catch (...) {
	cerr << "Error: Unhandled exception.\n";
}
