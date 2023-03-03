#pragma once
#include <iostream>

using namespace std;

template <class T>
class LinearList
{
private:
	struct Element
	{
		T elem;
		int next;
	};

	Element* base;
	int beginData;
	int beginFreeSpace = 0;
	int capacity = 0;

public:
	LinearList(const LinearList&);
	LinearList(const int capacity = 10);
	~LinearList();

	LinearList operator+(LinearList&);
	LinearList& operator=(const LinearList&);
	void addNode(T);
	T shift();
	T pop();
	void displayList();
	int len();
	bool isEmpty();
	
	friend ostream& operator<<(ostream& out, LinearList<T>& list)
	{
		int i = list.beginData;

		out << "List: ";
		while (i != -1)
		{
			out << list.base[i].elem << " ";
			i = list.base[i].next;
		}
		out << "\n";
		return out;
	}

	friend istream& operator>>(istream& in, LinearList<T>& list)
	{
		if (list.beginFreeSpace == -1)
		{
			throw "List is full!";
		}

		while (true)
		{
			char newElem;
			cout << "Enter data to add (\\ to exit): ";
			in >> newElem;

			if (newElem == '\\') { break; }

			list.addNode(newElem);
		}
		return in;
	}
};

template <class T>
LinearList<T>::LinearList(const LinearList& otherList)
{
	capacity = otherList.capacity;
	base = new Element[otherList.capacity];
	beginData = 0;

	if (!base) { throw "base is not defined!"; }

	for (int i = 0; i < otherList.capacity; i++)
	{
		base[i].elem = otherList.base[i].elem;
		base[i].next = otherList.base[i].next;
	}
	base[capacity - 1].next = otherList.base[capacity - 1].next;
}

template <class T>
LinearList<T>::LinearList(const int capacity)
{
	beginData = 0;
	this->capacity = capacity;
	base = new Element[capacity];

	if (!base) { throw "base is not defined!"; }

	for (int i = 0; i < this->capacity; i++)
	{
		base[i].elem = 0;
		base[i].next = i + 1;
	}
	base[capacity - 1].next = -1;
}

template <class T>
LinearList<T>::~LinearList()
{
	for (int i = 0; i < capacity; i++)
	{
		base[i].elem = 0;
	}
	delete[] base;
}

template <class T>
LinearList<T> LinearList<T>::operator+(LinearList<T>& otherList)
{
	LinearList result(capacity + otherList.capacity);

	for (int i = 0; i < len(); i++)
	{
		result.addNode(base[i].elem);
	}

	for (int i = 0; i < otherList.len(); i++)
	{
		result.addNode(otherList.base[i].elem);
	}

	return result;
}

template <class T>
LinearList<T>& LinearList<T>::operator=(const LinearList<T>& otherList)
{
	if (this != &otherList)
	{
		delete[] base;
		capacity = otherList.capacity;
		base = new Element[otherList.capacity];
		beginData = 0;
		
		if (!base) { throw "base is not defined!"; }

		for (int i = 0; i < otherList.capacity; i++)
		{
			base[i].elem = otherList.base[i].elem;
			base[i].next = otherList.base[i].next;
		}
		base[capacity - 1].next = otherList.base[capacity - 1].next;
	}
	else
	{
		cout << "Lists are equal!" << endl;
	}
	return *this;
}

template <class T>
void LinearList<T>::addNode(T newData)
{
	if (beginFreeSpace == -1)
	{
		throw "List is full!";
	}

	int indexNewBeginFreeSpace;
	int index;
	int i = beginData;
	while (i != -1)
	{
		index = i;
		i = base[i].next;
	}

	base[index].next = beginFreeSpace;
	base[beginFreeSpace].elem = newData;
	indexNewBeginFreeSpace = base[beginFreeSpace].next;
	base[beginFreeSpace].next = -1;
	beginFreeSpace = indexNewBeginFreeSpace;
}

template <class T>
T LinearList<T>::shift()
{
	T elem;
	int indexDelElem;

	if (base[beginData].elem == 0)
	{
		throw "wtf that russian dog said?";
	}

	indexDelElem = beginData;
	elem = base[indexDelElem].elem;
	base[indexDelElem].elem = 0;
	beginData = base[indexDelElem].next;
	base[indexDelElem].next = beginFreeSpace;
	beginFreeSpace = indexDelElem;
	return elem;
}

template <class T>
T LinearList<T>::pop()
{
	T elem;
	int indexDelElem;

	if (base[beginData].elem == 0)
	{
		throw "Nothing to delete";
	}

	int i = beginData;
	while (i != -1)
	{
		indexDelElem = i;
		i = base[i].next;
	}

	elem = base[indexDelElem].elem;
	base[indexDelElem].elem = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (base[i].next == indexDelElem)
		{
			base[i].next = -1;
			break;
		}
	}

	base[indexDelElem].next = beginFreeSpace;
	beginFreeSpace = indexDelElem;

	return elem;
}

template <class T>
void LinearList<T>::displayList()
{
	int i = beginData;

	if (base[i].elem == 0 || i == -1)
	{
		throw "List is empty";
	}

	cout << "List: ";
	while (i != -1)
	{
		cout << base[i].elem << " ";
		i = base[i].next;
	}
	cout << endl;
}

template <class T>
int LinearList<T>::len()
{
	int i = beginData;
	int len = 0;
	if (base[i].elem == 0)
	{
		throw "List is empty";
	}

	while (i != -1)
	{
		len++;
		i = base[i].next;
	}
	return len;
}

template <class T>
bool LinearList<T>::isEmpty()
{
	if (len() == 0)
	{
		return true;
	}
	return false;
}
