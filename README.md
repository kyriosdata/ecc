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
- [Travis-CI](https://github.com/kyriosdata/ecc/wiki/Travis-CI): serviço de integração contínua que viabiliza o uso de ferramentas de build, teste, análise de código, etc. para projetos hospedados no GitHub. Uma dessas ferramentas é o CMake, o que corrobora a utilização da mesma.

## Exemplos
Os exemplos presentes neste repositório auxiliam na compreensão e uso das ferramentas propostas. 

### Exemplos disponíveis atualmente:
#### CMake
- [CMake - Basic](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Basic) - o mínimo para construir e executar um projeto em CMake. Maior descrição deste exemplo está disponível em [CMake](https://github.com/kyriosdata/ecc/wiki/CMake).
- [CMake - Subdirectory](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Subdirectory) - básicos do uso do CMake, uso de um subdiretório, criação de um executável, uso de variáveis, uso de expressões de seleção básico, etc. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Subdirectory#sobre-o-exemplo) do exemplo.  
- [CMake - Library](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Library) - uso de funções para encontrar e 
vincular bibliotecas junto à targets. Princípios básicos do uso de variáveis e Scripts. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/blob/master/Exemplos/CMake/CMake-Library/README.md#sobre-o-exemplo) do exemplo.
- [CMake - Configure](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Configure) - uso da função configure_file para configurar um Header.h a partir de um arquivo de entrada.h.in que CMake usa como intermediário. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/blob/master/Exemplos/CMake/CMake-Configure/README.md#sobre-o-exemplo) do exemplo.
- [CMake - Tests](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Tests) - introdução aos testes sendo gerenciados pelo CMake. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Tests#sobre-o-exemplo) do exemplo.
- [CMake - Install - Use](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Install-Use) - junção do exemplo da criação de bibliotecas através do CMake e do uso destas. Os [pré-requisitos](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Install-Use#pr%C3%A9-requisitos) desse exemplo devem ser seguidos afinco, caso contrário, a saída dos resultados pode se misturar e a compreeensão ser prejudicada. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake/CMake-Install-Use#sobre-o-exemplo) do exemplo.
#### Travis
**Nota:** 
O único arquivo .travis.yml que será levado em conta pelo sistema do Travis é o arquivo na raiz do repositório. Todos os exemplos a seguir estão em uma pasta particular e não afetam a execução. Para fazer uso desses exemplos, basta substituir o conteúdo do arquivo .travis.yml na raiz pelo do exemplo desejado.
- [Travis - Basic](https://github.com/kyriosdata/ecc/tree/master/Exemplos/Travis/Travis-Basic) - Versão mais simples possível do uso de Travis para compilar e executar um programa em C. Uso dos comandos mais simples e uso de duas etapas de build. Mais informações podem ser encontradas no [README](https://github.com/kyriosdata/ecc/tree/master/Exemplos/Travis/Travis-Basic#sobre-o-exemplo) do exemplo.

## Construção do projeto
A sequência de passos para compilar e gerar executáveis através do CMake está descrita na [wiki do CMake](https://github.com/kyriosdata/ecc/wiki/CMake#construindo-o-primeiro-projeto)
