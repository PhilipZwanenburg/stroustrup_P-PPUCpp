#ifndef PZwan_struct_S
#define PZwan_struct_S

template<typename T>
struct S {
	S(T v): val{v} {};

	T& get();
	T& get() const;
	void set(const T& new_val);

	S<T>& operator=(const T& new_val);

private:
	T val;
};

// The implementation of template functions must be made visible in the header. The '*.ipp' naming convention is
// borrowed from Boost.
#include "struct_S.ipp"

#endif
