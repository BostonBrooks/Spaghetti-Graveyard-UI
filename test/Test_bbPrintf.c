
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BBDEBUG
#define BBVERBOSE
#define BBASSERT

#include "../headers/bbPrintf.h"
int main(void){

	int call_sign = 193;

	printf("Test printf wrappers:\n");

	bbDebug("This is a debug message: %d\n", call_sign);
	bbVerbose("This is a verbose message: %d\n", call_sign);

	bbAssert(1==1, "This is a true assertion: %d\n", call_sign);
	bbAssert(1==0, "This is a false assertion: %d\n", call_sign);

	exit(EXIT_SUCCESS);

}