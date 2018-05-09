#Versão mínima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Nome do projeto
project(TestsCMake C)

#O compilador GCC precisa de flags para saber que deve produzir 
#uma cobertura de testes
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

#Permite a criação de targets test.
#Essas targets estão definidas no subdiretório tests
enable_testing()

#Adiciona o subdiretório tests
#A execução desse CMakeLists é pausada aqui...
add_subdirectory(tests)

#...e retorna aqui
message(STATUS "CMakeLists no diretorio superior")
