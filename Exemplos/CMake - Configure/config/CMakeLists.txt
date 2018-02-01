#Versão mínima do CMake para executar esse CMakeLists.txt
cmake_minimum_required(VERSION 3.0)

#Atribui um identificador de acordo com o sistema
if(WIN32)
	SET( ID 1 )

elseif(UNIX)
	SET( ID 2 )

endif()

#Atribui uma memória RAM
SET( RAM 8 )

#Configura o arquivo sistema.h a partir do arquivo sistema.h.in
CONFIGURE_FILE( ${CMAKE_SOURCE_DIR}/config/sistema.h.in ${CMAKE_SOURCE_DIR}/config/sistema.h )

#Adiciona um executável sistema a partir do fonte sistema.c
add_executable(sistema sistema.c)

#Escolhe o caminho de saída do binário
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)