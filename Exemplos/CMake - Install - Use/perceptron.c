#include "perceptron.h"

//Inicializa um neurônio.
neuronio inicializa_neuronio(){
	neuronio n;

	n.wb = 0;			//Todas as sinapses de um neurônio começam com valor 0.
	n.w1 = 0;
	n.w2 = 0;

	return n;			//Retorna o novo neurônio.

}

//Inicializa um indivído (nova entrada de teste).
individuo inicializa_individuo(individuo i, int x, int y, int s){
	individuo aux;

	i.x = x;			//As entradas e a saída esperada são atribuídas a um indivíduo.
	i.y = y;
	i.s_esperada = s;

	aux = i;

	return aux;			//Retorna o novo indivíduo (neurônio de entrada).

}

//Calcula o somatório das entradas*sinapses.
int calcula_net(individuo i, neuronio n){
	int net = (n.wb * bias) + (n.w1 * i.x) + (n.w2 * i.y);	//Faz o somatório.

	return net;			//Retorna o somatório.

}

//Calcula a saída de acordo com o valor de NET.
int calcula_saida(neuronio n){
	if(n.net > 0)   return 1;	//As saídas são calculadas através da função escada.
	else			return 0;	//A saída da função escada é binária (0 ou 1).

}

//Calculo de uma nova sinapse para um neurônio.
neuronio calcula_sinapse(individuo i, neuronio n, int saida){

	neuronio aux;

	i.erro = i.s_esperada - saida;	//Calcula o erro com a saída esperada pelo teste de acordo com suas entradas menos a saída obtida.

	printf("\nCalcula sinapse inicio:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);//Mostra o neurônio antes de ser atualizado

	n.wb = n.wb + a * i.erro * bias;		//Atualiza o neurônio a partir do erro encontrado e dos sinais de entrada
	n.w1 = n.w1 + a * i.erro * i.x;
	n.w2 = n.w2 + a * i.erro * i.y;

	aux = n;

	printf("\nCalcula sinapse fim:\tWb %d - W1 %d - W2 %d", n.wb, n.w1, n.w2);	//Mostra o resultado do feedback.

	return aux;			//Retorna o novo neurônio com as novas sinapses.

}

//Atualiza neurônios a partir dos dados recebidos até que se encontre a saída correta.
void nova_epoca(individuo vet[4], neuronio n){

	int op = -1, saida, soma, aux, aux2, i, usado[4], ran, check;

	srand((unsigned)time(NULL));

	while(op != 0){//Enquanto a saída correta não foi encontrada.

		printf("\n-----------------------------------------------");

		printf("\nNeuronio Época: wb = %d ---- w1 = %d ---- w2 = %d\n", n.wb, n.w1, n.w2);	//Mostra o primeiro neurônio da época.

		soma = 0;

		aux2 = 0;

		n.net = calcula_net(vet[0], n);	//Calcula o net para o primeiro teste.

		saida = calcula_saida(n);		//Calcula a saída para o primeiro net.

		for(i = 0; i < 4; i++) usado[i] = 0;	//For usado para auxiliar na escolha da ordem dos testes.

		while(aux2 < 4){//Enquanto os quatro indivíduos não tenham sido testados.

			check = -1;

			while(check != 0){//Enquanto não achou um indivíduo que ainda não tenha sido escolhido.

				ran = rand() % 4;//Tenta achar um novo teste.

				if(usado[ran] == 0){//Checa se o teste já foi feito nessa época.
					check = 0;
					i = ran;
					usado[ran] = 1;
				}

			}

			printf("\n\nEscolhido %d - Esperado %d - Obtido: %d", i+1, vet[i].s_esperada, saida);//Mostra o teste escolhido, o esperado
																								 //e a saída encontrada.
			n = calcula_sinapse(vet[i], n, saida);	//Atualiza o neurônio.

			if(vet[i].s_esperada != saida) soma++; //Verifica se cada teste teve seu resultado esperado.

			printf("\nNET = %d SAÍDA = %d", n.net, saida);	//Mostra o Net e sua saída.

			if(i != 3)n.net = calcula_net(vet[i+1], n);
			else      n.net = calcula_net(vet[0], n);

			saida = calcula_saida(n);			   //Calcula a próxima saída.

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