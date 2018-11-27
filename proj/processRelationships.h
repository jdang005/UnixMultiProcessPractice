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
				the processRelationships.c source code file.

Libraries     : stdio.h 	
					- Used for common input/output definitions 
				stdlib.h 	
					- Used for common c definitions
				unistd.h 	
					- Used for miscellaneous c definitions 
				stdbool.h 	
					- Used to define a simple boolean type
				limits.h 	
					- Used define type limitations
				string.h 	
					- Used to define string functions
				sys/types.h 
					- Used to define c types based on the current system

Constants     : NUM_INIT	
					- Regular numerical type initialization value is zero. (0)
				EXEC_END
					- The end status of a successful process. (0)
				MAX_STR_BUFF
					- The maximum size for string input, constrained by the 
					  standard size of the unix console. (80)

Function	  : bool parentProcess(int, const char * *);
Prototypes		bool childProcess(int);

Required      : None
Features Not
Included

Known Bugs    : None
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
#include <sys/ipc.h>
#include <sys/shm.h>

#define NUM_INIT 0
#define EXEC_END 0
#define MAX_STR_BUFF 80

bool parentProcess(int, const char * *);
bool childProcess(int);

#endif /* processRelationships_h */