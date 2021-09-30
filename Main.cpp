#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "Property.h"
#include "Commercial.h"
#include "Residential.h"

using namespace std;

/*
DisplayAddresses takes a vector of type Property* and calls the toString() for each item in the vector.

@return: VOID
*/
void displayAddresses(vector<Property*>& input)
{
	cout << "All Valid Properties: \n\n";
	for (int i = 0; i < input.size(); i++)
	{
		cout << input[i]->toString() << endl << endl;
	}
}

/*
LoadFile prompts the user for input and checks to see if the file exists. If it does not, it returns -1.
Otherwise, loadFile begins to load data line by line from the selected file. If loadFile encounters 
any errors such as incorrect type, line too short or line improperly formatted, it throws an error,
prints the offending line and moves on to the next. After error checking each line, if the line is 
properly formatted, load file creates a pointer of type residential or commercial and loads it into the 
passed in vector.

@return: 0 if succesfully loaded, -1 if not.
*/
int loadFile(vector <Property*>& vectProp)
{
	cout << "ENTER FILE TO LOAD: ";
	string fileName;
	cin >> fileName;
	cout << endl;
	ifstream loadMe;
	loadMe.open(fileName);
	string type = "";
	string address = "";
	bool rented = NULL;
	double value = 0;
	bool taxBreak = NULL;
	double taxBreakPercentage = 0;
	bool notVacant = NULL;
	Property* p = NULL;
	stringstream ss;
	string holder;
	bool failed = false;
	if (loadMe.fail())
	{
		return -1;
	}
	getline(loadMe, holder, '\n');
	ss << holder;
	while (!loadMe.fail())
	{
		ss >> type;
		if ((type != "Residential") && (type != "Commercial"))
		{
			cout << "Ignoring unknown types of properties appearing in the input file: " << holder << endl << endl;
			failed = true;
		}
		ss >> rented;

		ss >> value;

		if (type == "Residential")
		{
			ss >> notVacant;

		}
		else if (type == "Commercial")
		{
			ss >> taxBreak;

			ss >> taxBreakPercentage;

		}
		
		getline(ss, address);

		if (ss.fail() && !failed)
		{
			cout << "Ignoring bad " << type << " in input file : " << holder << endl << endl;
			failed = true;
		}
		if (!failed)
		{
			if (type == "Residential")
			{
				p = new Residential(rented, value, notVacant, address);
			}
			else
			{
				p = new Commercial(rented, value, taxBreak, taxBreakPercentage, address);
			}
			vectProp.push_back(p);
		}
		getline(loadMe, holder, '\n');
		ss.str("");
		ss.clear();
		ss << holder;
		failed = false;
	}
	return 0;
}

/*
taxesOut takes a vector of type Property* and calls all their taxes().

@return: VOID
*/
void taxesOut(vector <Property*> allProperties)
{
	cout << "NOW PRINTING TAX REPORT : \n\n";
	for (int i = 0; i < allProperties.size(); i++)
	{
		cout << allProperties[i]->taxes();
	}
}

/*
main creates a vector of type Property* and tells the other functions to run. It also checks for loading of nonexistant files.

@return: 0 
*/
int main()
{
	vector <Property*> allProperties;
	int didIWork = loadFile(allProperties);
	if (didIWork == 0)
	{
		displayAddresses(allProperties);
		taxesOut(allProperties);
	}
	else
	{
		cout << "\nERROR. FILE NOT FOUND \n\n";
	}
	system("pause");
	return 0;
}