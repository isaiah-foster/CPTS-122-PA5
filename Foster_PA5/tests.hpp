#include "data.hpp"
#include "queue.hpp"
using std::string;

void runTests();
bool testEnqueue0();
bool testEnqueue1();

void runTests()
{
	std::cout << testEnqueue0() << std::endl;
	std::cout << testEnqueue1() << std::endl;
}


//Tests enqueue for empty queue and then resulting 1 member queue
bool testEnqueue0()
{
	Queue<Data> Q;
	Data first(3,5,10, 55);
	Q.enqueue(first);
	return Q.dequeue().getCustomerNumber() == first.getCustomerNumber(); //confirms customer number matches
}

//Tests enqueue for 1 member queue and then dequeue on the resulting 2 member queue
bool testEnqueue1()
{
	Queue<Data> Q;
	Data first(3, 5, 10, 90), second(5,3,8, 60);
	Q.enqueue(first);
	Q.enqueue(second); //enqueues second data, testing on a single member queue
	Q.dequeue();
	return Q.dequeue().getCustomerNumber() == second.getCustomerNumber(); 
}