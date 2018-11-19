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

bool validateCommandInput(int, const char * *);
bool validateCharToInt(char *, int, int);
int copyChars(char [MAX_STR_BUFF + 1], const char *, char);
void printErrorMessage(int);


int main(int argc, const char * argv[])
{
	const bool VALID = validateCommandInput(argc, argv);
	if(VALID == true)
	{
		
	}
	else
	{
		printErrorMessage(NUM_INIT);
	}

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
	char currentArg[MAX_STR_BUFF + 1];
	const char DELIM = '\0';
	int argCounter = NUM_INIT + 1;
	int strLen = NUM_INIT;
	const int MINARGS = 2;
	const int MAXARGS = 8;
	const int MINVAL = 0;
	const int MAXVAL = 9;

	if(numOfArgs >= MINARGS && numOfArgs <= MAXARGS)
	{
		while(argCounter < numOfArgs)
		{
			strLen = copyChars(currentArg, commandArgs[argCounter], DELIM);
			if(strLen != NUM_INIT)
			{
				isValid = validateCharToInt(currentArg, MINVAL, MAXVAL);
				argCounter ++;
			}
			else
			{
				isValid = false;
				argCounter = numOfArgs;
			}	
		}
	}
	return isValid;
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
	bool negativeNum = false;
	int strPos = NUM_INIT;
  	int digits = NUM_INIT;
  	long longStorage = NUM_INIT;

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

/*
  	Copy one seqeuence of characters into the location of a string given a
  	deliminating character. The destination string must allow for complete unix
  	command-line input, 80 character input, plus a single null character at the
  	end to ensure that the char pointer is pointing to a string. A character 
  	count is kept so that the null character is always inserted at the very end 
  	of the sequence in the destination string. The character count is returned.

  	If the source character pointer is NULL or if the deliminator character is 
  	not found within 80 characters, the destination is assigned to null and 0 is
  	returned.

  	Input   = {char [MAX_STR_BUFF + 1], char *, char}
  	Output  = {int}
*/
int copyChars(char dest[MAX_STR_BUFF + 1], const char * src, char delim)
{
	int charCount = NUM_INIT;
  	/* Reject invalid source strings */
  	if(src == NULL)
  	{
    	dest = NULL;
    	return NUM_INIT;
  	}

  	/* 
  		Count the number of characters until the deliminator is found, if the 
  		deliminator is not found within the MAX_STR_BUFF characters 
  		return zero.
  	*/
  	while(src[charCount] != delim || charCount > MAX_STR_BUFF)
  	{
    	charCount ++;
  	}

  	if(charCount > MAX_STR_BUFF)
  	{
    	dest = NULL;
    	return NUM_INIT;
  	}
  	/* 
  		Copy src into the destination array and return its address via a 
  		pointer and make destination a string.
  	*/
  	strncpy(dest, src, charCount);
  	dest[charCount] = '\0';
  	return charCount;
}

/*
  Function that can print multiple termination messages. The modes are used to
  modify the message(s) printed to the standard error stream.

  mode = 0      : Represents invalid command line arguments.
  any other mode: Represents and undefined reason for termination.

  Input   = {int}
  Output  = {void}
*/
void printErrorMessage(int mode)
{
  	char * message1 = '\0';
  	/* Assign message to print */
  	if(mode == NUM_INIT)
  	{
    	/* Additional details are printed */
    	char * message2 = '\0';
    	char * message3 = '\0';

    	message1 = "\nInvalid command input";
    	message2 = "\nThere must be between one and seven command arguments";
    	message3 = "\nEach argument must be an integer between zero and nine\n";
    	fprintf(stderr, "%s%s%s%d", message1, message2, message3);
    	fputs("\0", stderr);
  	}
  	else
  	{
    	/* Undefined reason for termination */
    	message1 = "\nUndefined reason for termination!\n";
    	fprintf(stderr, "%s", message1);
    	fputs("\0", stderr);
  	}
}