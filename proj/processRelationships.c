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
Definitions			- Used to aquire shared memory and attach it to it's process 
					  address space, populate the memory, and fork child 
					  processes. After all children have terminated exectution 
					  the function detaches and removes the shared memory.
				void childProcess(int memoryIndex, int * shrdMemPTR);
					- Used to display the shared memory is has access to and 
					  it's own unique ID. Following this the childProcess 
					  function stores the result of multiplying it's unique ID 
					  by the value already stored in the shared memory in the 
					  same shared memory location. Next the function displays 
					  the updated value and it's exit code, then terminates.
				bool validateCommandInput(int, char * *);
					- Used to validate the terminal command input.
				bool validateCharToInt(char * input, int min, int max)
					- Used to validate that a character pointer is pointing to 
					  a sequence of characters that can be converted into and 
					  integer within the minimum and maximum boundaries defined 
					  by the two integer arguments.
				int copyChars(char dest[MAX_STR_BUFF + 1], const char * SRC, 
						char delim)
					- Used to copy characters from a source buffer to the 
					  character array dest up until a deliminating character is 
					  found or until 80 characters has been copied, which ever
					  comes first.
				void printErrorMessage(int mode)
					- Used to print multiple messages to the standard error 
					  stream. The mode variable determines which set of messages 
					  is sent to the st1andard error stream.

Required      : 
Features Not
Included

Known Bugs    : 
*/

#include "processRelationships.h"

/*
	Aquires shared memory, based on numOfArgs and the commandArgs array. It then 
	attaches the shared memory to the it's own address space. After this, the 
	parentProcess fuction populates the memory with the data from the 
	commandArgs array, forks (numOfArgs) child processes and then waits for all
	child processes to terminate before detaching and removing the shared 
	memory. 

	If all processes can be executed successfully the function returns true, 
	false otherwise.

	Input	  = {int: numOfArgs, const char * *: commandArgs}
	Output	  = {bool: success}
*/
bool parentProcess(int numOfArgs, const char * commandArgs[])
{
	const int CHILDREN = numOfArgs - 1;
	const pid_t PARENTID = getpid();
	const key_t SHRDKEY = ftok(".", 'a');
	pid_t forkID = getpid();
	pid_t childIDs[CHILDREN];
	bool success = false;
	char * message = NULL;
	int status = NUM_INIT;
	int counter = NUM_INIT;
	int deadChildren = NUM_INIT;
	int shrdMemID = NUM_INIT;
	int * shrdMemPTR = NULL;  
	
	
	fprintf(stdout, "\nParent: requests shared memory\n");
	fflush(stdout);	
	
	shrdMemID = shmget(SHRDKEY, (CHILDREN * sizeof(int)), 
		IPC_CREAT | 0666);
	if (shrdMemID < 0)
	{
    	printErrorMessage(NUM_INIT + 1);
    	success = false;
	}
	else
	{
		fprintf(stdout, "\nParent: receives shared memory\n");
		fflush(stdout);

		fprintf(stdout, "\nParent: attaches shared memory\n");
		fflush(stdout);
		
		shrdMemPTR = (int *) shmat(shrdMemID, NULL, 0);
		if ((int)shrdMemPTR == NUM_INIT - 1) 
		{
     		printErrorMessage(NUM_INIT + 1);
     		success = false;
		}
		else
		{
			fprintf(stdout, "\nParent: fills shared memory\n");
			fflush(stdout);
			for(counter = 1; counter <= CHILDREN; counter ++)
			{
				shrdMemPTR[counter - 1] = atoi(commandArgs[counter]); 
			}

			fprintf(stdout, "\nParent: displays shared memory\n");
			fflush(stdout);

			for(counter = 0; counter < CHILDREN; counter ++)
			{
				fprintf(stdout, "%d ", shrdMemPTR[counter]);
				fflush(stdout);
			}
			
			fprintf(stdout, "\n");
			fflush(stdout);

			for(counter = 1; counter <= CHILDREN; counter ++)
			{
				if((forkID = fork()) > 0)
				{
					fprintf(stdout, "\nParent: forks child process: %d\n", 
						forkID);
					fflush(stdout);
				}
				else if(forkID < 0)
				{
					printErrorMessage(NUM_INIT + 2);
					exit(NUM_INIT + 1);
				}
				else
				{
					childProcess(counter - 1, shrdMemPTR);
				}
			}

			while(deadChildren < CHILDREN)
			{
				forkID = wait(&status);
				deadChildren ++;
			}
			
			if(getpid() == PARENTID)
			{
				fprintf(stdout, "\nDead Child Processes: %d", 
					deadChildren);
				fflush(stdout);

				fprintf(stdout, "\nParent: displays shared memory \n");
				fflush(stdout);
				for(counter = 0; counter < CHILDREN; counter ++)
				{
					fprintf(stdout, "%d ", shrdMemPTR[counter]);
					fflush(stdout);
				}

				fprintf(stdout, "\nParent: detaches shared memory\n");
				shmdt(shrdMemPTR);

				fprintf(stdout, "\nParent: removes shared memory \n");
				shmctl(shrdMemID, IPC_RMID, NULL);

				success = true;

				fprintf(stdout, "\nParent: finished\n");
				fflush(stdout);
			}
		}	
	}
	return success;
}

