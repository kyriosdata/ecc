#Versão mínima do CMake para executar esse CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(ConfigCMake C)

#Adiciona o subdiretório src
#CMake para a execução desse arquivo aqui...
add_subdirectory(config)

#...e retorna aqui
message(STATUS "CMakeLists no diretorio superior")
