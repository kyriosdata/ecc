#Vers�o m�nima do CMake para executar esse CMakeLists.
cmake_minimum_required(VERSION 3.0)

#Adiciona um execut�vel
add_executable(test_target main.c cmockatest.c)

#Muda a sa�da do execut�vel.
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#Os argumentos passados ao execut�vel do teste s�o os seguintes
#test(ID_TEST, ARG_1, ARG_2)
add_test(Test_Target0 ${PROJECT_BINARY_DIR}/bin/test_target 1 10 -10)	
add_test(Test_Target1 ${PROJECT_BINARY_DIR}/bin/test_target 2 11 -10)
add_test(Test_Target2 ${PROJECT_BINARY_DIR}/bin/test_target 1 12 -12)	
add_test(Test_Target3 ${PROJECT_BINARY_DIR}/bin/test_target 1 10 -11)
add_test(Test_Target4 ${PROJECT_BINARY_DIR}/bin/test_target 1 05 -05)
add_test(Test_Target5 ${PROJECT_BINARY_DIR}/bin/test_target 2 12  12)
add_test(Test_Target6 ${PROJECT_BINARY_DIR}/bin/test_target 2 10  12)