# Sobre o exemplo
Este exemplo busca introduzir alguns conceitos sobre controle de fluxo e tomadas de decisão em CMake. Alguns termos descritos nessa
 explicação podem ser mais densos e só virão a fazer mais sentido conforme os exemplos são incrementados.
 
## Estrutura do diretório

CMake - Subdirectory

------->build

-------------->bin

--------------------->hello

------->execs

-------------->hello

------->src

-------------->main.c

-------------->CMakeLists.txt

------->main.c

------->CMakeLists.txt

## Sobre as funções e variáveis do exemplo
* Expressões de seleção - CMake fornece uma das características básicas de qualquer linguagem de programação, tomadas de decisão.
  Em CMake, a sintaxe das expressões de seleção não segue o padrão de uso de chaves, em vez disso a sintaxe é baseada em comandos:
       
       if(<EXPRESSÃO>)
              COMANDOS()
       elseif(<OUTRA_EXPRESSÃO>)
              COMANDOS()
       endif(<EXPRESSÃO>)
       
  Note que a expressão em endif tem propósito únicos de documentação, isto é, identificar qual if ela encerra.

* Targets - Provavelmente o item mais importante de um arquivo CMakeLists. Elas podem ser executáveis, bibliotecas e utilidades 
construídas pelo CMake. Cada add_library, add_executable e add_utility cria uma target. Por exemplo, um comando para criar uma 
target chamada flib como uma biblioteca estática gerada a partir dos arquivos fonte functions_1.c e functions_2.c.

        add_library(flib STATIC functions_1.c functions_2.c)
        
    Agora flib está disponível para uso em todo o projeto e o CMake saberá como expandi-la quando necessário.       

* Funções - Os comandos em CMake, aqui chamados de funções, possuem a seguinte sintaxe:

        COMANDO ( ARGUMENTOS )
       
  Em CMake não existe um caracter responsável por delimitar o fim de um argumento e o começo de outro, estes são separados pelos espaços
  em branco entre eles.

* Adicionar um executável - add_executable é o comando de CMake que usamos quando queremos que um executável seja construído a partir de
fontes fornecidos no comando. Lembre-se, em CMake, um executável é uma target. Nos próximos exemplos, o termo target será mais explorado,
mas por enquanto basta saber que essa target é um executável a ser gerado na compilação, e que um projeto pode ter várias targets dependentes,
ou não entre si.

  O comando add_executable tem a seguinte sintaxe básica:
  
        add_executable( nome_do_executável fontes)

  Onde fontes pode ser uma grande lista de arquivos fonte a serem combinados nessa target. A saída desse executável, quando não se altera
  o valor da variável EXECUTABLE_OUTPUT_PATH, será o diretório de binários. Mas no exemplo ela foi alterada. 

* Mensagem no status - CMake oferece a função message, para que o programador possa identificar gradualmente durante a configuração
o que está acontecendo, por exemplo.
  
  O comando MESSAGE em CMake tem a seguinte sintaxe básica:
  
      MESSAGE ( MODO "Mensagem")
      
  Os argumentos são mostrados em MODO (stdout ou stderr) e podem ser intercalados de diversas formas
  
      MESSAGE ( STATUS "String: " ${Variavel})
      MESSAGE ( STATUS ${Variável} ": String" ... ... Argumento N)
      
  Os comando acima são ambos válidos. Onde STATUS é um argumento opcional que apenas informa o CMake que a mensagem deve ser exibida na
  saída, e não em stderr.
  
