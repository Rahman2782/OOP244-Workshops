#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {

	void reverse() {
		size_t size{};
		cout << "Enter the number of double values: \n> ";
		cin >> size;

		double* dArray = new double[size];
		for (size_t i = 0; i < size; i++) {
			cout << i + 1 << "> ";
			cin >> dArray[i];
		}
		for (size_t i = size; i > 0; i--) {
			cout << dArray[i-1] << endl;
		}

		delete[] dArray;
	}

	Contact* getContact() {
		Contact* newContact = new Contact;

		cout << "Name: ";
		cin >> newContact->m_name;
		cout << "Last name: ";
		cin >> newContact->m_lastname;
		cout << "Phone number: ";
		cin >> newContact->m_phoneNumber;

		return newContact;
	}

	void display(const Contact& d) {
		cout << d.m_name << " " << d.m_lastname << ", +" << d.m_phoneNumber << endl;
	}

	void deallocate(Contact* d) {
		delete d;
		d = nullptr;
	}

	void setEmpty(Contact& d) {
		*d.m_name = '\0';
		*d.m_lastname = '\0';
		d.m_phoneNumber = 0;
	}




}
