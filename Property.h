#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

using namespace std;

class Property
{
public:
	/*
	The constructor and deconstructor for objects of type Property.

	@param rented: Whether or not the property is a rental.
	@param value: the estimated value of the property
	@param address: The address of the property
	*/
	Property(string address, bool rented, double value);
	virtual ~Property();

	/*
	toString() displays a formatted string displaying all valid information about the Property.

	@return: string displaying all valid information about the Property
	*/
	virtual string toString();
	
	/*
	giveValue() returns the value of the Property.

	@return: Estimated value of the property
	*/
	double giveValue() const;
	
	/*
	giveRented() returns the status of a rental as a string of the Property.

	@return: Rental if a rental, Not Rental if not a rental
	*/
	string giveRented() const;
	
	/*
	giveAddress() returns the address of the Property.

	@return: address as a string
	*/
	string giveAddress() const;
	
	/*
	givePropertyID() returns the Property ID of the Property.

	@return:Property ID
	*/
	int givePropertyID() const;
	
	/*
	Pure Virtual function. 

	@return: Returns the tax report.
	*/
	virtual string taxes() = 0;

private:
	string address;
	bool rented;
	double value;
	static int numOfHouses;
	int propertyID;
};