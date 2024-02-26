#include "../headers/bbPool.h"

typedef struct {

	int32_t p_Pool_Self;
	int32_t p_Pool_Prev;
	int32_t p_Pool_Next;
	int32_t p_Pool_InUse;
	int32_t p_Map;


	char* test_string;
} test_struct;

int main(void){

	char test_str[] = "You shall not pass!\n";

	bbPool* TestPool = bbPool_NewPool(sizeof (test_struct), 4, 8);

	while(1) {

		int test_int = bbPool_New(TestPool, f_Pool_NextAvailable);

		test_struct* testStruct = bbPool_Lookup(TestPool, test_int);

		testStruct->test_string = test_str;

		test_struct* testStruct1 = bbPool_Lookup(TestPool, test_int);

		printf("%s", testStruct1->test_string);

	}
}