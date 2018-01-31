#Versão mínima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(SubCMake C)

#Simples expressão para verificar se o sistema é Windowws ou Unix
if(WIN32)
	message(STATUS "Esse eh um sistema Windows")
elseif(UNIX)
	message(STATUS "Esse eh um sistema UNIX")
endif()

#Mensagens que informam o caminho para o fonte e o caminho para os binários
message(STATUS "DIRETORIO BINARIO: " ${PROJECT_BINARY_DIR})
message(STATUS "DIRETORIO DE FONTES: " ${PROJECT_SOURCE_DIR})

#Adiciona um subidretório chamado src, 
# que deve conter seu próprio CMakeLists.txt
#A execução do CMakLists do diretório superior
# é pausa aqui...
add_subdirectory(src)

#...e retorna nesse comando
message(STATUS "CMakeLists no diretorio superior")