#include "../include/ArraySequence.h"
#include <stdexcept>

template<typename T>
void ArraySequence<T>::resize() {
	cap *= 2;
	T* p0 = new T[cap];
	for (int i = 0; i<sz; ++i) {
		p0[i] = p[i];
	}
	delete[] p;
	p = p0;
}

template<typename T>
ArraySequence<T>::ArraySequence(): sz(0), cap(100) {
	p = new T[cap];
}

template<typename T>
ArraySequence<T>::ArraySequence(const ArraySequence& other): sz(other.sz), cap(other.cap) {
	p = new T[cap];
	for (int i = 0; i<sz; ++i) {
		p[i] = other.p[i];
	}
}

template<typename T>
ArraySequence<T>& ArraySequence<T>::operator=(const ArraySequence& other) {
	if (this != &other) {
		delete[] p;
		cap = other.cap;
		sz = other.sz;
		p = new T[cap];
		for (int i = 0; i<sz; ++i) {
			p[i] = other.p[i];
		}
	}
	return *this;
}

template<typename T>
int ArraySequence<T>::getLength() const {
	return sz;
}

template<typename T>
bool ArraySequence<T>::getIsEmpty() const {
	return sz==0;
}

template<typename T>
T ArraySequence<T>::Get(int index) const {
	if (index < 0 || index >= sz) {
		throw std::out_of_range("Index out of range");
	}
	return p[index];
}		

template<typename T>
T ArraySequence<T>::GetFirst() const {
	if (getIsEmpty()) {
		throw std::out_of_range("Array is empty");
	}
	return p[0];
}

template<typename T>
T ArraySequence<T>::GetLast() const {
	if (getIsEmpty()) {
		throw std::out_of_range("Array is empty");
	}
	return p[sz-1];
}

template<typename T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex) const {
	if (startIndex < 0 || startIndex >= sz || endIndex < 1 || endIndex > sz || endIndex <= startIndex) {
		throw std::out_of_range("Incorrect range boundaries");
	}
	ArraySequence<T>* a = new ArraySequence<T>();
	for (int i = startIndex; i<endIndex; ++i) {
		a->Append(p[i]);
	}
	return a;
}	

template<typename T>
void ArraySequence<T>::Append(T item) {
	if (sz == cap) {
		resize();
	}
	p[sz++] = item;
}

template<typename T>
void ArraySequence<T>::Prepend(T item) {
	if (sz == cap) { 
		resize();
	}
	T* p0 = new T[cap];
	p0[0] = item;
	for (int i = 1; i<=sz; ++i) {
		p0[i] = p[i-1];
	}
	delete[] p;
	p = p0;
	++sz;					
}

template<typename T>
void ArraySequence<T>::InsertAt(int index, T item) {
	if (index < 0 || index > sz) {
		throw std::out_of_range("Index out of range");
	}
	if (sz == cap) {
		resize();
	}
	T* p0 = new T[cap];
	for (int i = 0; i<index; ++i) {
		p0[i] = p[i];
	}
	p0[index] = item;
	for (int i = index+1; i<=sz; ++i) {
		p0[i] = p[i-1];
	}
	delete[] p;
	p = p0;
	++sz;
}

template<typename T>
void ArraySequence<T>::Remove(T item) {
	int i = 0;
	while(i<sz && p[i] != item) {
		++i;
	}
	for (int j = i; j<(sz-1); ++j) {
		p[j] = p[j+1];
	}
	if (i == sz) {
		--sz;
	}
}	
	
template<typename T>
ArraySequence<T>::~ArraySequence() {
	delete[] p;
}

template class ArraySequence<int>;
template class ArraySequence<double>;
template class ArraySequence<uint64_t>;