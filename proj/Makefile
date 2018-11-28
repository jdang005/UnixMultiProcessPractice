#File 		   : Makefile
#Author        : Justin Danglade
#Student ID    : 4552415
#Course        : COP4338
#Section       : U04
#Instructor    : William Feild
#Due Date      : November 29, 2018

#-------------------------------------------------------------------------------
#I hereby certify that this collective work is my own and none of it is the work
#of any other person or entity.

#______________________________


#Language      : Unix make file

#Compile/Run   : make all

#Description   : This make file is intended to be used on a Unix system with the
#                gcc compiler for C99.

#Input         : "sharedProcessMain.c", "processRelationships.c", and 
#				 "processRelationships.h"
#                	- These must be located within the same directory as this 					
#                	  make file.

#Output        : "SharedProcess" 
#					- An executable file.

#Process       : The make file uses gcc to compile the c files 
#				 sharedProcessMain.c and processRelationships.c, then links the 
#				 object file with the header files processRelationships.h, 
#				 stdio.h, stdlib.h, unistd.h, stdbool.h, limits.h, string.h, and 
#				 sys/types.h, sys/ipc.h, sys/shm.h creating the executable file 
#				 SharedProcess.

#Required      : None
#Features Not
#Included

#Known Bugs    : None
#-------------------------------------------------------------------------------

# Create variables
App_1 = SharedProcess
HdrFile = processRelationships.h
CCo = gcc -o
Src_1 = sharedProcessMain.c
Src_2 = processRelationships.c

# Enable multiple build targets
all: $(App_1)

# Make instructions
# Build executable files
$(App_1): $(Src_1) $(Src_2) $(HdrFile)
	$(CCo) $(App_1) $(Src_1) $(Src_2)
clean:
	rm *.o
