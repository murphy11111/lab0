#include "../include/ListSequence.h"
#include <stdexcept>

template<typename T>
typename ListSequence<T>::Node* ListSequence<T>::getNode(int index) const {
	if (index < 0 || index >= sz) {
		throw std::out_of_range("Index out of range");
	}
	Node* temp = head->next;
	int i = 0;
	while (i != index) {
		temp = temp->next;
		++i;
	}
	return temp;
}	

template<typename T>
void ListSequence<T>::del(int index) {
	Node* temp = getNode(index);
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
	--sz;
}

template<typename T>
ListSequence<T>::ListSequence(): sz(0) {
	head = new Node(T());
	head->next = head;
	head->prev = head;
}

template<typename T>
ListSequence<T>::ListSequence(const ListSequence& other): ListSequence() {
	Node* temp = other.head->next;
	while(temp != other.head) {
		Append(temp->value);
		temp = temp->next;
	}
}

template<typename T>
ListSequence<T>& ListSequence<T>::operator=(const ListSequence& other) {
	if (this != &other) {
		while (sz > 0) {
			del(0);
		}
		Node* temp = other.head->next;
		while (temp != other.head) {
			Append(temp->value);
			temp = temp->next;
		}
	}
	return *this;
}

template<typename T>
int ListSequence<T>::getLength() const {
	return sz;
}

template<typename T>
bool ListSequence<T>::getIsEmpty() const {
	return sz==0;
}

template<typename T>
T ListSequence<T>::Get(int index) const {
	return getNode(index)->value;
}		

template<typename T>
T ListSequence<T>::GetFirst() const {
	if (getIsEmpty()) {
		throw std::out_of_range("List is empty");
	}
	return getNode(0)->value;
}

template<typename T>
T ListSequence<T>::GetLast() const {
	if (getIsEmpty()) {
		throw std::out_of_range("List is empty");
	}
	return getNode(sz-1)->value;
}

template<typename T>
Sequence<T>* ListSequence<T>::GetSubsequence(int startIndex, int endIndex) const {
	if (startIndex < 0 || startIndex >= sz || endIndex < 1 || endIndex > sz || endIndex <= startIndex) {
		throw std::out_of_range("Incorrect range boundaries");
	}
	ListSequence<T>* a = new ListSequence<T>();
	Node* temp = getNode(startIndex);
	for (int i = startIndex; i<endIndex; ++i) {
		a->Append(temp->value);
		temp = temp->next;
	}
	return a;
}	

template<typename T>
void ListSequence<T>::Append(T item) {
	InsertAt(sz, item);
}

template<typename T>
void ListSequence<T>::Prepend(T item) {
	InsertAt(0, item);
}

template<typename T>
void ListSequence<T>::InsertAt(int index, T item) {
	if (index < 0 || index > sz) {
		throw std::out_of_range("Index out of range");
	}
	Node* temp;
	if (index == 0) {
		temp = head;
	} else {
		temp = getNode(index-1);
	}	
	Node* nev = new Node(item);
	nev->next = temp->next;
	nev->prev = temp;
	temp->next->prev = nev;
	temp->next = nev;
	++sz;
}

template<typename T>
void ListSequence<T>::Remove(T item) {
	Node* temp = head->next;
	int i = 0;
	while(temp != head && temp->value != item) {
		temp = temp->next;
		++i;
	}
	if (temp != head) {
		del(i);
	}	
}	
	
template<typename T>
ListSequence<T>::~ListSequence() {
	while(sz > 0) {
		del(0);
	}
	delete head;  
}

template class ListSequence<int>;
template class ListSequence<double>;
template class ListSequence<uint64_t>;