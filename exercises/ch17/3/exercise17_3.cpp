#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void to_lower(char* s)
{
	constexpr char diff = 'A'-'a';
	do {
		if (*s>='A' && *s<='Z')
			*s -= diff;
	} while (*++s);
}

void print_c_str(char *s)
{
	string a {s};
	cout << a << '\n';
}

int main()
try {
	char a[] {"Hello, World!"};

	print_c_str(a);
	to_lower(a);
	print_c_str(a);

	return 0;
} catch (exception& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
