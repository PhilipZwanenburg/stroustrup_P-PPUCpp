#include <iostream>
#include <stdexcept>
#include <string>

#include "Link.h"

using namespace std;



int main()
try {
	Link* norse_gods = new Link{"Thor"};
	norse_gods = norse_gods->insert(new Link{"Odin"});
	norse_gods = norse_gods->insert(new Link{"Zeus"});
	norse_gods = norse_gods->insert(new Link{"Freia"});

	Link* greek_gods = new Link{"Hera"};
	greek_gods = greek_gods->insert(new Link{"Athena"});
	greek_gods = greek_gods->insert(new Link{"Mars"});
	greek_gods = greek_gods->insert(new Link{"Poseidon"});

	// Correct a name
	Link* p = greek_gods->find("Mars");
	if (p)
		p->value = "Ares";

	// Move object from one list to the other
	Link* p2 = norse_gods->find("Zeus");
	if (p2) {
		if (p2 == norse_gods) norse_gods = p2->next();
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}


	print_all(norse_gods);
	print_all(greek_gods);


	return 0;
} catch (exception& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cerr << "Error: unhandled exception.\n";
	return 2;
}
