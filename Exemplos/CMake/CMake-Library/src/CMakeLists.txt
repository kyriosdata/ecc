#Vers�o m�nima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Mostra que a execu��o de CMake foi para outro diret�rio.
message(STATUS "CMakeLists in src")

#Criando uma lista de arquivos fonte.
set(Source main.c abb.c)

#Criando um execut�vel a partir dos fontes.
add_executable(abb ${Source})

#Inclui o diret�rio lib.
include_directories(${PROJECT_BINARY_DIR}/../lib)

#Procura uma biblioteca chamada abb dentro do diret�rio inclu�do
#e adiciona o que foi encontrado em ABB_LIB.
find_library(ABB_LIB NAMES abb PATHS "${PROJECT_BINARY_DIR}/../lib")

#Mostra o caminho at� a biblioteca encontrada. Apenas para confirmar
#que a vari�vel ABB_LIB foi iniciada.
message(STATUS "The library path ABB_LIB is " ${ABB_LIB})

#Liga o execut�vel � biblioteca que ele precisa para executar.
target_link_libraries(abb ${ABB_LIB})

#Muda o local onde o execut�vel deve ser armazenado
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if(UNIX)
	#Regra em tempo de instala��o:
	#abb � um execut�vel, portanto deve ser instalada como uma target RUNTIME
	#Essa regra permitir� que o script runAbb possa executar diretamente o execut�vel.
	install(TARGETS abb RUNTIME DESTINATION bin)
endif(UNIX)

#Regra em tempo de instala��o:
#Instala o script message.cmake 
#Esse script ser� executado no momento da instala��o.
install(SCRIPT message.cmake)
