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

Input         : 

Output        : 

Process       : 

Required      : 
Features Not
Included

Known Bugs    : 
*/

#include "processRelationships.h"


/*
	

	Input	  = {}
	Output	  = {}
*/
int main(int argc, const char * argv[])
{	
	char * message = "Parent: starts";
	fprintf(stdout, "%s\n", message);
	message = "Parent: validate command line";
	fprintf(stdout, "%s\n", message);

	const bool VALID = validateCommandInput(argc, argv);
	bool sharedProcess = false;
	if(VALID == true)
	{	
		sharedProcess = parentProcess(argc, argv);
		if(sharedProcess == false)
		{
			return EXEC_END - 1;
		}
		else
		{
			message = "Hello";
			fprintf(stdout, "%s\n", message);
		}
	}
	else
	{
		printErrorMessage(NUM_INIT);
		return EXEC_END - 1;
	}
	return EXEC_END;
}