#ifndef SENECA_POPULATION_H_
#define SENECA_POPULATION_H_

#include <fstream>
#include <iostream>
#include <cstring>

namespace seneca {
	struct Population {
		char postalCode[4]; //postal code has 3 characters, + null terminator
		int population; //pop. count
	};

	bool load(const char filename[]);
	void display();
	void deallocateMemory();

}
#endif // SENECA_POPULATION_H_