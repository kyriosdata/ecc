#Vers�o m�nima do CMake para executar esse CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(InstallUseCMake C)

#Arquivos que ser�o tornados uma biblioteca
set(Source main.c perceptron.c)

#Adiciona uma biblioteca din�mica
#Usada na execu��o em Unix.
add_library(perceptron_dynamic SHARED ${Source})

#Configura o nome da biblioteca din�mica como "perceptron"
set_target_properties(perceptron_dynamic PROPERTIES OUTPUT_NAME "perceptron")

#Atribui uma vers�o e uma vers�o da aplica��o em que a aplica��o � usada
set_target_properties(perceptron_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)	

#Adiciona uma biblioteca.
#Essa ser� usada na execu��o
add_library(perceptron_static STATIC ${Source})

#Configura o nome da biblioteca est�tica como "perceptron"
set_target_properties(perceptron_static PROPERTIES OUTPUT_NAME "perceptron")

#Regra em tempo de instala��o:
#Durante a instala��o use o c�digo "message(STATUS \"CONFIGURATION LIBS\")".
#Installs a code to show the current stage
install(CODE "message(STATUS \"CONFIGURING LIBS\")" )

#Regra em tempo de instala��o:
#A biblioteca din�mica � instalada como uma biblioteca.
#A biblioteca est�tica tem uma instala��o como arquivo para documenta��o
# e outra para ser usada durante a execu��o.
#Todas essas bibliotecas s�o instaladas em ${PROJECT_SOURCE_DIR}/lib
install(TARGETS perceptron_dynamic perceptron_static perceptron_static
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
        ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
		RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/lib)

##Regra em tempo de instala��o:
#perceptron.h � um arquivo a ser instalado em ${PROJECT_SOURCE_DIR}/lib.
install(FILES perceptron.h DESTINATION ${PROJECT_SOURCE_DIR}/lib)