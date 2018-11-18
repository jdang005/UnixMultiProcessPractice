/*
Source Code   : sharedProcessMain.c
Author        : Justin Danglade
Student ID    : 4552415
Course        : COP4338
Section       : U04
Instructor    : William Feild
Due Date      : November 29, 2018

I hereby certify that this collective work is my own and none of it is the work
of any other person or entity.

______________________________

Language      : C

Compile/Run   : gcc -o SharedProcess sharedProcessMain.c processRelationships.c
				./SharedProcess [0 < int > 10: arg1 ... 0 < int > 10: arg7)

				- SharedProcess uses integer arguments from the command line, 
				  there must at least one and at most seven integer arguments. 
				  Each integer must be within the range 0 to 9(inclusive).

Description   : 

Function 	  : bool validateCommandInput(int, char * *);
Definitions			- used to validate the terminal command input.
				

Input         : 

Output        : 

Process       : 

Required      : 
Features Not
Included

Known Bugs    : 
*/

#include "processRelationships.h"

int main(int argc, const char * argv[])
{

}


/*
	

	Input	  = {}
	Output	  = {}
*/
bool validateCommandInput(int numOfArgs, const char * commandArgs[])
{
	bool isValidInput = false;
	
}

/*
	Verifies that the character pointer inputChar valid, inputChar valid if it 
	is pointing to a sequence of characters that is within the range min to 
	max(inclusive). 

	Returns true if inputChar is valid, false if it is not.

	Input	  = {char *: inputChar, int min, int max}
	Output	  = {bool: isValid}
*/
bool validateCharToInt(char * inputChar, int min, int max)
{	
	bool isValid = false;

}