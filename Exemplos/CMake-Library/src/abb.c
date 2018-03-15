#include "abb.h"

/*Rotina de busca
Insere o dado em string e ela retorna o ponteiro em hexa
para a região da memória para o qual o ponteiro está
apontando.
*/
int buscar(int dado) {
       
      struct no *ponteiro;
      
      ponteiro = raiz;
       
      while (ponteiro) { 
            
      if (dado == ponteiro->dado) //Faz a comparação de strings
            return 0; //Retorna ponteiro se o encontrar
            
      if (dado > ponteiro->dado)
            ponteiro = ponteiro->direita;

      else
            ponteiro = ponteiro->esquerda; 
      
      }
      
      return 1; //Retorna o ponteiro nulo
}

/*Rotina que faz a inserção na árvore binária de busca
O Parâmetro dado recebe um ponteiro para string 
A função não retorna valor nem referência
*/
void inserir(int dado) {
     
    alocar = (struct no *) malloc(sizeof(struct no)); //Faz alocação na memória
        
    if (!alocar) { //Se não for possível a alocação, sai do programa
       printf("Falta de memória"); 
       exit(0);
    }
    
	alocar->dado = dado; //Copia o dado para o novo nó alocado
     
     if (!raiz) { //Se não houver elemento ainda na árvore, insere na raiz
         raiz = alocar;
     }
     
     else //se não...
     
     {
       //ponteiros para busca
       struct no *ponteiro; 
       struct no *ponteiroAnterior;
       ponteiro = raiz; //ponteiro inicia na raiz
       ponteiroAnterior = NULL; //anterior inicial em NULL
         
        while (ponteiro) { //Faz a busca do lugar ao qual deve ser inserido o nó
              
              ponteiroAnterior = ponteiro;
              
              if (dado == ponteiro->dado) {
                 printf("\nDado inserido já existe!");
                 return;
                 }
              
              if (dado > ponteiro->dado){
                 ponteiro = ponteiro->direita;
              }
              else {
                 ponteiro = ponteiro->esquerda; 
                   }
           }

        if  (dado > ponteiroAnterior->dado) {
              ponteiroAnterior->direita = alocar; 
              //atribui o endereço de alocação ao ponteiro da direita do nó anterior
            }  
        else  {
              ponteiroAnterior->esquerda = alocar;
              //atribui o endereço de alocação ao ponteiro da esquerda do nó anterior
              }
     }
}

/*Faz o caminhamento em ordem recursivamente*/
void caminharEmOrdem(struct no *ponteiro) {
     if (ponteiro) {
           caminharEmOrdem(ponteiro->esquerda);
           printf("\n%d", ponteiro->dado);
           caminharEmOrdem(ponteiro->direita);
          }
     }


