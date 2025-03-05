#pragma once
#include "groceryList.hpp"

template <typename T> class Node
{
private:
	T data;
	Node<T>* next;
	groceryList groceryList;
public:
	Node(T _data);

	~Node();
	T getData();
	Node<T>* getNext();
	void setNext(Node<T>* _next);
	makeList();
};

template <typename T>
Node<T>::Node(T _data)
{
	data = _data;
	next = nullptr;
}

template <typename T>
Node<T>::~Node()
{

}

template <typename T>
T Node<T>::getData()
{
	return data;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template <typename T>
void Node<T>::setNext(Node<T>* _next)
{
	next = _next;
}

template <typename T>
void Node<T>::makeList()
{
	groceryList.generateRandomList();
}