#Requires CMake 3.5 or superior
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(LibsCMake C)

#Adiciona o subdiretório src
#CMake para a execução desse arquivo aqui...
add_subdirectory(src)

#...e retorna aqui
message(STATUS "CMakeLists in top-level dir")

if(WIN32)
	#Regra em tempo de instalação:
	#runHello.bat é uma target program a ser instalada em ${PROJECT_SOURCE_DIR}/scripts.
	#Para executar esse arquivo, abra o prompt de comando, procure o diretório em que
	#ela foi instalada e digite runAbb.bat.
	INSTALL(PROGRAMS runAbb.bat DESTINATION ${PROJECT_SOURCE_DIR}/scripts)	
elseif(UNIX)
	#Regra em tempo de instalação:
	#runHello.sh é uma target program a ser instalada em ${PROJECT_SOURCE_DIR}/scripts.
	#Para executar esse arquivo, abra o terminal, procure o diretório em que
	#ela foi instalada e digite runAbb.sh.
	INSTALL(PROGRAMS runAbb.sh DESTINATION ${PROJECT_SOURCE_DIR}/scripts)	
endif(WIN32)
