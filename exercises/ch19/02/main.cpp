#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename T, typename U>
T sum_tu(vector<T>& vt, const vector<U>& vu)
// Note: There is a logic error in the specification of the return type...
{
	if (vt.size() != vu.size())
		throw out_of_range("size mismatch");

	T sum = 0;
	for (size_t i = 0; i < vt.size(); ++i)
		sum += vt[i]*vu[i];

	return sum;
}

int main()
try {
	vector<double> a {1.1, 2.2, 3.03};
	vector<int>    b {2, 3, 4};

	double sum = sum_tu(a,b);
	cout << sum << '\n';

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
