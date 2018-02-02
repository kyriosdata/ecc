#include "perceptron.h"

//Inicializa um neur�nio.
neuronio inicializa_neuronio(){
	neuronio n;

	n.wb = 0;			//Todas as sinapses de um neur�nio come�am com valor 0.
	n.w1 = 0;
	n.w2 = 0;

	return n;			//Retorna o novo neur�nio.

}

//Inicializa um indiv�do (nova entrada de teste).
individuo inicializa_individuo(individuo i, int x, int y, int s){
	individuo aux;

	i.x = x;			//As entradas e a sa�da esperada s�o atribu�das a um indiv�duo.
	i.y = y;
	i.s_esperada = s;

	aux = i;

	return aux;			//Retorna o novo indiv�duo (neur�nio de entrada).

}

//Calcula o somat�rio das entradas*sinapses.
int calcula_net(individuo i, neuronio n){
	int net = (n.wb * bias) + (n.w1 * i.x) + (n.w2 * i.y);	//Faz o somat�rio.

	return net;			//Retorna o somat�rio.

}

//Calcula a sa�da de acordo com o valor de NET.
int calcula_saida(neuronio n){
	if(n.net > 0)   return 1;	//As sa�das s�o calculadas atrav�s da fun��o escada.
	else			return 0;	//A sa�da da fun��o escada � bin�ria (0 ou 1).

}

//Calculo de uma nova sinapse para um neur�nio.
neuronio calcula_sinapse(individuo i, neuronio n, int saida){

	neuronio aux;

	i.erro = i.s_esperada - saida;	//Calcula o erro com a sa�da esperada pelo teste de acordo com suas entradas menos a sa�da obtida.

	printf("\nCalcula sinapse inicio:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);//Mostra o neur�nio antes de ser atualizado

	n.wb = n.wb + a * i.erro * bias;		//Atualiza o neur�nio a partir do erro encontrado e dos sinais de entrada
	n.w1 = n.w1 + a * i.erro * i.x;
	n.w2 = n.w2 + a * i.erro * i.y;

	aux = n;

	printf("\nCalcula sinapse fim:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);	//Mostra o resultado do feedback.

	return aux;			//Retorna o novo neur�nio com as novas sinapses.

}

//Atualiza neur�nios a partir dos dados recebidos at� que se encontre a sa�da correta.
void nova_epoca(individuo vet[4], neuronio n){

	int op = -1, saida, soma, aux, aux2, i, usado[4], ran, check;

	srand((unsigned)time(NULL));

	while(op != 0){//Enquanto a sa�da correta n�o foi encontrada.

		printf("\n-----------------------------------------------");

		printf("\nNeuronio �poca: wb = %d ---- w1 = %d ---- w2 = %d\n", n.wb, n.w1, n.w2);	//Mostra o primeiro neur�nio da �poca.

		soma = 0;

		aux2 = 0;

		n.net = calcula_net(vet[0], n);	//Calcula o net para o primeiro teste.

		saida = calcula_saida(n);		//Calcula a sa�da para o primeiro net.

		for(i = 0; i < 4; i++) usado[i] = 0;	//For usado para auxiliar na escolha da ordem dos testes.

		while(aux2 < 4){//Enquanto os quatro indiv�duos n�o tenham sido testados.

			check = -1;

			while(check != 0){//Enquanto n�o achou um indiv�duo que ainda n�o tenha sido escolhido.

				ran = rand() % 4;//Tenta achar um novo teste.

				if(usado[ran] == 0){//Checa se o teste j� foi feito nessa �poca.
					check = 0;
					i = ran;
					usado[ran] = 1;
				}

			}

			printf("\n\nEscolhido %d - Esperado %d - Obtido: %d", i+1, vet[i].s_esperada, saida);//Mostra o teste escolhido, o esperado
																								 //e a sa�da encontrada.
			n = calcula_sinapse(vet[i], n, saida);	//Atualiza o neur�nio.

			if(vet[i].s_esperada != saida) soma++; //Verifica se cada teste teve seu resultado esperado.

			printf("\nNET = %d SA�DA = %d", n.net, saida);	//Mostra o Net e sua sa�da.

			if(i != 3)n.net = calcula_net(vet[i+1], n);
			else      n.net = calcula_net(vet[0], n);

			saida = calcula_saida(n);			   //Calcula a pr�xima sa�da.

			aux2++;

		}

		if(soma == 0) op = 0;

		printf("\n-----------------------------------------------");

		printf("\n\n");

	}

	op = -1;

	printf("\n--------------Checar-------------");

	int e1, e2, net;
	individuo in;

	while(op != 0){

		printf("\n1 - Novo teste\n0 - Sair\n");
		scanf("%d",& op);

		if(op != 0){
			printf("\nDigite Entrada 1 | Entrada 2\n");
			scanf("%d",& e1);
			scanf("%d",& e2);

		in = inicializa_individuo(in , e1, e2, 0);
		net = calcula_net(in, n);

		if(net > 0)  printf("\n1");
		else 		 printf("\n-1");
		}
		printf("\n");
	}


	return;			//Retorna para main quando encontra as sinapses corretas.

}