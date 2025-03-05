#include "tests.hpp"

int main(void)
{
	runTests();
	system("pause");
	system("CLS");

	Simulation sim;
	sim.runSimulation(480); //run simulation for 8 hours
	std::cout << "\nEight hour Simulation complete" << std::endl;
	// to change time of simulation iterations, edit SLEEP_TIME macro in simulation.hpp
	
	return 0;
}