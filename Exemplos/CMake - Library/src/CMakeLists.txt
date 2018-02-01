#Versão mínima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Mostra que a execução de CMake foi para outro diretório.
message(STATUS "CMakeLists in src")

#Criando uma lista de arquivos fonte.
set(Source main.c abb.c)

#Criando um executável a partir dos fontes.
add_executable(abb ${Source})

#Inclui o diretório lib.
include_directories(${PROJECT_BINARY_DIR}/../lib)

#Procura uma biblioteca chamada abb dentro do diretório incluído
#e adiciona o que foi encontrado em ABB_LIB.
find_library(ABB_LIB NAMES abb PATHS "${PROJECT_BINARY_DIR}/../lib")

#Mostra o caminho até a biblioteca encontrada. Apenas para confirmar
#que a variável ABB_LIB foi iniciada.
message(STATUS "The library path ABB_LIB is " ${ABB_LIB})

#Liga o executável à biblioteca que ele precisa para executar.
target_link_libraries(abb ${ABB_LIB})

#Muda o local onde o executável deve ser armazenado
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if(UNIX)
	#Regra em tempo de instalação:
	#abb é um executável, portanto deve ser instalada como uma target RUNTIME
	#Essa regra permitirá que o script runAbb possa executar diretamente o executável.
	install(TARGETS abb RUNTIME DESTINATION bin)
endif(UNIX)

#Regra em tempo de instalação:
#Instala o script message.cmake 
#Esse script será executado no momento da instalação.
install(SCRIPT message.cmake)
