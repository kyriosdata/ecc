# Sobre o exemplo
Esse exemplo busca apresentar o uso das funções: set, include_directories, find_library, target_link_libraries, install(SCRIPT) e 
install(PROGRAMS).
 
## Estrutura do diretório

CMake - Library

------->build*

-------------->bin*

--------------------->hello*

------->scripts*

-------------->runAbb.sh ou runAbb.bat*

------->lib

-------------->libabb.a

------->src

-------------->main.c

-------------->abb.c

-------------->abb.h

-------------->CMakeLists.txt

-------------->message.cmake

------->runAbb.sh

------->runAbb.bat

------->CMakeLists.txt

Os arquivos e diretórios marcados com * são criados durante a execução do exemplo.

## Sobre as funções e variáveis do exemplo
* Atribuir um valor - Como já mencionado no 
[exemplo anterior](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Subdirectory), existem variáveis no CMake que
 podem ser usadas para configurar certos comportamentos das funções, por exemplo quando ${EXECUTABLE_OUTPUT_PATH} foi alterada e o
 binário gerado pelo comando add_executable() foi armazenado em outro local. 
 
   Dentro do CMake existem dois tipo de variáveis, as variáveis do ambiente e as variáveis criadas na execução do CMake. As variáveis de
   ambiente são  as que o CMake configura automaticamente na sua execução e grava na cache. Elas podem no entanto ser alteradas durante
   a execução do CMake com o comando set().
 
   A sintaxe básica do comando set é a seguinte
 
        set(${NOME_DA_VARIÁVEL} VALORES)
      
   Quando se tratam de variáveis já criadas pelo CMake, isto é, as variáveis de ambiente, o valor, ou valores, a ser atribuido a ela pode
   possuir um tipo específico. Por exemplo, a variável ${EXECUTABLE_OUTPUT_PATH}, como o próprio nome já indica, deve guardar um path. 
   Dessa forma, não convem/não é permitido atribuir um valor inteiro para ela.
 
   O comando set também pode ser usado para criar novas variáveis. Se a variável recebendo o valor ainda não existe na cache, ou não é uma
   variável de ambiente, CMake cria a variável e atribui o valor passado. No exemplo isso pode ser visto quando foram definidos os fontes
   a serem usados na criação da target abb.

        set(Source main.c abb.c)

        add_executable(abb ${Source})

   O ideal é que a primeira letra da variável criada seja maiúscula, para facilitar na identificação, mas a regra de nomeação delas não é 
   lá muito restrita.

* Incluir um diretório - Essa é uma função em CMake que permite adicionar ao compilador um diretório no qual ele poderá procurar por
arquivos que ele deve incluir. Por exemplo, quando o compilador precisa encontrar as funções de abb.c. Se o arquivo abb.h não estiver 
existir dentro do diretório atual, o compilador deverá procurar em outro lugar por essa biblioteca de funções. Como o comando 

        include_directories(${PROJECT_BINARY_DIR}/../lib)
    
    foi incluído, durante a vinculação do executável, o arquivo libabb.a, instalado previamente, poderá ser encontrado no diretório
    fornecido. Esse arquivo contém a biblioteca compartilhada abb.h. Para vincular esse arquivo à target executável outro comando 
    será necessário.

