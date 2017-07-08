#include "Link.h"

#include <stdexcept>
#include <iostream>

Link* Link::insert(Link* n)
// insert n before this; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->succ = this;
	if (prev) prev->succ = n;
	n->prev = prev;
	prev = n;
	return n;
}

//Link* Link::add(Link* p, Link* n)
Link* Link::add(Link* n)
// insert n after this; return n
{
	throw runtime_error("Link::add not yet implemented.\n");
}

Link* Link::erase()
// remove this from the list; return successor
{
	if (this == nullptr) return nullptr;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
	return succ;
}

Link* Link::find(const string& s)
// find s in list
{
	Link* p = this;
	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}

/*
Link* Link::advance(int n) const
// move n positions in the list
{
	Link* p = this;
	if (p == nullptr) return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	} else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}
*/

void print_all(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p->value;
		if (p = p->next()) cout << ", ";
	}
	cout << " }\n";
}
