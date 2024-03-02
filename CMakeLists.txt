cmake_minimum_required(VERSION 3.26)
project(Spaghetti_Graveyard_Zero C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Spaghetti_Graveyard_Zero
        maps/demo/AI/AI_NULL.h
        headers/bbAI_FSM.h
        headers/bbAnimation.h
        headers/bbCommands.h
        headers/bbConstants.h
        headers/bbDictionary.h
        headers/bbDrawable.h
        headers/bbFlags.h
        headers/bbFloorDiv.h
        headers/bbGame.h
        headers/bbGeometry.h
        headers/bbGraphicsSettings.h
        headers/bbMap.h
        headers/bbMedia.h
        headers/bbPool.h
        headers/bbPrintf.h
        headers/bbSprites.h
        headers/bbSystemIncludes.h
        headers/bbTerrain.h
        headers/bbTextures.h
        headers/bbWidget.h
        source/bbDictionary.c
        source/bbPool.c
        test/Test_bbDictionary.c
        test/Test_bbPool.c
        test/Test_bbPrintf.c
        test/Test_calloc.c
        maps/demo/widgets/Widget_NULL.h)
