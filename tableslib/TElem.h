
#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class TElem
{
protected:
	string key;
	T data;
public:
	TElem() {};

	TElem(string _key, T _data)
	{
		key = _key;
		data = _data;
	};

	~TElem() {};

	TElem& operator = (const TElem<T>& h)
	{
		if (this != &h)
		{
			key = h.key;
			data = h.data;
		}
		return *this;
	};

	bool operator == (TElem& A)
	{
		return (data == A.data && key == A.key);
	};

	bool operator != (TElem& A)
	{
		return (data != A.data || key != A.key);
	};

	bool operator < (TElem& A)
	{
		return (key < A.key);
	};

	bool operator > (TElem& A)
	{
		return (key > A.key);
	};

	T& GetData()
	{
		return data;
	};

	void SetData(const T& _data)
	{
		data = _data;
	};

	string& GetKey()
	{
		return key;
	}

	void SetKey(string _key)
	{
		key = _key;
	}

	friend ostream& operator << (ostream& out, TElem& A)
	{
		out << "key:  " << A.key << " , ";
		out << "data:  " << A.data << endl;
		return out;
	}
};
