#include "tests.h"
    
int main(int argc, char *argv[]){
	
	int x; 
	int y;
	
	int test = atoi(argv[1]);

	x = atoi(argv[2]);
	y = atoi(argv[3]);

	printf("X: %d\nY: %d", x, y);

	//returns the result of the tests
	if       (test == 1)return inverse_test_success(x, y);
	else if  (test == 2)return  equals_test_success(x, y);
}