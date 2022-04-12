#include <iostream>
#pragma once
using namespace std;
template <class T>
class List
{
protected:
	T* arr;
	int currentSize;
	void shrink();
	void regrow(T element);
public:
	List();
	~List();
	virtual void addElement(T) = 0;
	virtual T removeElement() = 0;
};

template<class T>
List<T>::List()
{
	currentSize = 0;
}

template<class T>
List<T>::~List()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}

template<class T>
void List<T>::shrink()
{
	if (currentSize > 1)
	{
		T* temp = new T[--currentSize];
		for (int i = 0; i < currentSize; i++)
		{
			temp[i] = arr[i];
		}
		delete [] arr;
		arr = temp;
		temp = nullptr;
	}
	else if (currentSize == 1)
	{
		delete[] arr;
		arr = nullptr;
		currentSize = 0;
	}
	else
	{
		cout << "Cannot Delete." << endl;
	}
}

template<class T>
void List<T>::regrow(T element)
{
	if (currentSize == 0)
	{
		arr = new T[1];
		arr[0] = element;
		currentSize++;
		return;
	}
	else
	{
		T* temp = new T[currentSize + 1];
		for (int i = 0; i < currentSize; i++)
		{
			temp[i] = arr[i];
		}
		temp[currentSize] = element;
		delete[] arr;
		arr = temp;
		currentSize++;
		temp = nullptr;
	}
}
