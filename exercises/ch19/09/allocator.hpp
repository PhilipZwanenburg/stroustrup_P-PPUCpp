#ifndef PZwan_allocator
#define PZwan_allocator

#include <cstddef>

namespace alloc {

template<typename T>
class allocator {
public:
	T* allocate(int n);
	void deallocate(T* p, std::size_t n);

	void construct(T* p, const T& v);
	void destroy(T* p);
};

#include "allocator.ipp"

}

#endif
