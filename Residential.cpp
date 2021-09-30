#include "Residential.h"

Residential::Residential(bool rented, double value, bool notVacant, string address)
	:Property(address, rented, value)
{
	this->notVacant = notVacant;
}
Residential::~Residential(){};

string Residential::taxes()
{
	const double RESIDENTIAL_TAX_RATE_RENTAL = 0.006;
	const double RESIDENTIAL_TAX_RATE_NON_RENTAL = 0.009;
	double actualTax = 0;
	if (this->notVacant)
	{
		actualTax = Property::giveValue() * RESIDENTIAL_TAX_RATE_RENTAL;
	}
	else
	{
		actualTax = Property::giveValue() * RESIDENTIAL_TAX_RATE_NON_RENTAL;
	}
	stringstream ss;
	ss << "	** Taxes due for the property at : " << this->giveAddress() << endl
		<< "\t\t Property id : " << this->givePropertyID() << endl
		<< "\t\t This property has an estimated value of : " << this->giveValue() << endl
		<< "\t\t Taxes due on this property are : " << actualTax << endl << endl;
	return ss.str();
}
string Residential::getNotVacant()
{
	if (this->notVacant)
	{
		return "Occupied";
	}
	else
	{
		return "Vacant";
	}
}
string Residential::toString()
{
	stringstream ss;
	ss << Property::toString() << " " << this->getNotVacant() << endl;
	return ss.str();
}