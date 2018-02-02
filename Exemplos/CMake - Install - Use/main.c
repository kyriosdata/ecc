#include "perceptron.h"

int main(int argc,char *argv[]){
	individuo vet[4];

	neuronio  neu;

	int		  e1, e2, s, op, i;

	for(i = 0; i < 4; i++){
		printf("Digite: X - Y - Saída\n");

		scanf("%d",& e1);

		scanf("%d",& e2);

		scanf("%d",& s);

		vet[i] = inicializa_individuo(vet[i] , e1, e2, s);

	}

	neu = inicializa_neuronio();

	printf("\n---------Individuos---------");

	for(i = 0; i < 4; i++)
		printf("\nIndividuo: %d X: %d Y: %d S: %d\n", i+1, vet[i].x, vet[i].y, vet[i].s_esperada);

	nova_epoca(vet, neu);

    exit(EXIT_SUCCESS);
}