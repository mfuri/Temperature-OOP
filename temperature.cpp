//	Michael Tafuri
//	COP3330-0001
#include <iostream>
#include "temperature.h"
#include <iomanip>

using namespace std;

Temperature::Temperature() // Default constructor
{
	degrees = 0;
	scale = 'C';
}

Temperature::Temperature(double deg, char s)	//Constructor for user-entry
{
	if (Temperature::Set(deg,s) == false)
	{
		degrees = 0;
		scale = 'C';
	}
}

void Temperature::Input() //	User enters valid temperature
{
	double deg;
	char s;


	cout << "Please enter degrees and scale: ";
	cin >> deg >> s;
	while (Temperature::Set(deg,s) == false)
	{
		cout << "Invalid entry, please try again: ";
		cin >> deg >> s;
	}

}

void Temperature::Show() const	// Displays temperature in set format
{
	switch (format)
	{
		case 'P':
		{
			int oldprecision = cout.precision();
			cout << setprecision(1) << degrees << scale << endl;
			cout.precision(oldprecision);
			break;
		}

		case 'L':
			cout << degrees << " ";
			switch (scale)
			{
				case 'C':
					cout << "Celsius" << endl;
					break;
				case 'F':
					cout << "Fahrenheit" << endl;
					break;
				case 'K':
					cout << "Kelvin" << endl;
					break;
			}
			break;

		default:
			cout << degrees << " " << scale << endl;
			break;
	}
}

bool Temperature::SetFormat(char f) // Sets format of scale/temperature
{
	f = toupper(f);
	switch (f)
	{
		case 'D':
			format = f;
			return true;
			break;
		case 'P':
			format = f;
			return true;
			break;
		case 'L':
			format = f;
			return true;
			break;
		default:
			return false;
			break;
	}
}

double Temperature::GetDegrees() const //Accesses degrees
{
	return degrees;
}

char Temperature::GetScale() const //Accessess scale
{
	return scale;
}

bool Temperature::Set(double deg, char s) //Checks if valid temperature and scale is passed through
{
	s = toupper(s);
	if (s == 'C'||s == 'F' || s == 'K')
	{
		scale = s;
		switch (scale)
		{
			case 'C':
				if (deg < -273.15)
					return false;
				else
				{
					degrees = deg;
					return true;
				}
				break;
			case 'F':
				if (deg < -459.67)
					return false;
				else
				{
					degrees = deg;
					return true;
				}
				break;
			case 'K':
				if (deg < 0)
					return false;
				else
				{
					degrees = deg;
					return true;
				}
		}
	}
	else
		return false;
}

bool Temperature::Convert(char sc) // Converts from one scale to another
{
	sc = toupper(sc);
	switch (scale)
	{
		case 'C':
			switch (sc)
			{
				case 'F':
					degrees = (degrees * 9/5) + 32;
					scale = sc;
					return true;
					break;
				case 'K':
					degrees = degrees + 273.15;
					scale = sc;
					return true;
					break;
				default:
					return false;
			}
		case 'F':
			switch (sc)
			{
				case 'C':
					degrees = (degrees - 32) * 5/9;
					scale = sc;
					return true;
					break;
				case 'K':
					degrees = ((degrees - 32) * 5/9) + 273.15;
					scale = sc;
					return true;
					break;
				default:
					return false;
			}
		case 'K':
			switch (sc)
			{
				case 'C':
					degrees = degrees - 273.15;
					scale = sc;
					return true;
					break;
				case 'F':
					degrees = ((degrees - 273.15) * 9/5) + 32;
					scale = sc;
					return true;
					break;
				default:
					return false;
			}
	}
}

int Temperature::Compare(const Temperature& d) const //Compares values of temperatures
{
	Temperature Temp = d;
	switch (GetScale())
	{
		case 'C':
			Temp.Convert('C');
			return DegCompare(GetDegrees(),Temp.GetDegrees());
			break;
		case 'F':
			Temp.Convert('F');
			return DegCompare(GetDegrees(),Temp.GetDegrees());
			break;
		case 'K':
			Temp.Convert('K');
			return DegCompare(GetDegrees(),Temp.GetDegrees());
			break;

	}
}

int Temperature::DegCompare(double original, double comp) const //Compares degrees for compare function above
{
	if (original > comp)
	{
		return 1;
	}
	if (original == comp)
	{
		return 0;
	}
	if (original < comp)
	{
		return -1;
	}
}
