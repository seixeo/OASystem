cmake_minimum_required(VERSION 3.29)
project(OASystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(OASystem src/main.cpp
        src/OASystemUI.cpp
        inc/OASystemUI.h
        src/OAUtils.cpp
        inc/OAUtils.h
        src/OAAdmin.cpp
        inc/OAAdmin.h
        src/OAUser.cpp
        inc/OAUser.h
        src/OADataCenter.cpp
        inc/OADataCenter.h
)
