#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main()
try {
	int* p1 = new int {7};

	cout << "p1 = " << p1 << ", *p1 = " << *p1 << '\n';

	int* p2 = new int[7] {1,2,4,8,16,32,64};

	cout << "p2 = " << p2;
	for (int i = 0; i < 7; ++i)
		cout << ", p2[" << i << "] = " << p2[i];
	cout << '\n';

	int* p3 = p2;
	p2 = p1;
	p2 = p3; // Not really achieving anything here... Did I miss something?

	cout << "p1 = " << p1 << ", *p1 = " << *p1 << '\n';
	cout << "p2 = " << p2 << ", *p2 = " << *p2 << '\n';

	delete   p1;
	delete[] p2;


	p1 = new int[10];
	p2 = new int[10];
	for (int i = 0; i < 10; ++i) {
		p1[i] = int(pow(2,i));
		p2[i] = p1[i];
	}

	delete[] p1;
	delete[] p2;

	vector<int> v1(10);
	for (int i = 0; i < 10; ++i)
		v1[i] = int(pow(2,i));

	vector<int> v2 = v1;

	return 0;
} catch (exception &e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: Unhandled exception.\n";
	return 2;
}
