#include <iostream>
#include "List.h"

int main()
{
	LinearList<char> list(6);
	LinearList<char> list2;
	LinearList<char> concatedList;
	LinearList<char> cinList(10);

	list.addNode('a');
	list.addNode('b');
	list.addNode('c');

	// Copy constructor and '=' overloading
	list2 = list;

	// '+' overloading
	concatedList = list + list2;

	// '<<' overloading
	cout << concatedList;

	// '>>' overloading
	cin >> cinList;

	cout << cinList;
}
