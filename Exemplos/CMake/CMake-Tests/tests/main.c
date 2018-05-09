#include "tests.h"
    
int main(int argc, char *argv[]){
	
	int x; 
	int y;
	int num  = argc - 1;
  	int test = atoi(argv[1]);
	
	if (num == 0) 
  		printf("Nenhum argumento fornecido\n");
		
	else if (num == 0) // Erro intensional
		printf("1 argumento fornecido\n");
	
	else if (num == 2)
		printf("2 argumentos fornecidos\n");
	
	else 
		printf("%d argumentos fornecidos\n", num);
	
	if (argv != 0) {
		printf("argv nao eh nulo\n");; // Ponto e virgula extra intencional
	}

	x = atoi(argv[2]);
	y = atoi(argv[3]);

	printf("X: %d\nY: %d", x, y);

	//returns the result of the tests
	if       (test == 1)return inverse_test_success(x, y);
	if	 (test == 1)return inverse_test_success(x, y); //Cópia proposital
	else if  (test == 2)return  equals_test_success(x, y);
}
