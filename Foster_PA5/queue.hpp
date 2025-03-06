/*File: queue.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA5
* Created: 03/02/2025
* Last updated: 03/05/2025
* Description: Defines Queue class of nodes for use in simulation
*/
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

//dequeues and deletes the grocery list of the customer
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

//accesses private version of printQueueRecursive
template <typename T>
void Queue<T>::printQueueRecursive()
{
	printQueueRecursive(pHead);
}

//prints the queue recursively
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

//returns the data of the head of the queue without printing it
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