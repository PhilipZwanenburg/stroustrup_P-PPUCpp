#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;


string read_input(ifstream& ifs)
{
	string name;

	string line;
	getline(ifs,line,'\0');
	for (auto c : line) {
		if (c == '!')
			break;
		name += c;
	}

	return name;
}

int main()
try {
	string iname {"ch17/8/input_string.txt"};
	ifstream ifs {iname};
	if (!ifs)
		throw runtime_error("can't open input file: "+iname);

	string name { read_input(ifs) };

	cout << "name: " << name << '\n';

	return 0;
} catch (exception& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
