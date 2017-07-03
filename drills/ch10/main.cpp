#include "std_lib_facilities.h"
#include "Geometry.h"

/*
 *	Comments:
 *
 *	Some functions in the Geometry namespace can be used without prefixing with "Geometry::" because of automatic lookup
 *	based on the function arguments being defined as part of the Geometry namespace. See the linked stackoverflow answer
 *	for an explanation. This automatic lookup can be removed by placing brackets around the function name.
 *
 *		Example:
 *			Geometry::print(vector<Geometry::Point>): Works as expected (Expected prefixing)
 *			print(vector<Geometry::Point>): Works as well     (Automatic lookup)
 *			(print)(vector<Geometry::Point>): Does not compile (Automatic lookup suppressed)
 *
 *		https://stackoverflow.com/questions/10405638/why-are-some-functions-within-a-namespace-accessible-without-the-namespace-scopi
 */

int main()
try {
	string iname {"ch10/point_data.txt"};
	ifstream ifs {iname};
	if (!ifs) error("can't open input file: ",iname);

	vector<Geometry::Point> original_points;

	while (true) {
		Geometry::Point p;
		if (!(ifs >> p))
			break;

		original_points.push_back(p);
	}

	string oname {"ch10/mydata_output.txt"};
	ofstream ofs {oname};
	if (!ofs) error("can't open output file: ",oname);

	Geometry::write(ofs,original_points);

	ofs.close();

	ifstream ifs2 {oname};

	vector<Geometry::Point> processed_points;

	Geometry::read(ifs2,processed_points);

	cout << "original_points: \n";
	Geometry::print(original_points);

	cout << "\n" << "processed_points: \n";
	Geometry::print(processed_points);
//	print(processed_points);
//	(print)(processed_points);

	bool same_points {are_equal(original_points,processed_points)};

	if (!same_points)
		cout << "Something's wrong!\n";


	return 0;
} catch (exception& e) {
	cerr << "Error: " << e.what() << '\n';

	return 1;
} catch (...) {
	cerr << "Unhandled exception.\n";
}

// 2) Read in Point data
void read_point_data(ifstream& ifs)
{

}
