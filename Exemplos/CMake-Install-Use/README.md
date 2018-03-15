# Sobre o exemplo
O propósito desse exemplo é apresentar a instalação de uma biblioteca, seu uso por um executável que depende dela e também a diferença 
de uso das bibliotecas em Windows e Unix.
 
## Estrutura do diretório

CMake - Install - Use

------->build*

-------------->cmake_install*

------->example

-------------->build*

-------------->CMakeLists.txt

------->lib*

-------------->libperceptron.a*

-------------->libperceptron.dll*

-------------->libperceptron.dll.a*

-------------->perceptron.h

------->CMakeLists.txt

------->main.c

------->perceptron.c

------->perceptron.h


Os arquivos e diretórios marcados com * são criados durante a execução do exemplo.

## Sobre as funções e bibliotecas do exemplo
* Adicionar uma biblioteca - Em CMake, é possível contruir e exportar uma biblioteca a partir de arquivos fonte. Esse comando é muito 
útil quando pensamos em desenvolvimento cross-plataform. Dentro de sua execução ele criará a biblioteca própria para o sistema em que 
ele está sendo executado. Por exemplo, em Windows ele pode criar uma biblioteca .dll enquanto em Unix ele criará uma .lib ou .a. 

  A sintaxe básica do comando add_library é a seguinte:
  
          add_library(<nome_da_target> <tipo_da_biblioteca> ${<fontes>})
  
  Onde fontes é uma variável que guarde pelo menos um arquivo fonte, ou uma lista de arquivos fonte.
  
  As bibliotecas desse comando podem ser de três tipos STATIC, SHARED ou MODULE. As bibliotecas do tipo STATIC são ligadas durante a 
  etapa de vinculação da criação da target. As bibliotecas do tipo SHARED são dinâmicas e são usadas em tempo de execução pela target.
  
  As bibliotecas, assim como os executáveis, são targets em CMake. Quando uma biblioteca depende de outra, elas podem ser ligadas pelo 
  comando target_link_libraries.
  
  IMPORTANTE: Em Windows, as bibliotecas do tipo SHARED devem ser especificadas como RUNTIME no comando install, e o arquivo resultante
   deve estar junto do executável para que a execução possa encontrá-la. Se isso não for feito, a variável de ambiente PATH do Windows 
   precisará conhecer o caminho até a .dll.
   
* Mudar propriedades de targets - Essa é uma possibilidade para personalizar e identificar uma target particular criada pelo CMake. Da 
mesma forma que existem diferentes tipos de targets, existem diferentes propriedades que podem ser alteradas em cada uma. A lista de 
propriedades específicas das targets é extensa demais para constar nesse documento, mas pode ser encontrada na documentação de 
[propriedades](https://cmake.org/cmake/help/latest/manual/cmake-properties.7.html).

   A sintaxe básica do comando para mudar uma propriedade de uma target é a seguinte:
   
        set_target_properties(<nome_da_target> PROPERTIES <NOME_DA_PROPRIEDADE> <novo_valor>)
  
 * Manipulação de arquivos - CMake permite certa manipulação de arquivos da mesma forma que a linguagem C permite, com algumas 
 possiblidades adicionais. No exemplo, uma dessas possibilidades foi usada. Quando o executável está sendo usado em Windows e foi
  ligado a uma biblioteca .dll, a biblioteca precisa estar no mesmo diretório em que o arquivo está. Dessa forma, em certo ponto o 
  seguinte foi usado:
  
        find_library(PRC_LIB NAMES perceptron PATHS "../lib")
        
        set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
  
        if(WIN32)
	          file(COPY ${PRC_LIB}
            DESTINATION ${EXECUTABLE_OUTPUT_PATH})
        endif(WIN32)
        
    Que como a própria estrutura sugere, copia o arquivo guardado na variável ${PRC_LIB} para o destino ${EXECUTABLE_OUTPUT_PATH}. Onde
    EXECUTABLE_OUTPUT_PATH é uma variável que guarda o local onde a target executável deve ser colocada.

## Pré-requisitos
Um diretório build deve ser criado dentro do diretório raíz e outro dentro do diretório example, pois estes tem saídas diferentes:

      mkdir /CMake - Install - Use/build
      
      mkdir /CMake - Install - Use/example/build

Os comandos cmake serão executados de dentro desses subdiretórios.

## Uso de MinGW 

Os passos para o uso do gerador MinGW através do prompt de comando do Windows são os seguintes:
1. Abra o prompt de comando.

2. Encontre o diretório do projeto e acesse a pasta build em seguida.

        Exemplo: cd Projetos/CMake - Install - Use/build

3. Dentro do subdiretório build execute o comando cmake .. -G "MinGw Makefiles". Isso informa ao CMake o caminho (no caso .., diretório 
pai) onde procurar por CMakeLists.txt, o arquivo básico descrito acima e também o gerador a ser utilizado. O gerador "MinGW Makefiles"
produz um arquivo Makefile a ser interpretado pelo compilador gcc, já que estamos usando a linguagem C, de MinGW.

4. Para compilar o projeto basta digitar

        mingw32-make
        
5. Em seguida, execute o comando para instalar a biblioteca:

        mingw32-make install
   
   Neste ponto, um diretório lib será criado. Ele portará a biblioteca instalada. 
   
6. Dirija-se ao diretório example/build e execute cmake .. -G "MinGw Makefiles" novamente.

        cd ../example/build
        
        cmake .. -G "MinGw Makefiles"

6. Para executar o binário, abra a pasta bin e digite main.exe (ou ./main para Unix).
