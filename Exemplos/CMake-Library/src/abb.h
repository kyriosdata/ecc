#ifndef ABB_H_
#define ABB_H_
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct no *raiz; //Ponteiro da raiz
struct no *alocar; //Ponteiro para fazer alocação

/*Declaração do nó para a árvore, composto de ponteiros
da direita e esquerda e de um campo para dado que no caso
é um inteiro;
*/
struct no {
       
       int dado;
       struct no *direita;
       struct no *esquerda;
       
       };

int buscar(int dado);
       
void inserir(int dado);

void caminharEmOrdem(struct no *ponteiro);

#endif
