#include "tests.hpp"
#include "simulation.hpp"

int main(void)
{
	runTests();
	Simulation sim;
	sim.runSimulation();
	
	return 0;
}