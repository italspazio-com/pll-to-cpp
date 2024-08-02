cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(CleanPllLoop)

# Imposta lo standard del C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aggiungi il file sorgente
set(SOURCE_FILES clean_pll_loop.cpp)

# Trova le librerie Boost
find_package(Boost REQUIRED COMPONENTS iostreams system filesystem)

# Include le directory di Boost
include_directories(${Boost_INCLUDE_DIRS})

# Crea l'eseguibile
add_executable(main ${SOURCE_FILES})

# Linka le librerie Boost
target_link_libraries(main ${Boost_LIBRARIES})
