//sistema.h é um cabeçalho previamente configurado pelo CMake
#include "sistema.h"

int main(){

	struct system s;

	if		(ID == 1)		s.nome = "Windows";
	else if	(ID == 2) 		s.nome = "Unix";
	s.memo = RAM;

	printf("\nSistema: %s"
           "\nMemória Ram: %d"
           "\n", s.nome, s.memo);

}