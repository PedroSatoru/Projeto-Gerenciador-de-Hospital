cmake_minimum_required(VERSION 3.10)
project(MeuProjeto C)

# Define o padrão de compilação para o C
set(CMAKE_C_STANDARD 11)

# Adiciona a biblioteca
add_library(bibliotecas src/bibliotecas/biblioteca.c)

# Define o executável principal
add_executable(meu_programa src/main.c)

# Linka o executável com a biblioteca
target_link_libraries(meu_programa bibliotecas)
