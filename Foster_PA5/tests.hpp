#include "data.hpp"
#include "queue.hpp"

void runTests();
int testEnqueue0();
int testEnqueue1();
int testDequeue1();
int testDequeue2();

void runTests()
{
	testEnqueue0();
	testEnqueue1();
	testDequeue1();
	testDequeue2();
}

int testEnqueue0()
{
	Queue emptyQueue;

}