/*File: node.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA5
* Created: 03/02/2025
* Last updated: 03/05/2025
* Description: defines node class for queue holding customer data
*/
#pragma once
#include "data.hpp"


template <typename T> class Node
{
private:
	T data;
	Node<T>* next;
public:
	Node(T _data);

	~Node();
	T getData();
	Node<T>* getNext();
	void setNext(Node<T>* _next);
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