#pragma once
#include <iostream>
#include <string>

class Data
{
public:
	Data();
	Data(int customerNumber, int serviceTime, int totalTime);
	~Data();
	int getCustomerNumber();
	int getServiceTime();
	int getTotalTime();
	void setCustomerNumber(int customerNumber);
	void setServiceTime(int serviceTime);
	void setTotalTime(int totalTime);
	void printData();
private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in
	// minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line
	// before this customer; units in minutes
};

#pragma region Data Members
Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}
Data::Data(int _customerNumber, int _serviceTime, int _totalTime)
{
	customerNumber = _customerNumber;
	serviceTime = _serviceTime;
	totalTime = _totalTime;
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
void Data::printData()
{

}


#pragma endregion