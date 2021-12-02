cmake_minimum_required(VERSION 3.17)
project(Projeto)

set(CMAKE_CXX_STANDARD 14)

include_directories(state_machine)
include_directories(state_machine/bin)
include_directories(state_machine/inc)
include_directories(state_machine/src)

add_executable(Projeto
        state_machine/inc/dev_helper.h
        state_machine/inc/state_machine.h
        state_machine/src/state_machine.c
        state_machine/src/test_1.c
        state_machine/build.sh
        state_machine/LEIAME.txt)
