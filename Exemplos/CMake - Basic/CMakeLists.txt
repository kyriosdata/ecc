#Versão mínima do CMake para executar esse CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(hello C)

#Nome do executável e fonte a ser construída
add_executable(hello main.c)