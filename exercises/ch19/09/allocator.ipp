/*
 *	Implementation of allocator based on:
 *	https://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement
 */


template<typename T>
T* allocator<T>::allocate(int n)
{
//	return reinterpret_cast<T*>(::operator new(n * sizeof(T)));
//	return ::operator new(n * sizeof(T));
	return malloc(n * sizeof(T));
}

template<typename T>
void allocator<T>::deallocate(T* p, std::size_t n)
{
// Why is the 'n' variable suggested to be included here (ch. 19.3.7) if the entirety of the reserved memory is freed?
//	::operator delete(p);
	free(p);
}

template<typename T>
void allocator<T>::construct(T* p, const T& v)
{
	new(p) T{v};
}

template<typename T>
void allocator<T>::destroy(T* p)
{
	p->~T();
}

