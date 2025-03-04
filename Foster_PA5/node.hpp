#pragma once
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

