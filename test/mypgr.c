/* halt.c
 *	Simple program to test whether running a user program works.
 *	
 *	Just do a "syscall" that shuts down the OS.
 *
 * 	NOTE: for some reason, user programs with global data structures 
 *	sometimes haven't worked in the Nachos environment.  So be careful
 *	out there!  One option is to allocate data structures as 
 * 	automatics within a procedure, but if you do this, you have to
 *	be careful to allocate a big enough stack to hold the automatics!
 */

#include "syscall.h"

void main()
{
    char *execArgs[256];
    int status1;
    int processID;
    int buffer[256];
    printf("\n\n********************************** mypgr Program Loading **********************************\n\n");
    printf("How Many String Will You Give (Maximum 256):  ");
     /*
    int input=fgeti(0); 
      */
    int input=5;
    int i;
    char execInput[input][256];
    for(i=0; i<input; i++)
    {
        printf("Give String No. %d : ", (i+1));
        readline(execInput[i], 100);
        execArgs[i]= execInput[i];
    }
    processID=exec("echo.coff", input,  execArgs);
    int k=join(processID, &status1);
    printf("********* Join On Process %d Finished\nStatus Value:  %d   Returned Value: %d   ***************\n", processID, status1, k);
    processID=exec("echo.coff", input,  execArgs);
    k=join(processID, &status1);
    printf("********* Join On Process %d Finished\nStatus Value:  %d   Returned Value: %d   ***************\n", processID, status1, k);
    halt();
    /* not reached */
}
