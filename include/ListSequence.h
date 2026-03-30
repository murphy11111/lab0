#pragma once

#include "Sequence.h"

template<typename T>
class ListSequence: public Sequence<T> {
private:
	struct Node {
		T value;
		Node* next;
		Node* prev;
		Node(const T& val): value(val), next(nullptr),prev(nullptr){}
	};
	Node* head;
	int sz;	
	void del(int index);
	Node* getNode(int index) const;
public:
	ListSequence();
	ListSequence(const ListSequence& other);
	ListSequence& operator=(const ListSequence& other);
	
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

	~ListSequence();
};
