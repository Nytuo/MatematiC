cmake_minimum_required(VERSION 3.20)
project(MatematiC C)

set(CMAKE_C_STANDARD 99)

include_directories("${CMAKE_SOURCE_DIR}")

add_executable(MatematiC
        entetesGestionGrille.h
        entetesVersion1.h
        entetesVersion2.h
        gestionGrille.c
        main.c version1.c version2.c)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/grille.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)