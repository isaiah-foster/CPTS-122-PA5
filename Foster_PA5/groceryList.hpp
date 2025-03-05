#pragma once
#include "data.hpp"

class groceryItem
{
private:
	std::string name;
	groceryItem* pNext;
public:
	groceryItem();
	groceryItem(std::string _name);
	~groceryItem();
	groceryItem* getNext();
	void setNext(groceryItem* _pNext);
};

#pragma region GroceryItem Members
groceryItem::groceryItem()
{
	name = "";
	pNext = nullptr;
}
groceryItem::groceryItem(std::string _name)
{
	name = _name;
	pNext = nullptr;
}
groceryItem::~groceryItem()
{

}
groceryItem* groceryItem::getNext()
{
	return pNext;
}
void groceryItem::setNext(groceryItem* _pNext)
{
	pNext = _pNext;
}
#pragma endregion

class groceryList
{
private:
	groceryItem* pHead;
	int countList();
public:
	groceryList();
	~groceryList();
	void addItem(groceryItem item);
	void generateRandomList();
};

#pragma region GroceryList Members
groceryList::groceryList()
{
	pHead = nullptr;
}
groceryList::~groceryList()
{
	while (pHead != nullptr)
	{
		groceryItem* pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
}
void groceryList::addItem(groceryItem item)
{
	groceryItem* pNewNode = new groceryItem(item);
	if (pHead == nullptr)
	{
		pHead = pNewNode;
	}
	else
	{
		groceryItem* pCur = pHead;
		while (pCur->getNext() != nullptr)
		{
			pCur = pCur->getNext();
		}
		pCur->setNext(pNewNode);
	}
}

int groceryList::countList()
{
	int count = 0;
	groceryItem* pCur = pHead;
	while (pCur != nullptr)
	{
		count++;
		pCur = pCur->getNext();
	}
	return count;
}
void groceryList::generateRandomList()
{
	std::string items[] = { "apple", "banana", "carrot", "doughnut", "eggplant", "fries", "grapes", "hamburger", "ice cream", "jelly beans" };
	int numItems = rand() % 10 + 1;
	for (int i = 0; i < numItems; i++)
	{
		addItem(groceryItem(items[rand() % 10]));
	}

}
#pragma endregion