/*
	Displays the unique ID known as memoryIndex and initial state of the shared 
	memory associated with memoryIndex. Then the child process multiplies that 
	array element by their unique ID, storing the result in the same array 
	element. Finally the child will then display the current state of the 
	shared memory, provide their exit PID & status/code, and exit.

	Input	  = {int: memoryIndex, int * shrdMemPTR}
	Output	  = {void: null}
*/
void childProcess(int memoryIndex, int * shrdMemPTR)
{
	char * message = NULL;
	int exitCode = EXEC_END;
	pid_t PROCESSID = getpid();
	/* Child Process */ 

	fprintf(stdout, "\nChild ID: %d displays shared memory %d\n", 
		PROCESSID, shrdMemPTR[memoryIndex]);
	fflush(stdout);

	fprintf(stdout, "\nChild ID: %d displays private unique ID %d\n", 
		PROCESSID, memoryIndex);
	fflush(stdout);
	
	fprintf(stdout, "\nChild ID: %d updates shared memory\n", 
		PROCESSID);
	fflush(stdout);

	shrdMemPTR[memoryIndex] *= memoryIndex;

	fprintf(stdout, "\nChild ID: %d displays shared memory %d\n", 
		PROCESSID, shrdMemPTR[memoryIndex]);
	fflush(stdout);

	fprintf(stdout, "\nChild ID: %d exits with code %d\n", exitCode);
	fflush(stdout);

	exit(exitCode);
}

/*
	Verifies that the command input provided at execution time is valid. Valid 
	numOfArgs is a number between two and eight(inclusive) and valid commandArgs 
	is an array of numOfArgs strings each of which can be converted into an 
	integer between zero and nine(inclusive). 

	Returns true if commandInput is valid, false otherwise.

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
	Verifies that the character pointer input valid, input valid if it is 
	pointing to a sequence of characters that can be converted into an integer 
	that is within the range min to max(inclusive). 

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
int copyChars(char dest[MAX_STR_BUFF + 1], const char * SRC, char delim)
{
	int charCount = NUM_INIT;
  	/* Reject invalid source strings */
  	if(SRC == NULL)
  	{
    	dest = NULL;
    	return NUM_INIT;
  	}

  	/* 
  		Count the number of characters until the deliminator is found, if the 
  		deliminator is not found within the MAX_STR_BUFF characters return zero.
  	*/
  	while(SRC[charCount] != delim || charCount > MAX_STR_BUFF)
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
  	strncpy(dest, SRC, charCount);
  	dest[charCount] = '\0';
  	return charCount;
}

/*
  	Function that can print multiple termination messages. The modes are used to
  	modify the message(s) printed to the standard error stream.

  	mode = 0      : Represents invalid command line arguments.
  	mode = 1	  : Represents shared memory error.
  	mode = 2	  : Represents a process creation error.
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
    	write(STDERR_FILENO, message1, strlen(message1));
    	message2 = "\nThere must be between one and seven command arguments";
    	write(STDERR_FILENO, message2, strlen(message2));
    	message3 = "\nEach argument must be an integer between zero and nine\n";
    	write(STDERR_FILENO, message3, strlen(message3));
    	message1 = "\n";
    	write(STDERR_FILENO, message1, strlen(message1));

  	}
  	else if(mode == NUM_INIT + 1)
  	{
  		message1 = "\nShared memory error\n\0";
  		write(STDERR_FILENO, message1, strlen(message1));
  	}
  	else if(mode == NUM_INIT + 2)
  	{
  		message1 = "\nError creating child process\n\0";
  		write(STDERR_FILENO, message1, strlen(message1));
  	}
  	else
  	{
    	/* Undefined reason for termination */
    	message1 = "\nUndefined reason for termination!\n\0";
    	write(STDERR_FILENO, message1, strlen(message1));
  	}
}