* Encontrar uma biblioteca - Esse comando permite procurar por uma biblioteca através de caminhos pré-especificados na cache do CMake,
mas também em diretórios incluídos pelo comando include_directories.
  
   A sintaxe básica desse comando é a seguinte
   
        find_library(<Variável_para_path> NAMES (nomes_para_procura>)
        
   De forma muito simples, CMake procura combinações de <nome_para_procura> e armazena os resultados encontrados na variável 
   <Variável_para_path>. Essa variável vai guardar o caminho completo até a biblioteca correspondente encontrada, ou vai receber 
   --NOT-FOUND, caso não tenha encontrado um resultado.
   
   Também é possível incrementar o comando com um local específico no qual procurar a biblioteca, como no exemplo:
   
        find_library(ABB_LIB NAMES abb PATHS "${PROJECT_BINARY_DIR}/../lib")
        
   Após a palavra NAMES se encontram todos os nomes que o comando find_library deve experimentar na procura. Após PATHS se encontra
   o local onde find_library deve realizar a procura.

* Ligar bibliotecas para vinculação - As bibliotecas encontradas através do comando find_library, ou que tenham simplesmente sido 
adicionadas por um comando add_library (este será explicado em outro exemplo), devem ser ligadas ao executável que depende delas. 
Essa ligação é feita através do comando target_link_libraries.

  A sintaxe básica do comando target_link_libraries é a seguinte:
  
        target_link_libraries(<nome_da_target> <target_a_se_vincular>)
        
  Todas as targets que dependem de outra devem ser ligadas dessa forma para que possam ser vinculadas após a compilação.

* Usando Script CMake - CMake permite que scripts próprios dele sejam executados durantes a compilação da target install. Isso permite
que operações necessárias durante a instalação sejam feitas fora do arquivo CMakeLists.txt, por exemplo, para não sobrecarregar o
arquivo. Os scripts de cmake são identificados na forma <nome_do_script>.cmake

   A sintaxe básica para o uso de um script CMake durante a instalação é a seguinte:

        install (SCRIPT <nome_do_script>.cmake)

* Instalar Script do Sistema - CMake permite a instalação de um programa em um destino específicado. Quando não se especifica um caminho
até esse programa, o comando install procura no diretório atual por ele.

  A sintaxe básica desse comando utiliza o install de CMake da seguinte forma
  
        install(PROGRAMS <nome_do_programa> DESTINATION <caminho_destino>)
        
  No exemplo do repositório, o programa fornecido é um script e seu caminho de instalação é uma pasta que ainda não existe no diretório.
   Durante a instalação essa pasta é criada e o script é instalado dentro dela.
   
        if(WIN32)
	        INSTALL(PROGRAMS runAbb.bat DESTINATION ${PROJECT_SOURCE_DIR}/scripts)	
        elseif(UNIX)
            INSTALL(PROGRAMS runAbb.sh DESTINATION ${PROJECT_SOURCE_DIR}/scripts)	
        endif(WIN32)

  Perceba que no exemplo, é feita uma verificação para descobrir qual script instalar, o de Windows com formato .bat, ou o de Unix com 
  formato .sh.
  
  
## Pré-requisito
De agora em diante, para evitar armazenar binários desnecessários no repositório, o subidretório build não será mais enviado junto ao 
exemplo. Dessa forma, para manter os resultados da execução do CMake em um local separado dos fontes, será preciso criar um diretório
build (ou qualquer outro nome que indique a presença dos binários).

Isso deve ser feito dentro do diretório do projeto. Basta criar um diretório build através da GUI, ou através de um terminal, digitando:

    mkdir build

## Problemas no Visual Studio
Esse exemplo também possui o mesmo erro com Visual Studio descrito no 
[README](https://github.com/kyriosdata/ecc/blob/master/Exemplos/CMake%20-%20Subdirectory/README.md) do exemplo 
[CMake - Subdirectory](https://github.com/kyriosdata/ecc/tree/master/Exemplos/CMake%20-%20Subdirectory). Da mesma forma,
recomendo o uso de MinGW para compilação e instalação, pois este se mostrou mais simples de utilizar.

## Uso de MinGW e uso do script

De forma geral, o uso de MinGw se assemelha bastante aos passos descritos de uso do cmake no prompt de comando do Windows.

Os passos para o uso do gerador MinGW através do prompt de comando do Windows são os seguintes:
1. Abra o prompt de comando.

2. Encontre o diretório do projeto e acesse a pasta build em seguida.

        Exemplo: cd Projetos/CMake - Library/build

3. Dentro do subdiretório build execute o comando cmake .. -G "MinGw Makefiles". Isso informa ao CMake o caminho (no caso .., diretório 
pai) onde procurar por CMakeLists.txt, o arquivo básico descrito acima e também o gerador a ser utilizado. O gerador "MinGW Makefiles"
produz um arquivo Makefile a ser interpretado pelo compilador gcc, já que estamos usando a linguagem C, de MinGW.

4. Para compilar o projeto basta digitar

        mingw32-make
    
5. Agora que a target foi criada, podemos utilizar uma regra de instalação para ela. A instalação com MinGW é feita com o seguinte 
comando:

        mingw32-make install
   
6. Tudo pronto. Agora, para executar o objeto gerado na etapa 6, basta abrir o diretório de saída que foi específicado em CMakeLists com
a variável ${EXECUTABLE_OUTPUT_PATH} e executá-lo com ./abb. Da mesma forma, para executar a target script instalada, basta abrir o 
diretório especificado após DESTINATION e executá-la com seu nome de arquivo.

        Windows:  runAbb.bat
    
        Unix:     runAbb.sh


