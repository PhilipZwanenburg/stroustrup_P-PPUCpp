#include <iostream>
#include <stdexcept>

using namespace std;


int ga[10] {1,2,4,8,16,32,64,128,256,512};

void print_ia(int *ia, int n)
{
	for (int i = 0; i < n; ++i)
		cout << ia[i] << " ";
	cout << '\n';
}

void f(int* ia, int n)
{
	int la[10];

	for (int i = 0; i < 10; ++i)
		la[i] = ga[i];

	print_ia(la,10);

	int* p = new int[n];
	for (int i = 0; i < n; ++i)
		p[i] = ia[i];
	print_ia(p,10);

	delete[] p;
}

int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n*factorial(n-1);
}

int main()
try {
	f(ga,10);

	int aa[10];
	for (int i = 0; i < 10; ++i)
		aa[i] = factorial(i+1);

	f(aa,10);

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
