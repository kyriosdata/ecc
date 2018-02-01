#Versão mínima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(TestsCMake C)

#Permite a criação de targets test.
#Essas targets estão definidas no subdiretório tests
enable_testing()

#Adiciona o subdiretório tests
#A execução desse CMakeLists é pausada aqui...
add_subdirectory(tests)

#...e retorna aqui
message(STATUS "CMakeLists no diretorio superior")