#include "std_lib_facilities.h"
#include <climits>

int main()
try {
	cout << "Please enter the number of Fibonacci numbers to be computed:\n";

	int N { 0 };
	cin >> N;

	if (N == 0) throw std::invalid_argument( "Invalid input (main)." );

	cout << "The first " << N << " Fibonacci numbers are:\n";
	int n0 {1}, n1 {1};
	for (int n = 0; n < N; n++) {
		cout << "Fib[" << n << "] = " << n0 << "\n";

		int n2 = n0+n1;
		n0 = n1;
		n1 = n2;

		if (n1 < n0) throw std::out_of_range( "Integer overflow detected (main)." );
	}

	return 0;
} catch (const std::invalid_argument &e) {
	cout << "invalid_argument error: " << e.what() << "\n";
} catch (const std::out_of_range &e) {
	cout << "out_of_range error: " << e.what() << "\n";
} catch (...) {
	cout << "error: unhandled exception.\n";
}
