#include "data.hpp"
#include "queue.hpp"
using std::string;

void runTests();
int testEnqueue0();
int testEnqueue1();

void runTests()
{
	testEnqueue0();
	testEnqueue1();
}


//Tests enqueue for empty queue and then resulting 1 member queue
int testEnqueue0()
{
	Queue<Data> Q;
	Data first(3,5,10);
	Q.enqueue(first);
	
}

//Tests enqueue for 1 member queue and then dequeue on the resulting 2 member queue
int testEnqueue1()
{
	Queue<Data> Q;
	Data first(3, 5, 10);
	Q.enqueue(first);
}