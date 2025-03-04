#pragma once
#include <iostream>
#include "data.hpp"
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
	void enqueue(T _data);
	T dequeue();
	bool isEmpty();
	void printQueueRecursive();
	T peek();
};

#pragma region Member Functions
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
void Queue<T>::enqueue(T _data)
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
	if (pHead == pTail)
	{
		T thing = pHead->getData();
		pHead = nullptr;
		pTail = nullptr;
		return thing;
	}
	else
	{
		Node<T>* pTemp = pHead;
		pHead = pHead->getNext();
		T thing = pTemp->getData();
		delete pTemp;
		return thing;
	}

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
	std::cout << pCur->getData() << std::endl;
	printQueueRecursive(pCur->getNext());
}

template <typename T>
T Queue<T>::peek()
{
	if (isEmpty())
	{
		std::cout << "shit is empty as hell foo" << std::endl;
		return nullptr;
	}
	else
	{
		std::cout << "Peek: " << pHead->getData().getCustomerNumber() << std::endl;
		return &(pHead->getData()); //address of the data
	}
}
#pragma endregion