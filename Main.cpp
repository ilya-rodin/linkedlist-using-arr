#include <iostream>
#include "List.h"

int main()
{
	LinearList list(6);
	LinearList list2;
	LinearList concatedList;
	LinearList cinList(3);

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
