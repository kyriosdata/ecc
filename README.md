# ECC
Entrega Contínua para Desenvolvimento em C

## Objetivo
Definir uma proposta de Entrega Contínua para projetos de desenvolvimento de software na linguagem de programação C.

## Links relevantes
- [CNCF](https://github.com/cncf/landscape)
- [WiredTiger](https://github.com/wiredtiger/wiredtiger)

## Ferramentas
A descrição da instalação e do uso das ferramentas pode ser encontrada na [wiki](https://github.com/kyriosdata/ecc/wiki) do projeto
- [CMake](https://github.com/kyriosdata/ecc/wiki/CMake): conjunto de ferramenta open-source para desenvolvimento cross-plataform. Possui ferramentas que auxiliam na construção, teste, e empacotamento de softwares desenvolvidos em C, C++, Fortran e Python.

## Exemplos
Os exemplos presentes neste repositório auxiliam na compreensão e uso das ferramentas propostas. 

### Exemplos disponíveis atualmente:
#### CMake
- [CMake - Basic](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Basic) - o mínimo para construir e executar um projeto em CMake. Maior descrição deste exemplo está disponível em [CMake](https://github.com/kyriosdata/ecc/wiki/CMake).
- [CMake - Subdirectory](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Subdirectory) - básicos do uso do CMake, uso de um subdiretório, criação de um executável, uso de variáveis, uso de expressões de seleção básico, etc. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Subdirectory#sobre-o-exemplo) do exemplo.  
- [CMake - Library](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Library) - uso de funções para encontrar e 
vincular bibliotecas junto à targets. Princípios básicos do uso de variáveis e Scripts. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/blob/master/Exemplos/CMake%20-%20Library/README.md#sobre-o-exemplo) do exemplo.
- [CMake - Configure](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Configure) - uso da função configure_file para configurar um Header.h a partir de um arquivo de entrada.h.in que CMake usa como intermediário. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/blob/master/Exemplos/CMake%20-%20Configure/README.md#sobre-o-exemplo) do exemplo.
- [CMake - Tests](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Tests) - introdução aos testes sendo gerenciados pelo CMake. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Tests#sobre-o-exemplo) do exemplo.

## Construção do projeto
A sequência de passos para compilar e gerar executáveis através do CMake está descrita na [wiki do CMake](https://github.com/kyriosdata/ecc/wiki/CMake#construindo-o-primeiro-projeto)