* Adicionar um subdiretório - A semântica de adicionar um subdiretório em CMake nada tem haver com o comando include_directories
(caminho/ao/diretório) que será explicado em um exemplo futuro. Enquanto o comando include_directories adiciona os arquivos de um 
diretório especificado no comando ao escopo do diretório atual, o comando add_subdirectory se assemelha mais a um controlador de fluxo.
  
       add_subdirectory(src)
  
   Na chamada de um comando add_subdirectory(caminho/ao/subdiretório), a execução de CMake é levada imediatamente ao diretório
   especificado. Para que continue sua execução, CMake espera encontrar nesse novo diretório um novo arquivo CMakeLists.txt. Se este não
   existir, a execução é interrompida com uma mensagem de erro informando a inexistência de um arquivo CMakeLists.txt no subdiretório.
   
   Quando encontra o novo CMakeLists, CMake começa a execução dos comandos incrementalmente da mesma forma como fez no primeiro CMakeLists.
   Assim que passa por todos os comandos desse arquivo CMakeLists, a execução de CMake retorna ao CMakeLists que fez a chamada de
   add_subdirectory. Um arquivo CMakeLists já adicionado por add_subdirectory pode fazer novas chamadas de add_subdirectory e assim por
   diante.
   
   O escopo de arquivos do CMakeLists no subdiretório é apenas o do próprio subdiretório, isto é, ele não tem acesso às variáveis do
   diretório em que foi chamado. Para lida com essa limitação, existem alguns argumentos em funções que permitem certo uso dessas 
   variáveis.

 * Regras de Instalação - É possível adicionar regras de instalação para um projeto em CMake. Isso quer dizer, comandos que só serão executados
 em tempo de instalação de um projeto, por exemplo ao se fazer "sudo make install".
 
    Uma regra de instalação, nunca é chamada durante a fase de configuração de um projeto, muito menos os artefatos que ela cria podem ser
    aproveitados antes da instalação. As regras de instalação se estendem à targets, arquivos e diretórios. Cada um desses possui opções de
    instalação próprias, ainda que algumas sejam compartilhadas.
    
    No exemplo fornecido neste diretório há a instalação de uma target previamente adicionada pelo comando add_executable
    
        add_executable(hello main.c)
        
        install(TARGETS hello RUNTIME DESTINATION   ${PROJECT_SOURCE_DIR}/execs)
        
    que deve ser instalada da seguinte como um executável, por isso o argumento RUNTIME. O local onde essa target deve ser instalada é 
    especificado imediatamente após a palavra-reservada 'DESTINATION' e nesse caso ele é será ${PROJECT_SOURCE_DIR}/execs. Quando uma 
    variável de ambiente como essa, que guarda um 'path', é fornecida como parte do argumento de DESTINATION, o local de instalação é 
    avaliado com relação à ela. Se o diretório 'execs' ainda não existe no diretório de fontes do projeto, CMake criará o diretório e
    instalará nele a target 'hello'.

## Problemas no Visual Studio
Quando se tenta fazer uso do comando INSTALL de cmake em conjunto do generator Visual Studio, um problema surge. O nome da target sendo
instalada não será reconhecido ao se fazer a depuração do projeto INSTALL em Visual Studio. Isso se deve pelo fato dessa depuração procurar
por executável chamado INSTALL, apenas por ser o nome desse projeto. Dessa forma, como não o Visual Studio não consegue encontrar essa target
haverá um erro. Entretanto, a compilação e execução da target fornecida por add_executable continua perfeitamente normal.

Uma solução para isso é informar ao CMake de forma explícita no comando cmake um novo gerador. Aproveito esse erro para introduzir o uso
do compilador MinGW em exemplos futuros que façam o uso desse comando em CMake.

## Uso de MinGW
De forma geral, o uso de MinGw se assemelha bastante aos passos descritos de uso do cmake no prompt de comando do Windows.

Os passos para o uso do gerador MinGW através do prompt de comando do Windows são os seguintes:
1. Abra o prompt de comando.

2. Encontre o diretório do projeto e acesse a pasta build em seguida.

   Exemplo: cd Projetos/CMake - Basic/build

3. Dentro do subdiretório build execute o comando cmake .. -G "MinGw Makefiles". Isso informa ao CMake o caminho (no caso .., diretório 
pai) onde procurar por CMakeLists.txt, o arquivo básico descrito acima e também o gerador a ser utilizado. O gerador "MinGW Makefiles"
produz um arquivo Makefile a ser interpretado pelo compilador gcc, já que estamos usando a linguagem C, de MinGW.

4. Para compilar o projeto basta digitar

    mingw32-make
    
5. Agora que a target foi criada, podemos utilizar uma regra de instalação para ela. A instalação com MinGW é feita com o seguinte comando:

    mingw32-make install
   
6. Tudo pronto. Agora para executar o objeto gerado na etapa 6, basta abrir o diretório de saída que foi específicado em CMakeLists com a
variável ${EXECUTABLE_OUTPUT_PATH} e executá-lo com ./hello. Da mesma forma, para executar a target instalada, basta abrir o diretório
especificado após DESTINATION e executá-la com ./hello.


