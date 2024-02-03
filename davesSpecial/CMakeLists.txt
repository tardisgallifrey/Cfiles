cmake_minimum_required(VERSION 3.20)
project(davesSpecial C)

set(CMAKE_C_STANDARD 11)

add_executable(davesSpecial app.c
        app.h
        splash.c
        menu.c
        addentry.c
        init.c
        saverecord.c)
