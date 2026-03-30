#include <iostream>
#include "include/ArraySequence.h"
#include "include/ListSequence.h"
#include <cassert>
#include <stdexcept>

int main() {
	{
		ArraySequence<int> a;
		assert(a.getLength() == 0);
		a.Append(23);
		assert(a.getLength() == 1);
		assert(a.GetFirst() == 23);
		assert(a.GetLast() == 23);
		assert(a.Get(0) == 23);
		try {
			a.Get(-1);
			assert(false);
		} catch (const std::out_of_range&) {
			
		}
		try {
			a.Get(1);
			assert(false);
		} catch (const std::out_of_range&) {
	
		}
		a.Append(43);
		assert(a.getLength() == 2);
		assert(a.GetFirst() == 23);
		assert(a.GetLast() == 43);
		assert(a.Get(0) == 23);
		assert(a.Get(1) == 43);
		try {
			a.Get(-1);
			assert(false);
		} catch (const std::out_of_range&) {
			
		}
		try {
			a.Get(2);
			assert(false);
		} catch (const std::out_of_range&) {
	
		}	
		a.Prepend(53);
		assert(a.getLength() == 3);
		assert(a.GetFirst() == 53);
		assert(a.GetLast() == 43);
		assert(a.Get(0) == 53);
		assert(a.Get(1) == 23);
		try {
			a.Get(-1);
			assert(false);
		} catch (const std::out_of_range&) {
			
		}
		try {
			a.Get(3);
			assert(false);
		} catch (const std::out_of_range&) {
	
		}
		Sequence<int>* b = a.GetSubsequence(1,2);
		assert(b->getLength() == 1);
		assert(b->GetFirst() == 23);
		assert(b->GetLast() == 23);
		delete b;
		std::cout << "hi there\n";
	}
	
	{
		ListSequence<int> a;
		assert(a.getLength() == 0);
		a.Append(23);
		assert(a.getLength() == 1);
		assert(a.GetFirst() == 23);
		assert(a.GetLast() == 23);
		assert(a.Get(0) == 23);
		try {
			a.Get(-1);
			assert(false);
		} catch (const std::out_of_range&) {
			
		}
		try {
			a.Get(1);
			assert(false);
		} catch (const std::out_of_range&) {
	
		}
		a.Append(43);
		assert(a.getLength() == 2);
		assert(a.GetFirst() == 23);
		assert(a.GetLast() == 43);
		assert(a.Get(0) == 23);
		assert(a.Get(1) == 43);
		try {
			a.Get(-1);
			assert(false);
		} catch (const std::out_of_range&) {
			
		}
		try {
			a.Get(2);
			assert(false);
		} catch (const std::out_of_range&) {
	
		}	
		a.Prepend(53);
		assert(a.getLength() == 3);
		assert(a.GetFirst() == 53);
		assert(a.GetLast() == 43);
		assert(a.Get(0) == 53);
		assert(a.Get(1) == 23);
		try {
			a.Get(-1);
			assert(false);
		} catch (const std::out_of_range&) {
			
		}
		try {
			a.Get(3);
			assert(false);
		} catch (const std::out_of_range&) {
	
		}
		Sequence<int>* b = a.GetSubsequence(1,2);
		assert(b->getLength() == 1);
		assert(b->GetFirst() == 23);
		assert(b->GetLast() == 23);
		delete b;
		std::cout << "hi there\n";
	}
}
