#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

class Data
{
public:
	Data();
	Data(int _customerNumber, int _serviceTime, int _totalTime, int _entryTime);
	~Data();
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();
	int getEntryTime();
	void setCustomerNumber(int customerNumber);
	void setServiceTime(int serviceTime);
	void setTotalTime(int totalTime);
	void setEntryTime(int entryTime);
	void printData();
private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in
	// minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line
	// before this customer; units in minutes
	int entryTime; // Time that the customer enters the line; units in minutes
};

#pragma region Data Members
Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}
Data::Data(int _customerNumber, int _serviceTime, int _totalTime, int _entryTime)
{
	customerNumber = _customerNumber;
	serviceTime = _serviceTime;
	totalTime = _totalTime;
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
void Data::printData()
{

}
#pragma endregion