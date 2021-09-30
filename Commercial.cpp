#include "Commercial.h"

Commercial::Commercial(bool rented, double value, bool taxBreak, double taxBreakPercentage, string address)
	:Property(address, rented, value)
{
	this->taxBreak = taxBreak;
	this->taxBreakPercentage = taxBreakPercentage;
}
Commercial::~Commercial(){};

string Commercial::taxes()
{
	const double COMMERCIAL_TAX_RATE_RENTAL = 0.012;
	const double COMMERCIAL_TAX_RATE_NON_RENTAL = 0.01;
	double actualTax = 0;
	double gimmeATaxBreak = 1;
	if (this->taxBreak)
	{
		gimmeATaxBreak = (1- taxBreakPercentage);
	}
	if (this->giveRented() == "Rental")
	{
		actualTax = Property::giveValue() * COMMERCIAL_TAX_RATE_RENTAL * gimmeATaxBreak;
	}
	else
	{
		actualTax = Property::giveValue() * COMMERCIAL_TAX_RATE_NON_RENTAL * gimmeATaxBreak;
	}
	stringstream ss;
	ss << "	** Taxes due for the property at : " << this->giveAddress() << endl
		<< "\t\t Property id : " << this->givePropertyID() << endl
		<< "\t\t This property has an estimated value of : " << this->giveValue() << endl
		<< "\t\t Taxes due on this property are : " << actualTax << endl << endl;
	return ss.str();
}

string Commercial::giveTaxBreak()
{
	if (this->taxBreak)
	{
		return "Discounted";
	}
	else
	{
		return "Not Discounted";
	}
}

string Commercial::toString()
{

	stringstream ss;
	if (taxBreak)
	{
		ss << Property::toString() << " " << this->giveTaxBreak() << " Discount " << taxBreakPercentage << endl;
	}
	else
	{

		ss << Property::toString() << " " << "Not Discounted" << endl;
	}
	return ss.str();
}