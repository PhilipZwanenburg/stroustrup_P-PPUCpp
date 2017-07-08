// Skipped step 9

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;


class Person {
public:
	Person();
	Person(string n, int a);

	string name() const { return name_p; };
	int age() const { return age_p; };
private:
	string name_p;
	int age_p;
};

Person::Person(): name_p{""}, age_p{0} { }

Person::Person(string n, int a): name_p{n}, age_p{a}
{
	if (n.find_first_of(";:'\"[]*&^%$#@!") != string::npos)
		throw runtime_error("Invalid name: "+n);

	if (a<0 || a>=150)
		throw runtime_error("Invalid age");
}

istream& operator>>(istream& is, Person& p)
{
	string n;
	int a;
	char ch1, ch2, ch3;
	is >> ch1 >> n >> ch2 >> a >> ch3;
	if (!is)
		return is;
	if (ch1!='(' || ch2!=',' || ch3!=')') {
		is.clear(ios_base::failbit);
		return is;
	}

	p = Person(n,a);

	return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
	return os << "(" << p.name() << "," << p.age() << ")\n";
}

int main()
try {
	string iname {"ch15/class/person_list.txt"};
	ifstream ifs {iname};
	if (!ifs)
		throw runtime_error("can't open input file: "+iname);

	vector<Person> people;
	for (Person p; ifs >> p; )
		people.push_back(p);

	ifs.close();

	for (auto p : people)
		cout << p;

	return 0;
} catch (exception &e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: Unhandled exception.\n";
	return 2;
}
