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

Description   : SharedProcess first allocates a block of shared memory, a space 
				necessary to hold one integer for every command-line argument 
				that was provided as input, there must be at least one and at 
				most seven integers provided as command-line arguments. Each of 
				these integers must be between the numbers zero and nine. Next 
				SharedProcess populates this block of shared memory with the 
				command-line arguments, displays the memory, and for every 
				command-line argument, forks a child process that is provided a 
				unique location in the shared memory as input, while printing 
				trace statements. The child process multiplies it's unique 
				location number by the argument stored in the shared memory 
				location and stores the result in the same location, while 
				printing trace statements, terminating when finished. The 
				parentProcess waits for all children to finish execution before
				reprinting the shared memory then detaching and removing the 
				shared memory.

Input         : Command arguments: {int argc, const char * argv[]}
				
Output        : Standard out: Various trace statements from both the parent 
				process and child processes.

				Standard error: Error statements based on function and process 
				termination

Process       : sharedProcessMain prints simple parent process trace statements
				and calls the validateCommandInput function and the 
				parentProcess fuction. If any of the functions fail the main 
				function prints error statements to standard error output 
				stream.

Required      : None
Features Not
Included

Known Bugs    : None
*/

#include "processRelationships.h"

/*
	Performs basic function calls for the sharedProcess application.

	Input	  = {int argc, const char * argv[]}
	Output	  = {int EXEC_END}
*/
int main(int argc, const char * argv[])
{	
	/* Define constants and variables */
	bool sharedProcess = false;
	const int NUMOFMESSAGES = 2;
	char * STANDARDMESSAGES[NUMOFMESSAGES];
	STANDARDMESSAGES[0] = "Parent: starts";
	STANDARDMESSAGES[1] = "Parent: validate command line";

	/* Print trace statements */
	char * message = STANDARDMESSAGES[0];
	fprintf(stdout, "%s\n", message);
	fflush(stdout);

	message = STANDARDMESSAGES[1];
	fprintf(stdout, "%s\n", message);
	fflush(stdout);

	/* Validate command-line input */
	const bool VALID = validateCommandInput(argc, argv);
	if(VALID == true)
	{	
		/* Run parent process  */
		sharedProcess = parentProcess(argc, argv);
		if(sharedProcess == false)
		{
			return EXEC_END - 1;
		}
	}
	else
	{
		printErrorMessage(NUM_INIT);
		return EXEC_END - 1;
	}
	return EXEC_END;
}