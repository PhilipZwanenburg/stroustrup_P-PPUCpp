#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;


vector<int> gv {1,2,4,8,16,32,64,128,256,512};

void print_iv(vector<int> iv)
{
	for (int i = 0; i < iv.size(); ++i)
		cout << iv[i] << " ";
	cout << '\n';
}

void f(vector<int> ia)
{
	vector<int> lv(ia.size());
	lv = gv;

	print_iv(lv);

	vector<int> lv2 = ia;
	print_iv(lv2);
}

vector<int> factorial(int n)
{
	vector<int> v_f;

	v_f.push_back(1);
	for (int i = 1; i < n; ++i)
		v_f.push_back(v_f[i-1]*(i+1));

	return v_f;
}

int main()
try {
	f(gv);

	vector<int> vv = factorial(10);
	f(vv);

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
