#pragma once
#include "List.h"
#include <iostream>
using namespace std;
template <class T>                                        
class Stack :public List<T>
{
public:
	Stack();
	bool empty();
	bool full();
	int size();
	T top();
	void push(T);
	T pop();
private:
	void addElement(T);
	T removeElement();
};

template<class T>
Stack<T>::Stack():List<T>()
{
}

template<class T>
bool Stack<T>::empty()
{
	if (List<T>::currentSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool Stack<T>::full()
{
	return false;
}

template<class T>
int Stack<T>::size()
{
	return List<T>::currentSize;
}

template<class T>
T Stack<T>::top()
{
	if (List<T>::currentSize == 0)
	{
		return 0;
	}
	else
	{
		return List<T>::arr[List<T>::currentSize - 1];
	}
}

template<class T>
void Stack<T>::push(T element)
{
	addElement(element);
}

template<class T>
T Stack<T>::pop()
{
	
	T last = removeElement();
	return last;
}

template<class T>
void Stack<T>::addElement(T element)
{
	List<T>::regrow(element);
}

template<class T>
T Stack<T>::removeElement()
{
	if (List<T>::currentSize == 0)
	{
		cout << "Cannot Delete." << endl;
		return 0;
	}
	else
	{
		T last = List<T>::arr[List<T>::currentSize - 1];
		List<T>::shrink();
		return last;
	}
}
