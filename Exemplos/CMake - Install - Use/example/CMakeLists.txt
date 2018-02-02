#Versão mínima do CMake para executar esse CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

#Lista de fontes para a compilação da target executable
set(Fonte ../main.c)

#Adiciona a target executável a partir dos arquivos desse subdiretório
add_executable(main ${Fonte})

#Procura bibliotecas com o nome abb no diretório lib,
# previamente abastecido por install (targets ...),
# e armazenas as bibliotecas encontradas em ABB_LIB.
find_library(PRC_LIB NAMES perceptron PATHS "../lib")

#Mostra o caminho da biblioteca.
message(STATUS "O caminhdo da biblioteca eh: " ${PRC_LIB})

#Liga a target executável com as bibliotecas que ele
# precisa para executar.
target_link_libraries(main ${PRC_LIB})

#Define o local onde o executável será armazenado
# como ${PROJECT_BINARY_DIR}/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#No sistema Windows, a .dll encontrada deve estar junto 
# ao executável, caso contrário o executável não será 
# executado.
if(WIN32)
	file(COPY ${PRC_LIB}
        DESTINATION ${EXECUTABLE_OUTPUT_PATH})
endif(WIN32)