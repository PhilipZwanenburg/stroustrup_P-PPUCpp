#include <iostream>
#include <stdexcept>

using namespace std;

int main()
try {
	/*
	 *	Guesses for sizes:
	 *		int    : 4 bytes (32 bit integers)
	 *		double : 8 bytes (64 bit doubles)
	 *		bool   : equivalent to an int?
	 *
	 *	Correct answers:
	 *		guesses for sizeof int and double were correct.
	 *		sizeof(bool) is implementation defined and is not guaranteed to be 1 (as it was using gcc 5.4.0).
	 *
	 *	References
	 *		sizeof(bool) : https://stackoverflow.com/questions/4897844/is-sizeofbool-defined
	 */

	cout << "sizeof(int)    : " << sizeof(int)    << '\n'
	     << "sizeof(double) : " << sizeof(double) << '\n'
	     << "sizeof(bool)   : " << sizeof(bool)   << '\n';

	return 0;
} catch (exception& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
