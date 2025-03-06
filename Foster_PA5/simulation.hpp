/*File: simulation.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA5
* Created: 03/02/2025
* Last updated: 03/05/2025
* Description: Defines simulation class to simulate a grocery store with express and normal lanes
*/
#pragma once
#include "queue.hpp"
#define SLEEP_TIME .01


class Simulation
{
private:
	Queue<Data> express;
	Queue<Data> normal;
public:
	Simulation();
	~Simulation();
	void runSimulation(int run_minutes);
};

Simulation::Simulation()
{
	express = Queue<Data>();
	normal = Queue<Data>();
}

Simulation::~Simulation() 
{
}

//runs a simulation for a user given number of minutes
void Simulation::runSimulation(int run_minutes)
{
	srand((unsigned int)time(NULL));

	int nextNormalArrival = rand() % 5 + 3;
	int nextExpressArrival = rand() % 5 + 1;

	int normalCustomerNumber = 0;
	int expressCustomerNumber = 0;

	int normalTotalTime = 0;
	int expressTotalTime = 0;

	for (int elapsed_time = 0; elapsed_time < run_minutes; elapsed_time++)
	{
		Sleep(SLEEP_TIME); //pause between iterations

		//next normal customer makes it to the line
		if (elapsed_time == nextNormalArrival)
		{
			normalCustomerNumber++;
			Data customer(normalCustomerNumber, normalTotalTime, elapsed_time);
			normalTotalTime += customer.getServiceTime();
			normal.enqueue(customer);
			nextNormalArrival = elapsed_time + rand() % 5 + 3;
			std::cout << "Normal customer " << customer.getCustomerNumber() << " has arrived at time " << elapsed_time << std::endl;
		}

		//next express customer makes it to the line
		if (elapsed_time == nextExpressArrival)
		{
			expressCustomerNumber++;
			Data customer(expressCustomerNumber, expressTotalTime, elapsed_time);
			expressTotalTime += customer.getServiceTime();
			express.enqueue(customer);
			nextExpressArrival = elapsed_time + rand() % 5 + 1;
			std::cout << "Express customer " << customer.getCustomerNumber() << " has arrived at time " << elapsed_time << std::endl;
		}

		//normal customer at front of line is done
		if (normal.peek().getEntryTime() + normal.peek().getTotalTime() <= elapsed_time && !normal.isEmpty())
		{
			std::cout << "Normal customer " << normal.peek().getCustomerNumber() << " serviced after " << normal.peek().getTotalTime() << " minutes" << std::endl;
			normalTotalTime -= normal.peek().getServiceTime();
			normal.dequeue();
		}

		//express customer at front of line is done
		if (express.peek().getEntryTime() + express.peek().getTotalTime() <= elapsed_time && !express.isEmpty())
		{
			std::cout << "Express customer " << express.peek().getCustomerNumber() << " serviced after " << express.peek().getTotalTime() << " minutes" << std::endl;
			expressTotalTime -= express.peek().getServiceTime();
			express.dequeue();
		}

		//print queues every 10 minutes
		if (elapsed_time % 10 == 0 && elapsed_time!=0)
		{
			std::cout << "Time: " << elapsed_time << std::endl;
			std::cout << "Normal Lane Customers:" << std::endl;
			normal.printQueueRecursive();
			std::cout << "Express Lane Customers:" << std::endl;
			express.printQueueRecursive();
		}
	}
}