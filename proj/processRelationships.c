/*
Source Code   : processRelationships.c
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

Compile/Run   : N/A

Description   : This source code file is a collection of function definitions 
				that were declared in the processRelationship.h header file.

Function 	  : bool parentProcess(int numOfArgs, const char * commandArgs[]);
Definitions		bool childProcess(int memoryIndex);

Required      : 
Features Not
Included

Known Bugs    : 
*/

#include "processRelationships.h"

/*
	

	Input	  = {int: numOfArgs, const char * *: commandArgs}
	Output	  = {bool: success}
*/
bool parentProcess(int numOfArgs, const char * commandArgs[])
{
	bool success = false;
	char * message = "Parent: requests shared memory";
	fprintf(stdout, "%s\n", message);

	message	= "Parent: receives shared memory";
	fprintf(stdout, "%s\n", message);

	message = "Parent: attaches shared memory";
	fprintf(stdout, "%s\n", message);

	message = "Parent: fills shared memory";
	fprintf(stdout, "%s\n", message);

	message = "Parent: displays shared memory";
	fprintf(stdout, "%s\n", message);

	return success;
}

/*
	

	Input	  = {int: memoryIndex}
	Output	  = {bool: }
*/
bool childProcess(int memoryIndex)
{
	bool success = false;

	return success;
}

