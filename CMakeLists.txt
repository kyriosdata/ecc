cmake_minimum_required(VERSION 3.0)

project(exemplo C)

add_executable(exemplo exemplo.c)

if(WIN32)
	message(STATUS "Executando em Windows")
elseif(UNIX)
	message(STATUS "Executando em Unix")	
endif(WIN32)