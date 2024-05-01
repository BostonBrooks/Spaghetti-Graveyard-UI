cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used

project(myprogram C)
include_directories( ../ )
add_executable(myprogram Incremental_test.c
        ../headers/bbList.h
        ../source/bbList.c
        bbPriorityQueue_test.c
        ../headers/bbWidgetTimer.h
        ../source/bbWidgetTimer.c
        ../source/bbWidget.c
        ../games/game/maps/demo/widgets/widgets.c
        Incremental_test2.c
        ../headers/bbDeque2.h)
