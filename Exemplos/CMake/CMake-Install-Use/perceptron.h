/*Perceptron
*Nome: Lucas Felipe Moreira Silva
*Matrícula: 201405021
*/

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bias 1	//Entrada de b (wb).
#define a 	 1	//Taxa de aprendizagem.

//Um indivíduo é composto de:
typedef struct individuo{
	int x, y;			//Duas entradas (e1, e2);
	int s_esperada; 	//Uma saída esperada dada as duas entradas.
	int erro;		 	//Um campo erro que recebe a saída desejada - saída.

}individuo;

//Um neurônio é composto de:
typedef struct neuronio{
	int wb, w1, w2; 	//Três sinapses (b, w1 e w2); coeficientes em NET;
	int net;			//Net: somatório de entradas*sinapses. Net = wb*b + w1*e1 + w2*e2

}neuronio;

individuo inicializa_individuo(individuo i, int x, int y, int s);

void nova_epoca(individuo vet[4], neuronio n);

int calcula_net(individuo i, neuronio n);

int calcula_saida(neuronio n);

neuronio calcula_sinapse(individuo i, neuronio n, int saida);

neuronio inicializa_neuronio();

#endif






