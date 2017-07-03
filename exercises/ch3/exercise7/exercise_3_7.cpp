#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter 3 strings\n";
	vector<string> input_names;
	for (auto i = 0; i < 3; i++) {
		string current_name;
		cin >> current_name;
		input_names.push_back(current_name);
	}

	sort(input_names.begin(),input_names.end());

	for (auto i = 0; i < input_names.size(); i++) {
		cout << input_names.at(i);

		if (i < input_names.size()-1)
			cout << ", ";
		else
			cout << "\n";
	}

	return 0;
}
