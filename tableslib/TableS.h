
#pragma once
#include <string>
#include <iostream>
#include "TElem.h"

using namespace std;

template <class T>
class TTableS : public TElem<TElem<T> >
{
protected:
	TElem<T>* node;
	int size, count;
	static TElem<T> zero;
public:
	TTableS(const int _size);
	TTableS(TTableS<T>& A);
	~TTableS();

	bool Add(const TElem<T>& A);
	bool Add(T& _data);
	int GetCount() const { return count; }

	void Expansion(int newSize);

	void Delete(TElem<T>& A);
	bool Delete(const string& _key);
	TElem<T>& Search(string _key);
	int& operator [] (string _key);

	friend ostream& operator << (ostream& out, TTableS<T>& A)
	{
		for (int  i = 0; i < A.count; i++)
			out << A.node[i] << endl;
		return out;
	}
};

/////////////////////////////

template <class T>
TElem<T> TTableS<T>::zero;

template <class T>
TTableS<T>::TTableS(const int _size)
{
	if (_size < 1)
		throw 1;
	size = _size;
	count = 0;
	node = new TElem<T>[_size];
	for (int i = 0; i < size; i++)
	{
		node[i] = zero;
	}
};

template <class T>
TTableS<T>::TTableS(TTableS<T>& A)
{
	size = A.size;
	count = A.count;
	node = new TElem<T>[size];

	for (int i = 0; i < size; i++)
	{
		node[i] = A.node[i];
	}
};

template <class T>
TTableS<T>::~TTableS()
{
	count = 0;
	size = 0;
	delete[]node;
};

template <class T>
bool TTableS<T>::Add(const TElem<T>& A)
{
	if (size == count)
		Expansion(count * 2);
	node[count] = A;
	count++;
	return true;
};

/*template <class T>
bool TTableS<T>::Add(T& _data)
{
	
};
*/


template <class T>
void TTableS<T>::Expansion(int newSize)
{
	if (size < newSize)
	{

		TElem<T>* newArr;
		newArr = new TElem<T>[newSize];

		for (int i = 0; i < count; i++)
			newArr[i] = node[i];
		for (int i = count; i < newSize; i++)
		{
			newArr[i] = zero;
		}

		size = newSize;
		delete[] node;
		node = newArr;
	}
}

template <class T>
void TTableS<T>::Delete(TElem<T>& A)
{
	if (count == 0)
		throw 1;
	for (int i = 0; i < count; i++)
	{
		if (node[i].GetKey()==A.GetKey())
			for (int j = 0; j < count - 1; j++)
				node[j] = node[j + 1];
		count--;
	}
}

template <class T>
bool TTableS<T>::Delete(const string& _key)
{
	if (count == 0)
		return false;
	bool flag = false;
	for (int i = 0; i < count; i++)
		if (node[i].GetKey() == _key)
		{
			for (int j = i; j < count-1; j++)
				node[j] = node[j + 1];
			flag = true;
			break;
		}
		if (flag == true)
			count--;
		return flag;
}

template <class T>
TElem<T>& TTableS<T>::Search(string _key)
{
	for (int i = 0; i < count; i++)
		if (node[i].GetKey() == _key)
			return node[i];
	return zero;
}

template <class T>
int& TTableS<T>::operator [] (string _key)
{
	return Search(_key).GetData();
}













