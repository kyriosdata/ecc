#Versão mínima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Mensagem para sinalizar que a execução do CMake agora
# está no arquivo CMakeLists dentro de src.
message(STATUS "CMakeLists dentro de src")

#Adiciona um executável construido com o fonte de /src,
# ou seja, do diretório atual.
add_executable(hello main.c)

#Configura uma variável para determinar onde o executável
# deve ser armazenado.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#Regra em tempo de instalação:
#hello é um executável, portanto deve ser tratado como uma
# target RUNTIME. Essa regra, especifica o diretório onde 
# essa target deve ser encontrada.
install(TARGETS hello RUNTIME DESTINATION   ${PROJECT_SOURCE_DIR}/execs)