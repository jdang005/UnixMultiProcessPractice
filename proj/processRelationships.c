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

Function 	  : bool parentProcess();
Definitions			- Responsible for allocating shared memory based on the 
					  command-line arguments, attaching the shared memory to its 
					  own address space, filling that memory with the 
					  command-line arguments and forking child processes. The 
					  parentProcess function will display the initial state of 
					  the shared memory, store and display the PID and exit 
					  codes of all executed child processes, display the final 
					  state of the shared memory, detach and removes the shared 
					  memory and then returns true with successful execution, 
					  false otherwise. 
				bool childProcess(int memoryIndex);
					- Responsible for first displaying the initial state of the 
					  shared memory and the unique ID assigned to the child 
					  process. The child process then locates the memory 
					  associated with its own unique ID within the shared 
					  memory, multiplies the initial value by its unique ID, 
					  then updates that shared memory location with the value. 
					  Each child will then display the current state of the 
					  shared memory, provide their exit PID & exit code, and 
					  then returns true with successful execution, false 
					  otherwise. 
				bool runProcesses(int numOfArgs, const char * commandArgs[]);
					- 
Required      : 
Features Not
Included

Known Bugs    : 
*/

#include "processRelationships.h"

/*
	

	Input	  = {}
	Output	  = {bool: }
*/
bool parentProcess()
{
	bool success = false;
	
}

/*
	

	Input	  = {}
	Output	  = {bool: }
*/
bool childProcess(int memoryIndex)
{
	bool success = false;

}

/*
	

	Input	  = {}
	Output	  = {bool: }
*/
bool runProcesses(int numOfArgs, const char * commandArgs[])
{
	bool success = false;

}

