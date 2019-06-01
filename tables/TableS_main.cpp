
#include <string>
#include <iostream>
#include "TElem.h"
#include "TableS.h"

#define TableS

using namespace std;

#ifdef TableS

int main()
{
	int count;
	cout << "plese, enter the count of elements in the table -> ";
	cin >> count;

	TTableS<int> tab(count);
	TElem<int> el;
	char str[10];

	for (int i = 0; i < count; i++)
	{
		int data;
		cout << "Enter key  " << i << " ->";
		cin >> str;
		string key(str);
		cout << "Enter data " << i << " ->";
		cin >> data;
		el.SetData(data);
		el.SetKey(key);
		tab.Add(el);
	}
	cout << "Your table : " << endl << tab << endl;

	cout << "Enter count the elems in table to delete ->";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Enter key->";
		cin >> str;
		string _key(str);
		tab.Delete(_key);
	}

	cout << "Your table after deleting: " << endl << tab << endl;

	return 0;
};
#endif
