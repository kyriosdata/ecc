#include "tests.h"

/* A test case that verifies if a is the inverse of b. */
int inverse_test_success(int a, int b) {
    
	 if ((a + b) == 0) return 0;
	 else              return 1;

}

int equals_test_success(int a, int b) {

	if (a == b) return 0;
	else        return 1;

}