#pragma once
#include <iostream>
#include "data.hpp"

class QueueNode
{
private:
	Data* pData;
	QueueNode* pNext;
public:
	QueueNode();
	QueueNode(Data* pData);
	~QueueNode();
	Data getData();
};
#pragma region QueueNode Members
QueueNode::QueueNode()
{
	pData = nullptr;
	pNext = nullptr;
}
QueueNode::QueueNode(Data* pData)
{
	this->pData = pData;
	pNext = nullptr;
}
QueueNode::~QueueNode()
{
	//work on this
}
Data QueueNode::getData()
{
	return *pData;
}
#pragma endregion


class Queue
{
public:
	Queue();
	~Queue();
	void enqueue(Data* pData);
	Data* dequeue();
	Data* peek();
	bool isEmpty();
	void printQueue();
private:
	QueueNode* pHead;
	QueueNode* pTail;
};
#pragma region Queue Members
Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

Data* Queue::peek()
{
	if (isEmpty())
	{
		std::cout << "Queue is empty" << std::endl;
		return nullptr;
	}
	else
	{
		std::cout << "Peek: " << pHead->getData().getCustomerNumber() << std::endl;
		return &(pHead->getData()); //address of the data
	}
}

#pragma endregion