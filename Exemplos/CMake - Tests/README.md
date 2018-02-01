# Sobre o exemplo
Neste exemplo a forma como testes são adicionados através do CMake foi apresentada. Os testes tem como função única apresentar o funcionamento dos comandos relacionados à eles.
 
## Estrutura do diretório

CMake - Tests

------->build*

-------------->bin*

--------------------->test_target*

------->tests

-------------->cmockatest.c

-------------->testes.h

-------------->main.c

-------------->CMakeLists.txt

------->CMakeLists.txt

Os arquivos e diretórios marcados com * são criados durante a execução do exemplo.

## Sobre as funções e variáveis do exemplo
* Permitir testes - Para permitir que CMake adicione testes, o comando enable_testing() deve ser adicionado no CMakeLists principal, 
ou seja, o da raíz do diretório.
  
  Esse comando não possui nenhuma sintaxe especial, basta adicioná-lo logo após o nome do projeto.
  
      enable_testing()

  Todos os subdiretórios na cadeia do atual poderão realizar testes.

* Adicionar testes - Para adicionar testes através de CMake, utilizamos o comando add_test(). A sintaxe mais básica possível para esse
 comando é a seguinte
 
      add_test(<nome_do_teste> <executável>)
      
   No entanto, os testes costumam precisar de entradas próprias que informem por exemplo: seu comportamento; valores a serem testados;
   saída esperada; etc.
   
   As saídas são interpretadas como Sucesso ou Falha da mesma forma que CMake avalia se o valor de uma variável é true ou false.
      
## Pré-requisitos
De agora em diante, para evitar armazenar binários desnecessários no repositório, o subidretório build não será mais enviado junto ao 
exemplo. Dessa forma, para manter os resultados da execução do CMake em um local separado dos fontes, será preciso criar um diretório
build (ou qualquer outro nome que indique a presença dos binários).

Isso deve ser feito dentro do diretório do projeto. Basta criar um diretório build através da GUI, ou através de um terminal, digitando:

      mkdir build

## Uso de MinGW 

Os passos para o uso do gerador MinGW através do prompt de comando do Windows são os seguintes:
1. Abra o prompt de comando.

2. Encontre o diretório do projeto e acesse a pasta build em seguida.

        Exemplo: cd Projetos/CMake - Configure/build

3. Dentro do subdiretório build execute o comando cmake .. -G "MinGw Makefiles". Isso informa ao CMake o caminho (no caso .., diretório 
pai) onde procurar por CMakeLists.txt, o arquivo básico descrito acima e também o gerador a ser utilizado. O gerador "MinGW Makefiles"
produz um arquivo Makefile a ser interpretado pelo compilador gcc, já que estamos usando a linguagem C, de MinGW.

4. Para compilar o projeto basta digitar

        mingw32-make
   
5. O binário resultado já pode ser executado, mas os resultados dessa execução ainda não serão encarados como testes. Ainda assim, se
for de interesse executar o binário do exemplo neste ponto faça

        cd bin

        test_target.exe (ou ./test_target para Unix)
      
6. Para criar e executar os testes faça

        mingw32 make test
      
   O resultado será exibido logo em seguida.


## Resultado
O resultado dos testes é passado mostrando um a um o resultado de cada teste. Porem, o comando ctest -V possui maiores detalhes para
 cada teste individual

## Aviso
Esse exemplo pode ser compilado e executado usando Visual Studio. Basta compilar a target nome do projeto e em seguida RUN_TESTS. 
No entanto, como alguns dos testes no exemplo foram projetados para falhar, Visual Studio irá apresentar o resultado como erro. 
Para verificar a saída dos testes basta clicar na aba "saída" ao lado de "lista de erros" e rolar para cima.
