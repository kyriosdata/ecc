#Vers�o m�nima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Mensagem para sinalizar que a execu��o do CMake agora
# est� no arquivo CMakeLists dentro de src.
message(STATUS "CMakeLists dentro de src")

#Adiciona um execut�vel construido com o fonte de /src,
# ou seja, do diret�rio atual.
add_executable(hello main.c)

#Configura uma vari�vel para determinar onde o execut�vel
# deve ser armazenado.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#Regra em tempo de instala��o:
#hello � um execut�vel, portanto deve ser tratado como uma
# target RUNTIME. Essa regra, especifica o diret�rio onde 
# essa target deve ser encontrada.
install(TARGETS hello RUNTIME DESTINATION   ${PROJECT_SOURCE_DIR}/execs)