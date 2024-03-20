#include "headers/bbPool.h"

typedef struct {

	bbPool_data p_PoolData;

	char* test_string;
} test_struct;

int main(void){

	char test_str[] = "You shall not pass!\n";

	bbPool* TestPool;
	int flag = bbPool_NewPool(&TestPool, 0, sizeof (test_struct), 4, 8);

	while(1) {


		test_struct* testStruct;


		int32_t flag = bbPool_New(&testStruct,TestPool, f_PoolNextAvailable);



		testStruct->test_string = test_str;

		test_struct* testStruct1;
		bbPool_Lookup(&testStruct1, TestPool, testStruct->p_PoolData.Self);

		printf("%s", testStruct1->test_string);

	}
}