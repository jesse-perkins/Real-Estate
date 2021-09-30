#include "Property.h"

int Property::numOfHouses = 0;

Property::Property(string address, bool rented, double value)
{
	this->address = address;
	this->rented = rented;
	this->value = value;
	this->propertyID = numOfHouses;
	numOfHouses++;
}
Property::~Property(){};

double Property::giveValue() const
{
	return value;
}

string Property::giveRented() const
{
	stringstream ss;
	if (this->rented)
	{
		ss << "Rental";
	}
	else
	{
		ss << "NOT Rental";
	}
	return ss.str();
}

string Property::giveAddress() const
{
	return address;
}
int Property::givePropertyID() const
{
	return propertyID;
}
string Property::toString()
{
	stringstream ss;
	ss << "\tProperty id: " << this->givePropertyID() << " " << "Address :" 
		<< address << " " << this->giveRented() << " Estimated Value : " << value;
	return ss.str();
}