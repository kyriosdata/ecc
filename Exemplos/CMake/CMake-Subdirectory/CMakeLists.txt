#Vers�o m�nima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(SubCMake C)

#Simples express�o para verificar se o sistema � Windowws ou Unix
if(WIN32)
	message(STATUS "Esse eh um sistema Windows")
elseif(UNIX)
	message(STATUS "Esse eh um sistema UNIX")
endif()

#Mensagens que informam o caminho para o fonte e o caminho para os bin�rios
message(STATUS "DIRETORIO BINARIO: " ${PROJECT_BINARY_DIR})
message(STATUS "DIRETORIO DE FONTES: " ${PROJECT_SOURCE_DIR})

#Adiciona um subidret�rio chamado src, 
# que deve conter seu pr�prio CMakeLists.txt
#A execu��o do CMakLists do diret�rio superior
# � pausa aqui...
add_subdirectory(src)

#...e retorna nesse comando
message(STATUS "CMakeLists no diretorio superior")