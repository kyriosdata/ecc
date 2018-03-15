# Sobre o exemplo
Neste exemplo podemos observar como um header pode ser configurado a partir de variáveis e valores obtidos através do CMake.
 
## Estrutura do diretório

CMake - Configure

------->build*

-------------->bin*

--------------------->sistema*

------->config

-------------->sistema.c

-------------->sistema.h

-------------->sistema.h.in

-------------->CMakeLists.txt

------->CMakeLists.txt

Os arquivos e diretórios marcados com * são criados durante a execução do exemplo.

## Sobre as funções e variáveis do exemplo
* Configurando um arquivo - CMake oferece uma função muito poderosa em termos de configuração. A função configure_file usa um arquivo 
de entrada .in para configurar um arquivo de acordo com valores e variáveis pré-definidos em uma execução do CMake. Antes de mais nada,
vejamos a sintaxe básica desse comando:

      CONFIGURE_FILE( caminho/ao/arquido/de/entrada.h.in caminho/ao/arquido/de/saída.h )

Nesse comando o arquivo entrada.h.in deve existir previamente, sendo saída.h o arquivo que será configurado pelo CMake através do arquivo 
entrada.h.in. O arquivo entrada.h.in possui algumas características especiais que permitem ao CMake utilizá-lo como um intermediário. O
arquivo saída.h é criado no caminho especificado caso esse ainda não exista.

Dentro do arquivo entrada.h.in se encontra o texto a ser escrito em saída.h. Na execução do comando configure_file, CMake lê o arquivo 
entrada.h.in e procura por algumas palavras chave. 

Sempre que CMake encontrar uma linha começando por 

      #cmakedefine
    
Ele vai aplicar uma configuração de acordo com uma regra estabelecida. Por exemplo, uma linha como essa está presente no arquivo
sistema.h.in:

      #cmakedefine RAM @RAM@

E dentro do arquivo que invocou configure_file existe uma variável chamada RAM. Ao verificar isso, CMake substitui imediatamente essa 
linha por:

      #define RAM 8

Sendo 8 o valor que foi atribuido a essa variável dentro de CMakeLists.txt. CMake conseguiu identificar que isso se tratava de uma 
variável pois RAM estava circundada por arrobas ('@').

Os valores das variáveis também podem ser usados para determinar se um #define será ou não criado. Por exemplo, um fragmento de código
em CMakeLists.txt que realize a seguinte configuração:

      SET(AGE ON)

      SET(NOT_AGE OFF)

      CONFIGURE_FILE( ${CMAKE_SOURCE_DIR}/config/sistema.h.in ${CMAKE_SOURCE_DIR}/config/sistema.h )

Iria produzir o seguinte no arquivo sistema.h:

      #define AGE 10
      
      /* #undef NOT_AGE */
      
As variáveis que não foram definidas como algum dos valores que CMake entende como verdadeiro se tornam comentários.      
      
## Pré-requisitos
De agora em diante, para evitar armazenar binários desnecessários no repositório, o subidretório build não será mais enviado junto ao 
exemplo. Dessa forma, para manter os resultados da execução do CMake em um local separado dos fontes, será preciso criar um diretório
build (ou qualquer outro nome que indique a presença dos binários).

Isso deve ser feito dentro do diretório do projeto. Basta criar um diretório build através da GUI, ou através de um terminal, digitando:

      mkdir build
      
Observe que antes da configuração ser feita, o arquivo sistema.h se encontra vazio, quando essa configuração é refeita, ele será 
sobrescrito com o novo resultado.

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
   
5. Tudo pronto. Agora, para executar o objeto gerado na etapa 6, basta abrir o diretório de saída que foi específicado em CMakeLists com
a variável ${EXECUTABLE_OUTPUT_PATH} e executá-lo com ./sistema (sistema.exe em Windows).

## Resultado
Observe novamente o arquivo sistema.h. Após o fim da configuração ele se encontra escrito e pôde ser usado na compilação da target
sistema.

*Esse exemplo pode perfeitamente ser compilado e executado usando Visual Studio.
