cmake_minimum_required(VERSION 3.24)
project(ProjetCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetCPP main.cpp train.h billet.h passager.h reservation.h train.cpp billet.cpp passager.cpp reservation.cpp)
