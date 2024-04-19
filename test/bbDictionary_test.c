#include "headers/bbDictionary.h"
#include "headers/bbIntTypes.h"

int main (void){
	bbDictionary* dict;

	bbDictionary_new(&dict, 512);

	for(I32 i = 1; 1; i++){
		if (i%100 == 0)
			printf("iteration %d\n", i);
		char string[125];
		I32 integer = rand();

		sprintf(string, "%d", integer);

		bbDictionary_add(dict, string, integer);

	}

}