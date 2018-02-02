#Versão mínima do CMake para executar esse CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(InstallUseCMake C)

#Arquivos que serão tornados uma biblioteca
set(Source main.c perceptron.c)

#Adiciona uma biblioteca dinâmica
#Usada na execução em Unix.
add_library(perceptron_dynamic SHARED ${Source})

#Configura o nome da biblioteca dinâmica como "perceptron"
set_target_properties(perceptron_dynamic PROPERTIES OUTPUT_NAME "perceptron")

#Atribui uma versão e uma versão da aplicação em que a aplicação é usada
set_target_properties(perceptron_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)	

#Adiciona uma biblioteca.
#Essa será usada na execução
add_library(perceptron_static STATIC ${Source})

#Configura o nome da biblioteca estática como "perceptron"
set_target_properties(perceptron_static PROPERTIES OUTPUT_NAME "perceptron")

#Regra em tempo de instalação:
#Durante a instalação use o código "message(STATUS \"CONFIGURATION LIBS\")".
#Installs a code to show the current stage
install(CODE "message(STATUS \"CONFIGURING LIBS\")" )

#Regra em tempo de instalação:
#A biblioteca dinâmica é instalada como uma biblioteca.
#A biblioteca estática tem uma instalação como arquivo para documentação
# e outra para ser usada durante a execução.
#Todas essas bibliotecas são instaladas em ${PROJECT_SOURCE_DIR}/lib
install(TARGETS perceptron_dynamic perceptron_static perceptron_static
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
        ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
		RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/lib)

##Regra em tempo de instalação:
#perceptron.h é um arquivo a ser instalado em ${PROJECT_SOURCE_DIR}/lib.
install(FILES perceptron.h DESTINATION ${PROJECT_SOURCE_DIR}/lib)