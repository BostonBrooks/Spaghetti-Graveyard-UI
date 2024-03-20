#include "headers/bbDictionary.h"

int main (void){
	bbDictionary* dict;

	bbDictionary_new(&dict, 512);

	for(int i = 1; 1; i++){
		if (i%100 == 0)
			printf("iteration %d\n", i);
		char string[125];
		int32_t integer = rand();

		sprintf(string, "%d", integer);

		bbDictionary_add(dict, string, integer);

	}

}