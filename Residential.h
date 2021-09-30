#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "Property.h"

using namespace std;

class Residential : public Property
{
public:
	
	/*
	The constructor and deconstructor for objects of type Residential.

	@param rented: Whether or not the property is a rental.
	@param value: the estimated value of the property
	@param notVacant: If occupied, this is true.
	@param address: The address of the property
	*/
	Residential(bool rented, double value, bool notVacant, string address);
	~Residential();

	/*
	toString() displays a formatted string displaying all valid information about the Residential Object.

	@return: string displaying all valid information about the Residential Object
	*/
	virtual string toString();

	/*
	taxes() displays a formatted string displaying all valid information about the taxes for a residential object.

	@return: string displaying all valid information about the taxes for a residential object.
	*/
	string taxes();

	/*
	getNotVacant() returns whether or not the residential property is vacant.

	@return: a string containing "Occupied" or "Vacant"
	*/
	string getNotVacant();
private:
	bool notVacant;
};