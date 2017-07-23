
template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector<T,A>& a)
{
	if (this == &a) {
		// Do nothing
	} else if (a.sz <= space) { // already enough space
		for (int i = 0; i < a.sz; ++i)
			elem[i] = a.elem[i];
		sz = a.sz;
	} else {
//#define op_eq_original
#ifdef op_eq_original
		T* p = new T[a.sz];
		for (int i = 0; i < a.sz; ++i)
			p[i] = a.elem[i];
		delete[] elem;
		space = sz = a.sz;
		elem = p;
#else
		// Does not seem more efficient as all previously defined entries in elem are copied in reserve().
		reserve(a.sz);
		for (int i = 0; i < a.sz; ++i)
			alloc.construct(&elem[i],a.elem[i]);
		sz = a.sz;
#endif
	}

	return *this;
}


template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
	if (newalloc<=space)
		return;

	T* p = alloc.allocate(newalloc);
	for (int i = 0; i < sz; ++i)
		alloc.construct(&p[i],elem[i]);

	for (int i = 0; i < sz; ++i)
		alloc.destroy(&elem[i]);

	alloc.deallocate(elem,space);
	elem = p;
	space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
{
	if (space == 0)
		reserve(8);
	else if (sz == space)
		reserve(2*space);

	alloc.construct(&elem[sz],val);
	++sz;
}

template<typename T, typename A>
void print(const vector<T,A>& v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ", ";
	cout << '\n';
}
