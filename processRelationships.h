/*
Source Code   : processRelationships.h
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

Description   : This header file is used to include several libraries, several 
				constants, as well as to prototype several functions defined in 
				the processRelationships.c and sharedProcessMain.c source code 
				files.

Libraries     : stdio.h 	
					- used for common input/output definitions 
				stdlib.h 	
					- used for common c definitions
				unistd.h 	
					- used for miscellaneous c definitions 
				stdbool.h 	
					- used to define a simple boolean type
				limits.h 	
					- used define type limitations
				string.h 	
					- used to define string functions
				sys/types.h 
					- used to define c types based on the current system

Constants     : MAX_ARGS 	
					- The maximum number of command arguments is seven. (7)
				MIN_ARGS 	
					- The minimum number of command arguments is one. (1)
				MAX_ARGVAL  
					- The maximum value for any of the command arguments is 
					  nine. (9)
				NUM_INIT	
					- Regular numerical type initialization value is zero. (0)

Function	  : bool validateCommandInput(int, char * *);
Prototypes			- used to validate the terminal command input.
				bool validateCharToInt(char *, int, int);
					- used to validate that a character pointer is pointing to 
					  the address of a character that can be converted into and 
					  integer within the minimum and maximum boundaries defined 
					  by the two integer arguments.
				bool parentProcess();
					- 
				bool childProcess(int);
					-
Required      : 
Features Not
Included

Known Bugs    : 
*/

#ifndef processRelationships_h
#define processRelationships_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>

#define MAX_ARGS 7
#define MIN_ARGS 1
#define MAX_ARGVAL 9
#define NUM_INIT 0

bool validateCommandInput(int, const char * *);
bool validateCharToInt(char *, int, int);
bool parentProcess();
bool childProcess(int);

#endif processRelationships_h