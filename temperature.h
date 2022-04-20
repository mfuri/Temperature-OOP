//	Michael Tafuri
//	COP3330-0001
//--------------- temperature.h ---------------

class Temperature

{
public:
  Temperature (); // Default constructor
	Temperature (double, char);	//Constructor for user input

   // I/O Routines
	 void Show() const;	//displays degrees and scale in chosen format

	 // Setter
	 void Input();	//Takes keyboard input for valid degrees and scale
	 bool Set(double, char); //Checks if passed in values are valid

	 //Mutators
	 bool SetFormat(char); //Sets format of display (D, P, L)
	 bool Convert(char);	//Converts from one scale to another

	 //Accessors
	 double GetDegrees() const;	//Returns degree in double format
	 char GetScale() const; //Returns scale value (C,F,K)
	 int Compare(const Temperature& d) const; //Compares two temperatures based on scale then degrees
	 int DegCompare(double,double) const;	//Takes in two degree values and returns 1, 0, -1

private:
   double degrees;
	 char scale;
	 char format;
};
