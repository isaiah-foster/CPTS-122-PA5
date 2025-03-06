#include "simulation.hpp"
using std::string;

void runTests();
bool testEnqueue0(); //test enqueue on empty queue and dequeue 1 member queue
bool testEnqueue1(); //test enqueue on 1 member queue and dequeue on 2 member queue
void testSimulation(); //tests a day long simulation 

void runTests()
{
	testSimulation();
	std::cout << "24 hour simulation complete" << std::endl;
	std::cout << "Enqueue0 test status: " << testEnqueue0() << std::endl;
	std::cout << "Enqueue1 test status: " << testEnqueue1() << std::endl;
}


//Tests enqueue for empty queue and then resulting 1 member queue
bool testEnqueue0()
{
	Queue<Data> Q;
	Data first(3, 10, 55);
	Q.enqueue(first);
	return Q.dequeue().getCustomerNumber() == first.getCustomerNumber(); //confirms dequeued customer number matches queued one
}

//Tests enqueue for 1 member queue and then dequeue on the resulting 2 member queue
bool testEnqueue1()
{
	Queue<Data> Q;
	Data first(3, 10, 90), second(5, 8, 60);
	Q.enqueue(first);
	Q.enqueue(second); //enqueues second data, testing on a single member queue
	Q.dequeue();
	return Q.dequeue().getCustomerNumber() == second.getCustomerNumber(); 
}

void testSimulation()
{
	Simulation testSim;
	testSim.runSimulation(1440);
}