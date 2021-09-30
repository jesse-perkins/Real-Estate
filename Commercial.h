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

class Commercial : public Property
{
public:

	/*
	The constructor and deconstructor for objects of type Residential.

	@param rented: Whether or not the property is a rental.
	@param value: the estimated value of the property
	@param taxBreak: True if the property gets a tax break.
	@param taxBreakPercentage: The percentage of the tax break.
	@param address: The address of the property
	*/
	Commercial(bool rental, double value, bool taxBreak, double taxBreakPercentage, string address);
	~Commercial();

	/*
	giveTaxBreak() returns whether or not the Commercial Property gets a tax break.

	@return: A string containing "Discounted" or "Not Discounted"
	*/
	string giveTaxBreak();

	/*
	toString() displays a formatted string displaying all valid information about the Commercial Object.

	@return: string displaying all valid information about the Commercial Object
	*/
	virtual string toString();
	
	/*
	taxes() displays a formatted string displaying all valid information about the taxes for a commercial object.

	@return: string displaying all valid information about the taxes for a commercial object.
	*/
	string taxes();
private:
	bool taxBreak;
	double taxBreakPercentage;
};