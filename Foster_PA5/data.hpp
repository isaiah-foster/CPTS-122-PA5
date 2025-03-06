/*File: data.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA5
* Created: 03/02/2025
* Last updated: 03/05/2025
* Description: defines data class to represent customer data holdinga a grocery list
*/
#pragma once
#include "groceryList.hpp"

class Data
{
public:
	Data();
	Data(int _customerNumber, int _totalTime, int _entryTime);
	~Data();
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();
	int getEntryTime();
	void setCustomerNumber(int customerNumber);
	void setServiceTime(int serviceTime);
	void setTotalTime(int totalTime);
	void setEntryTime(int entryTime);
	GroceryList getGroceryList() { return groceryList; }

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in
	// minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line
	// before this customer; units in minutes
	int entryTime; // Time that the customer enters the line; units in minutes

	GroceryList groceryList;
};

#pragma region Data Members
Data::Data()
{
	groceryList.generateRandomList(); 
	serviceTime = groceryList.countList(); //extra credit. service time is based on number of items in grocery list
	customerNumber = 0;
	totalTime = serviceTime;
}
Data::Data(int _customerNumber, int _totalTime, int _entryTime)
{
	groceryList.generateRandomList();
	serviceTime = groceryList.countList(); //extra credit. service time is based on number of items in grocery list
	customerNumber = _customerNumber;
	totalTime = _totalTime + serviceTime;
	entryTime = _entryTime;
}
Data::~Data()
{
}
int Data::getCustomerNumber()
{
	return customerNumber;
}
int Data::getServiceTime()
{
	return serviceTime;
}
int Data::getTotalTime()
{
	return totalTime;
}
int Data::getEntryTime()
{
	return entryTime;
}
void Data::setCustomerNumber(int _customerNumber)
{
	customerNumber = _customerNumber;
}
void Data::setServiceTime(int _serviceTime)
{
	serviceTime = _serviceTime;
}
void Data::setTotalTime(int _totalTime)
{
	totalTime = _totalTime;
}
void Data::setEntryTime(int _entryTime)
{
	entryTime = _entryTime;
}
#pragma endregion