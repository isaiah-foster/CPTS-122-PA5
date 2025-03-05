#pragma once
#include "queue.hpp"
#include <iostream>
#include <Windows.h>
#define SLEEP_TIME 20

class Simulation
{
private:
	Queue<Data> express;
	Queue<Data> normal;
public:
	Simulation();
	~Simulation();
	void runSimulation();
};

#pragma region Member Functions
Simulation::Simulation()
{
	express = Queue<Data>();
	normal = Queue<Data>();
}

Simulation::~Simulation() {}

void Simulation::runSimulation()
{
	srand((unsigned int)time(NULL));

	int firstExpress = rand() % 5 + 1;
	int firstNormal = rand() % 5 + 3;

	int serviceTime = 0;

	int nextExpressArrival = 0;
	int nextNormalArrival = 0;

	int normalCustomerNumber = 0;
	int expressCustomerNumber = 0;

	int expressTotalTime = 0;
	int normalTotalTime = 0;

	for (int i = 0; i < 1440; i++)
	{
		Sleep(SLEEP_TIME);
		//first normal customer makes it to the front of the line
		if (i == firstNormal)
		{
			normalCustomerNumber++;
			serviceTime = rand() % 5 + 3;
			normalTotalTime += serviceTime;
			Data customer(normalCustomerNumber, serviceTime, normalTotalTime, i);
			normal.enqueue(customer);
			nextNormalArrival = i + rand() % 5 + 3;
		}

		//first express customer makes it to the front of the line
		if (i == firstExpress)
		{
			expressCustomerNumber++;
			serviceTime = rand() % 5 + 1;
			expressTotalTime += serviceTime;
			Data customer(expressCustomerNumber, serviceTime, expressTotalTime, i);
			express.enqueue(customer);
			nextExpressArrival = i + rand() % 5 + 1;
		}

		//next normal customer makes it to the line
		if (i == nextNormalArrival)
		{
			normalCustomerNumber++;
			serviceTime = rand() % 5 + 3;
			normalTotalTime += serviceTime;
			Data customer(normalCustomerNumber, serviceTime, normalTotalTime, i);
			normal.enqueue(customer);
			nextNormalArrival = i + rand() % 5 + 3;
			std::cout << "Customer" << customer.getCustomerNumber() << " has arrived to express lane at time " << i << std::endl;

		}

		//next express customer makes it to the line
		if (i == nextExpressArrival)
		{
			expressCustomerNumber++;
			serviceTime = rand() % 5 + 1;
			expressTotalTime += serviceTime;
			Data customer(expressCustomerNumber, serviceTime, expressTotalTime, i);
			express.enqueue(customer);
			nextExpressArrival = i + rand() % 5 + 1;
			std::cout << "Customer" << customer.getCustomerNumber() << " has arrived to express lane at time " << i << std::endl;
		}

		//normal customer at front of line is done
		if (normal.peek().getEntryTime() + normal.peek().getServiceTime() == i)
		{
			std::cout << "Normal customer " << normal.peek().getCustomerNumber() << " serviced after" << normal.peek().getTotalTime() << " minutes" << std::endl;
			normalTotalTime -= normal.peek().getServiceTime();
			normal.dequeue();
			
		}

		//express customer at front of is done
		if (express.peek().getEntryTime() + express.peek().getServiceTime() == i)
		{
			std::cout << "Express customer " << express.peek().getCustomerNumber() << " serviced after" << express.peek().getTotalTime() << " minutes" << std::endl;
			expressTotalTime -= express.peek().getServiceTime();
			express.dequeue();
		}

		//print queues every 10 minutes
		if (i % 10 == 0)
		{
			std::cout << "Time: " << i << std::endl;
			std::cout << "Normal Lane:" << std::endl;
			normal.printQueueRecursive();
			std::cout << "Express Lane:" << std::endl;
			express.printQueueRecursive();
		}

	}
}