// ProcessorSimulator.cpp : Defines the entry point for the application.
//

#include "ProcessorSimulator.h"
#include "../Lib/Constructions/Elementary.hpp"

using namespace std;

int main()
{
	Or or1;
	cout << or1.Calculate(false, false) << endl;
	cout << or1.Calculate(false, true) << endl;
	cout << or1.Calculate(true, false) << endl;
	cout << or1.Calculate(true, true) << endl;
	cout << "Hello CMake." << endl;
	return 0;
}
