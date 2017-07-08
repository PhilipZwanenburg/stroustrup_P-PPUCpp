#include <iostream>
#include <vector>

using namespace std;


void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << a[i] << ", ";
	os << '\n';
}

void print_vector(ostream& os, vector<int> a)
{
	for (auto a_i : a)
		os << a_i << ", ";
	os << '\n';
}

int main()
try {
//#define PZWAN_INT
#define PZWAN_VEC
#ifdef PZWAN_INT
	cout << "Int*\n\n";
	int* a = new int[10],
	   * b = new int[11],
	   * c = new int[20];

	for (int i = 0; i < 20; ++i) {
		if (i < 10)
			a[i] = 100+i;
		if (i < 11)
			b[i] = 100+i;
		c[i] = 100+i;
	}

	print_array(cout,a,10);
	print_array(cout,b,11);
	print_array(cout,c,20);

	delete[] a;
	delete[] b;
	delete[] c;
#else
	cout << "Vector\n\n";
	vector<int> a(10),
	            b(11),
	            c(20);

	for (int i = 0; i < 20; ++i) {
		if (i < 10)
			a[i] = 100+i;
		if (i < 11)
			b[i] = 100+i;
		c[i] = 100+i;
	}

	print_vector(cout,a);
	print_vector(cout,b);
	print_vector(cout,c);
#endif

	return 0;
} catch (exception &e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: Unhandled exception.\n";
	return 2;
}
