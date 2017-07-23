// Skipped steps 12-14

#include <iostream>
#include <stdexcept>
#include <vector>

#include "struct_S.hpp"

using namespace std;

int main()
try {

	S<int> s_i(1);
	S<char> s_c('a');
	S<double> s_d(1.1);
	S<vector<int>> s_v({1,2,3});

	cout << s_d.get() << '\n';

	for (auto vi = s_v.get().begin(); vi != s_v.get().end(); ++vi)
		cout << *vi << " ";
	cout << '\n';

	cout << s_d.get() << '\n';

	s_d.set(2.2);
	cout << s_d.get() << '\n';

	s_d = 3.3;
	cout << s_d.get() << '\n';

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
