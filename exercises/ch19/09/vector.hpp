/*
 *	Copied directly from 19.3.1.
 */

#include "allocator.hpp"

namespace vector {

// an almost real vector of Ts:
template<typename T, typename A = allocator<T>>
class vector { // read “for all types T” (just like in math)
	A alloc;

	int sz; // the size
	T* elem; // a pointer to the elements
	int space; // size + free space
public:
	vector() : sz{0}, elem{nullptr}, space{0} { }
	explicit vector(int s) :sz{s}, elem{new T[s]}, space{s}
	{
		for (int i=0; i<sz; ++i) elem[i]=0; // elements are initialized
	}

	vector(const vector&);            // copy constructor
	vector& operator=(const vector&); // copy assignment

	vector(vector&&);            // move constructor
	vector& operator=(vector&&); // move assignment

	~vector() { delete[] elem; } // destructor

	T& operator[](int n) { return elem[n]; } // access: return reference
	const T& operator[](int n) const { return elem[n]; }

	int size() const { return sz; } // the current size
	int capacity() const { return space; }

	void resize(int newsize); // growth
	void push_back(const T& d);
	void reserve(int newalloc);
};

template<typename T, typename A> void print(const vector<T,A>& v);

#include "vector.ipp"

}
