#include <stdlib.h>
#include <stdio.h>



int main (void){

	int size = sizeof(int);

	void* array = malloc (size * 5);

	u_int8_t* ch = array;

	for (int i = 0; i < 5; i++){
		int j = i * size;

		int* integ = &ch[j];

		*integ = i;
	}

	for (int i = 0; i < 5; i++){
		int j = i * size;

		int* integ = &ch[j];

		printf("%d\n",*integ);
	}

}