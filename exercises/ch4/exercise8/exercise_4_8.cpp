#include "std_lib_facilities.h"

void output_ngrains(int const sq, string const num_string)
{
	cout << sq << " squares are required for the inventor to receive " << num_string << " grains of rice.\n";
}

int main()
{
	vector<int> entered (3, 0);

	int    n_grains   = 1;
	double n_grains_d = 1.0;
	for (int sq = 1; sq <= 64; sq++) {

		int index = 0;
		if (!entered[index] && n_grains >= 1e3) {
			entered[index] = 1;
			output_ngrains(sq,"one thousand");
		}

		index = 1;
		if (!entered[index] && n_grains >= 1e6) {
			entered[index] = 1;
			output_ngrains(sq,"one million ");
		}

		index = 2;
		if (!entered[index] && n_grains >= 1e9) {
			entered[index] = 1;
			output_ngrains(sq,"one billion ");
		}

		cout << "The inventor asked for (" << n_grains << ", " << n_grains_d << ") grains";
		cout << " for " << sq << " squares.\n";

		n_grains *= 2;
		n_grains_d *= 2;
	}

	return 0;
}
