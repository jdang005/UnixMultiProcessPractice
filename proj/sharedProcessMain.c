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
				bool validateCharToInt(char * input, int min, int max)
					- used to validate that a character pointer is pointing to 
					  a sequence of characters that can be converted into and 
					  integer within the minimum and maximum boundaries defined 
					  by the two integer arguments.
				
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
	Verifies that the command input provided at execution time is valid. Valid 
	numOfArgs is a number between two and eight(inclusive) and valid commandArgs 
	is an array of numOfArgs strings each of which can be converted into an 
	integer between zero and nine(inclusive).

	Input	  = {int numOfArgs, const char * commandArgs[]}
	Output	  = {bool: isValid}
*/
bool validateCommandInput(int numOfArgs, const char * commandArgs[])
{
	bool isValid = false;
	
}

/*
	Verifies that the character pointer input valid, input valid if it 
	is pointing to a sequence of characters that can be converted into an 
	integer that is within the range min to max(inclusive). 

	Returns true if input is valid, false if it is not.

	Input	  = {char *: input, int min, int max}
	Output	  = {bool: isValid}
*/
bool validateCharToInt(char * input, int min, int max)
{	
	bool isValid = false;
	int strPos = NUM_INIT;
  	int digits = NUM_INIT;
  	long longStorage = NUM_INIT;
  	bool negativeNum = false;

  	if(input == NULL || min > max)
  	{
  		return false;
  	}
  	/* Count the number of digits in possibleInt. */
  	while(input[strPos] != '\0' &&  input[strPos] != EOF)
  	{
    	/*
      		If the character being inspected is a digit, increment the number of
      		digits counted.
    	*/
    	if(input[strPos] > 47 && input[strPos] < 58)
    	{
      		digits ++;
      		strPos ++;
    	}
    	else
    	{
      		/* check for a single predicate negative symbol */
      		if(input[strPos] == '-' && digits == NUM_INIT)
      		{
        		if(negativeNum == true)
        		{
          			return false;
        		}
        		negativeNum = true;
        		strPos ++;
      		}
      		else if(input[strPos] != '\0' &&  
      				input[strPos] != EOF)
      		{
        		/*
          			If any other symbol other than the null character or EOF 
          			interupts the string, the string is not an int.
        		*/
        		return false;
      		}
    	}
  	}
  	/*
    	If the number of digits in the string is beyond the maximum buffer size 
    	for a string, the string is not an int.
  	*/
  	if(digits > MAX_STR_BUFF)
  	{
  	  return false;
  	}
  	/* Exclude values outside the range of min...max */
  	longStorage = atol(input);
  	if(longStorage < min || longStorage > max)
  	{
    	return false;
  	}
  	return true;
}