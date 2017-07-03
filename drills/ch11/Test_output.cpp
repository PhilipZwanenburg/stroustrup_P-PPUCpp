#include "std_lib_facilities.h"

constexpr int current_year = 2017;

int main()
{
	// Steps 1-7
	int birth_year = 1991;

	cout << "Outputting birth_year in various formats.\n"
	     << showbase
	     << "Decimal:     \t" << dec << birth_year << '\n'
	     << "Octal:       \t" << oct << birth_year << '\n'
	     << "Hexadecimal: \t" << hex << birth_year << '\n';
	cout << "My current age is: " << dec << current_year-birth_year << '\n';

	// Step 8
	string iname {"ch11/input_values.txt"};
	ifstream ifs {iname};
	if (!ifs) error("can't open input file: ",iname);

	int a, b, c, d;
	ifs >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;

	// The values were read in as dec, oct and hex respectively and are then being output as dec.

	// Step 9
	double output9 {1234567.89};
	cout << defaultfloat << output9 << '\n'
	     << fixed << output9 << '\n'
	     << scientific << output9 << '\n';

	// Step 10 (skipped)
}
