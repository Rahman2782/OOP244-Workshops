#define _CRT_SECURE_NO_WARNINGS


//population.cpp

#include "Population.h"
#include "File.h"
#include <fstream>
#include <iostream>


using namespace std;
namespace seneca {

	Population* population_data = nullptr;
	size_t numOfRecords{};

	//opens the file, returns an error if it cannot open
	bool load(const char filename[]) {
		if (!openFile(filename)) {
			cerr << "Could not open the data file: " << filename << endl;
			return false;
		}
		//after file is opened counts the number of records in the file
			//and allocates memory to the size of the records
		numOfRecords = noOfRecords();
		population_data = new Population[numOfRecords];
		if (!population_data) {
			cerr << "Memory allocation failed." << endl;
			closeFile();
			return false;
		}

		for (size_t i = 0; i < numOfRecords; i++) {
			if (fscanf(fptr, "%3[^,],%d\n", population_data[i].postalCode, &population_data[i].population) != 2) {
				cerr << "ERROR reading data" << endl;
				delete[] population_data;
				population_data = nullptr;
				closeFile();
				return false;
			}
			
		}
		closeFile();
		return true;
	}

	void display() {
		cout << "Postal Code: Population  " << endl
			<< "------------------------- " << endl;
		int totalPopulation{};
		for (size_t i = 1; i < numOfRecords; i++) {
			cout << i << "- " << population_data[i].postalCode << ":  " 
				<< population_data[i].population << endl;

			
			totalPopulation += population_data[i].population;
		}

		cout << "------------------------ - " << endl
			<< "Population of Canada: " << totalPopulation << endl;

	}

	void deallocateMemory() {
		delete[] population_data;
		population_data = nullptr;
	}
}