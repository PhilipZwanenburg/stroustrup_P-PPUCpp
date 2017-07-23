template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
T& S<T>::get() const
{
	return val;
}

template<typename T>
void S<T>::set(const T& new_val)
{
	val = new_val;
}

template<typename T>
S<T>& S<T>::operator=(const T& new_val)
{
	val = new_val;
}

