//Não é preciso incluir a biblioteca abb.c
//Como uma biblioteca dinâmica foi construída,
//Esse fonte pode acessar as funções de abb.c
//De forma direta em tempo de execução
#include "abb.h"
      
int main() {
    
	int dado, option = -1;

	while(option != 0){
		printf("\n1 - Inserir"
			   "\n2 - Buscar"
			   "\n3 - Imprimir"
			   "\n0 - sair\n:");

		scanf("%d", & option);

		switch(option){
			case 1:
				printf("Inserir - Digite um numero: ");
				scanf("%d", & dado);
				inserir(dado);
				break;
			
			case 2:
				printf("Buscar - Digite um numero: ");
				scanf("%d", & dado);

				if(!(buscar(dado)))
					printf("\nFound");				

				else
					printf("\nNot Found");	
				
				break;
		
			case 3:
				caminharEmOrdem(raiz);
				break;

			default:
				printf("Entrada invalidada");
				break;
		}

	}

	return 0;
}
