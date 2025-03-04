#pragma once
#include <iostream>
#include "data.hpp"


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