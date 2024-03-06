#include "headers/bbPool.h"

typedef struct {

	bbPool_data p_PoolData;

	char* test_string;
} test_struct;

int main(void){

	char test_str[] = "You shall not pass!\n";

	bbPool* TestPool = bbPool_NewPool(0, sizeof (test_struct), 4, 8);

	while(1) {

		int32_t test_int = bbPool_New(TestPool, f_Pool_NextAvailable);

		test_struct* testStruct;
		bbPool_Lookup(&testStruct, TestPool, test_int);

		testStruct->test_string = test_str;

		test_struct* testStruct1;
		bbPool_Lookup(&testStruct1, TestPool, test_int);

		printf("%s", testStruct1->test_string);

	}
}