#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename T>
void f(vector<T>& v1, const vector<T>& v2)
{
	if (v1.size() != v2.size())
		throw out_of_range("size mismatch");

	for (size_t i = 0; i < v1.size(); ++i)
		v1[i] += v2[i];
}

int main()
try {
	vector<double> a {1.1, 2.2, 3.3},
	               b {2.1, 3.2, 4.3};

	f(a,b);

	for (size_t i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << '\n';

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
