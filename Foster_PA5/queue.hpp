#pragma once
#include "node.hpp"

template <typename T> class Queue
{
private:
	Node<T>* pHead;
	Node<T>* pTail;
	void printQueueRecursive(Node<T>* pCur);
public:
	Queue();
	~Queue();
	void enqueue(T &_data);
	T dequeue();
	bool isEmpty();
	void printQueueRecursive();
	T peek();
};


template <typename T>
Queue<T>::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template <typename T>
void Queue<T>::enqueue(T &_data)
{
	Node<T>* pNewNode = new Node<T>(_data);
	if (isEmpty())
	{
		pHead = pNewNode;
		pTail = pNewNode;
	}
	else
	{
		pTail->setNext(pNewNode);
		pTail = pNewNode;
	}
}

template <typename T>
T Queue<T>::dequeue()
{
	T thing = pHead->getData();
	if (pHead == pTail)
	{
		pHead->getData().getGroceryList().deleteList();
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		Node<T>* pTemp = pHead;
		pHead = pHead->getNext();
		pTemp->getData().getGroceryList().deleteList();
		delete pTemp;
	}
	return thing;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	return pHead == nullptr;
}

template <typename T>
void Queue<T>::printQueueRecursive()
{
	printQueueRecursive(pHead);
}

template <typename T>
void Queue<T>::printQueueRecursive(Node<T>* pCur)
{
	if (pCur == nullptr)
	{
		return;
	}
	std::cout << pCur->getData().getCustomerNumber() << ": ";
	pCur->getData().getGroceryList().printList(); //print grocery list after customer number
	printQueueRecursive(pCur->getNext());
}

template <typename T>
T Queue<T>::peek()
{
	if (isEmpty())
	{
		return Data(0, 0, 0);
	}
	else
	{
		return pHead->getData();
	}
}