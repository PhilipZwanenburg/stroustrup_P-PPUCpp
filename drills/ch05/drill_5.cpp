#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Success! 1\n";
	cout << "Success! 2\n";
	cout << "Success" << "! 3\n";
	cout << "Success! 4" << '\n';
	string res = "7"; vector<string> v(10); v[5] = res; cout << "Success! 5\n";
	vector<int> v8(10); v8[5] = 7; if (v8[5]==7) cout << "Success! 6\n";
	bool cond = 1; if (cond) cout << "Success! 7\n"; else cout << "Fail!\n";
	bool c = false; if (!c) cout << "Success! 8\n"; else cout << "Fail!\n";
	string s = "ape"; bool c9 = "fool"<s; if (!c9) cout << "Success! 9\n";
	string s10 = "ape"; if (s10!="fool") cout << "Success! 10\n";
	string s11 = "ape"; if (s11!="fool") cout << "Success! 11\n";
	string s12 = "ape"; if (s12<"fool") cout << "Success! 12\n";
	vector<char> v13(5); for (int i=0; i<v13.size(); ++i) ; cout << "Success! 13\n";
	vector<char> v14(5); for (int i=0; i<v14.size(); ++i) ; cout << "Success! 14\n";
	string s15 = "Success! 15\n"; for (int i=0; i<s15.length(); ++i) cout << s15[i];
	if (true) cout << "Success! 16\n"; else cout << "Fail!\n";
	int x = 2000; int c17 {x}; if (c17==2000) cout << "Success! 17\n";
	string s18 = "Success! 18\n"; for (int i=0; i<s18.length(); ++i) cout << s18[i];
	vector<int> v19(5); for (int i=0; i<v19.size(); ++i) ; cout << "Success! 19\n";
	int i=0; int j = 9; while (i<10) ++i; if (j<i) cout << "Success! 20\n";
	int x21 = 2; double d = 5.0/(x21-2); if (!(d==2*x21+0.5)) cout << "Success! 21\n";
	string s22 = "Success! 22\n"; for (int i=0; i<=s22.length(); ++i) cout << s22[i];
	int i23=0; while (i23<10) ++i23; int j23 = 9; if (j23<i23) cout << "Success! 23\n";
	int x24 = 4; double d24 = 5.0/(x24-2); if (d24!=2*x24+0.5) cout << "Success! 24\n";
	cout << "Success! 25\n";

	return 0;
} catch (exception &e) {
	cerr << "error: " << e.what() << "\n";
	return 1;
} catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}
