/** main.cpp
 *
 *	In this example program, did the following:
 *		- Examined a simple class with 'instance' data-members, a constructor, accessors, mutators.
 *
 *	@author		Andre Agrippa
 *	@studentID  100756090
*/

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

using namespace std;

// class declaration section
class CartesianPoint
{
public:

	/* Constructor: Used to initialize objects
	*	- always the same name as the class
	*	- never have a return type
	*	- called automatically when an obj is instantiated
	*	- should set values for each member variable
	*/
	CartesianPoint(int x = 1, int y = 1) { SetPoint(x, y); }
	


	/* Accessors: Used to query the state of the object
	*	- never modifies the object
	*	- should specify const at the end of the prototype/header
	*/

	// get x
	int GetX() const{ return myX; }
	// get y
	int GetY() const{ return myY; }
	// get the distance between this point and a second point
	// convert the obj to a string
	string ToString() const;

	/* Mutator(s): Used to change the state of the object
	*	- should contain logic to ensure object remains in a valid state.
	*	- typically sets a member variable to a parameter
	*/
	void SetPoint(int x, int y) { SetX(x); SetY(y); }
	double GetDistanceTo(CartesianPoint pointTo) const;

	// set x
	void SetX(int x) { myX = x; }
	// set y,
    void SetY(int y) { myY = y; }
	
	// set point (both x and y)	

private:
	// private data members for the dimensions of the point
	int myX; // x-axis (horizontal) value
	int myY;  // y-axis (vertical) value

};

// main() function
int main()
{
	// Declarations
	// a point called 'origin', initialized to 0, 0
	CartesianPoint origin = CartesianPoint(0, 0);
	CartesianPoint destination;
	// a point called 'destination'
	int inputX; // temporary input variable for x
	int inputY; // temporary input variable for y
	double distance;// to store the distance between two points

	try
	{
		// Input

		// Prompt the user for the coordinates
		cout << "\nEnter coordinates of the destination point: " << endl;
		// prompt for, read, and store x coordinate:
		cout << "X: ";
		inputX = ConsoleInput::ReadInteger();
		destination.SetX(inputX);



		// prompt for, read, and store y coordinate:
		cout << "Y: ";
		inputY = ConsoleInput::ReadInteger();
		destination.SetY(inputY);



		// Processing
		// determine the distance between the two points
		distance = origin.GetDistanceTo(destination);


		// Output 
		// Show the points and the distance
		// formatting
		cout << fixed << setprecision(3) << "/nThe distance between" << origin.ToString()
			 << " and " << destination.ToString() << " is " << distance << "."<< endl; 


	}

	catch (exception& ex)
	{
		cerr << ex.what() << " Ending the program." << endl;
	}

	// done.
	cout << endl << endl;
	return 0;
} // end of main()

// Class definition section

/** GetDistanceTo Method for CartesianPoint class
*	Determines the distance between this point and a second point.
*	@param	pointTo: CartesianPoint
*	@return	the distance as a double
*/
double CartesianPoint::GetDistanceTo(CartesianPoint poinTo) const
{
	// difference between x values
	int xDiff = poinTo.myX - myX;
	// difference between y values
	int yDiff = poinTo.myY - myY;
	
	// return the formula (based on Pythagorean theorem)
	return sqrt((xDiff * xDiff) + (yDiff * yDiff));
	

}

/** ToString Method for CartesianPoint class
*	Converts the obj to a string.
*	@return	the obj state as a string
*/
string CartesianPoint::ToString() const
{
	// declare a stringstream 
	stringstream strOutput;
	// build the string
	strOutput << "(" << myX << ", " << myY << ")";
 	// return the string
	return strOutput.str();
}
