#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
template <class T>
class TQueue
{
	T* pMem;
	int size, start, finish, count;
public:
	TQueue(int _size) {
		pMem = new T[_size];
		size = _size;
		count = 0;
		start = 0;
		finish = -1;
	}
	TQueue(const TQueue& other) {
		size = other.size;
		start = other.start;
		finish = other.finish;
		count = other.count;
		pMem = new int[size];
		for (int i = 0; i < size; i++) {
			pMem[i] = other.pMem[i];
		}
	}

	~TQueue() {
		delete[] pMem;
	}

	TQueue& operator=(const TQueue& other) {
		if (this != &other) {
			delete[] pMem;
			size = other.size;
			start = other.start;
			finish = other.finish;
			count = other.count;
			pMem = new int[size];
			for (int i = 0; i < size; i++) {
				pMem[i] = other.pMem[i];
			}
		}
		return *this;
	}
	bool operator==(const TQueue& other) {
		if (size != other.size) {
			return false;
		}
		for (int i = 0; i < size; i++) {
			if (pMem[i] != other.pMem[i]) {
				return false;
			}
		}
		return true;
	}

	void printQueue() {
		if (empty()) {
			cout << "Queue is empty" << endl;
			return ;
		}
		for (int i = start; i <= finish; i++) {
			cout << pMem[i] << " ";
		}
		cout << endl;
	}
	bool empty()
	{
		if (count == 0) return true;
		else return false;
	}
	bool full()
	{
		if (count == size) return true;
		else return false;
	}
	void Push(const T& el)
	{
		finish++;
		if (full()) throw "Queue is full";
		else
		{
			if (finish == size) finish = 0;
			pMem[finish] = el;
			count++;

		}
	}
	T Pop()
	{
		if (this->empty() == true)
		{
			throw("Queue is empty");
		}
		
		
			T el = pMem[start];
			start++;
			if (start == size) start = 0;
			count--;
			return el;
		
	}
	T Front()
	{
		if (empty()) {
			throw "Queue is empty";
			return -1;
		}
		return pMem[start];
	}
	T Back()
	{
		if (full()) {
			throw "Queue is empty";
			return -1;
		}
		return pMem[finish];
	}
};

