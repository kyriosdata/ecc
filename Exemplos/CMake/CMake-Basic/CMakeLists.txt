#Vers�o m�nima do CMake para executar esse CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(hello C)

#Nome do execut�vel e fonte a ser constru�da
add_executable(hello main.c)