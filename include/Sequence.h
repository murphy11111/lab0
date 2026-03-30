#pragma once

template<typename T>
class Sequence {
public:
	virtual ~Sequence () {}
	virtual int getLength() const = 0;
	virtual bool getIsEmpty() const = 0;
	virtual T Get(int index) const = 0;
	virtual T GetFirst() const = 0;
	virtual T GetLast() const = 0;
	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
	virtual void Append(T item) = 0;
	virtual void Prepend(T item) = 0;
	virtual void InsertAt(int index, T item) = 0;
	virtual void Remove(T item) = 0;  
};