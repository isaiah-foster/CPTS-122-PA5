/*File: main.cpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA5
* Created: 03/02/2025
* Last updated: 03/05/2025
* Description: Runs tests, creates and runs a simulation for 8 hours
*/
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