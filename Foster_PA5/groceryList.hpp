/*File: groceryList.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA5
* Created: 03/02/2025
* Last updated: 03/05/2025
* Description: Defines Grocery item(node) and GroceryList(linked list) classes
*/
#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

class GroceryItem
{
private:
	std::string name;
	GroceryItem* pNext;
public:
	GroceryItem();
	GroceryItem(std::string _name);
	~GroceryItem();
	GroceryItem* getNext();
	std::string getName() { return name; }
	void setNext(GroceryItem* _pNext);
};

#pragma region GroceryItem Members
GroceryItem::GroceryItem()
{
	name = "";
	pNext = nullptr;
}
GroceryItem::GroceryItem(std::string _name)
{
	name = _name;
	pNext = nullptr;
}
GroceryItem::~GroceryItem()
{

}
GroceryItem* GroceryItem::getNext()
{
	return pNext;
}
void GroceryItem::setNext(GroceryItem* _pNext)
{
	pNext = _pNext;
}
#pragma endregion

//Linked list class
class GroceryList
{
private:
	GroceryItem* pHead;
public:
	GroceryList();
	~GroceryList();
	void addItem(GroceryItem item);
	void generateRandomList();
	int countList();
	void deleteList();
	void printList();
};

#pragma region GroceryList Members
GroceryList::GroceryList()
{
	pHead = nullptr;
}
GroceryList::~GroceryList()
{
	//while (pHead != nullptr)
	//{
	//	GroceryItem* pTemp = pHead;
	//	pHead = pHead->getNext();
	//	delete pTemp;
	//}
	//cant delete here cause it will delete the items in the queue
	//deleting with deleteList in dequeue in queue class
}
void GroceryList::addItem(GroceryItem item)
{
	GroceryItem* pNewNode = new GroceryItem(item);
	if (pHead == nullptr)
	{
		pHead = pNewNode;
	}
	else
	{
		pNewNode->setNext(pHead);
		pHead = pNewNode;
	}
}
int GroceryList::countList()
{
	int count = 0;
	GroceryItem* pCur = pHead;
	while (pCur != nullptr)
	{
		count++;
		pCur = pCur->getNext();
	}
	return count;
}
void GroceryList::generateRandomList()
{
	std::string items[] = { "apple", "banana", "carrot", "doughnut", "eggplant", "fries", "grapes", "hamburger", "ice cream", "jelly beans" };
	int numItems = rand() % 4 + 1; //customers have between 1 and 4 items. More makes them not process fast enough for arrival times
	for (int i = 0; i < numItems; i++)
	{
		addItem(GroceryItem(items[rand() % 10]));
	}
}
void GroceryList::deleteList()
{
	while (pHead != nullptr)
	{
		GroceryItem* pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
}

void GroceryList::printList()
{
	GroceryItem* pCur = pHead;
	while (pCur != nullptr)
	{
		std::cout << pCur->getName() << ", ";
		pCur = pCur->getNext();
	}
	std::cout << std::endl;
}

#pragma endregion