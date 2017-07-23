#include <iostream>
#include <stdexcept>

using namespace std;

#include "File_handle.hpp"

int main()
try {
	File_handle::File_handle file("ch19/12/data.txt");

	for (string a; file.fs() >> a; )
		cout << a << '\n';

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
