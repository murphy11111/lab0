#pragma once

#include "Sequence.h"

template<typename T>
class ArraySequence : public Sequence<T> {
private:
	T* p;
	int sz;
	int cap;
	void resize();
public:
	ArraySequence();
	ArraySequence(const ArraySequence& other);
	ArraySequence& operator=(const ArraySequence& other);
	
	int getLength() const override;
	bool getIsEmpty() const override;
	T Get(int index) const override;
	T GetFirst() const override;
	T GetLast() const override;
	Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override;
	void Append(T item);
	void Prepend(T item);
	void InsertAt(int index, T item);
	void Remove(T item);

	~ArraySequence();
};
