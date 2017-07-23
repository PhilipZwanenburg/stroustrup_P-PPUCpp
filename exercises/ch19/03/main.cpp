#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename T, typename U>
class Pair {
public:
	Pair(T t, U u) : name{t}, value{u} {};

	T n() const { return name;  };
	U v() const { return value; };
private:
	T name;
	U value;
};

int main()
try {
	vector<Pair<string,double>> variables({{"a",1.0},{"b",2.2}});

	variables.push_back({"c",3.0});

	cout << variables.size() << '\n';

	for (auto vi = variables.begin(); vi != variables.end(); ++vi)
		cout << "{ " << vi->n() << ", " << vi->v() << " }\n";

	return 0;
} catch (exception& e) {
	cerr << "Error, caught exception: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
