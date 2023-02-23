#include <iostream>
#include "List.h"

int main()
{
	LinearList list(6);
	LinearList list2;
	LinearList concatedList;

	list.addNode('a');
	list.addNode('b');
	list.addNode('c');

	list2 = list;

	concatedList = list + list2;
	cout << concatedList;
}
