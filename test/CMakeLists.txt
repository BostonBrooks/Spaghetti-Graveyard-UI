cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used

project(myprogram C)
include_directories( ../ )
add_executable(/test/demo2.c
        ../source/bbAnimation.c
        ../source/bbCharacter.c
        ../source/bbDictionary.c
        ../source/bbDispatch.c
        ../source/bbFonts.c
        ../source/bbGame.c
        ../source/bbGeometry.c
        ../source/bbGraphicsSettings.c
        ../source/bbList.c
        ../source/bbMap.c
        ../source/bbMouse.c
        ../source/bbPool.c
        ../source/bbSprites.c
        ../source/bbTextures.c
        ../source/bbTree.c
        ../source/bbWidget.c
        ../source/bbWidgetTimer.c
        ../games/game/maps/demo2/widgets/widgets.c
        ../games/game/maps/demo2/widgets/fireworks.h
        ../games/game/maps/demo2/widgets/layout.h
        ../games/game/maps/demo2/widgets/MouseClickText.h
        ../games/game/maps/demo2/widgets/prompt.h
        ../games/game/maps/demo2/widgets/sphere.h
        ../games/game/maps/demo2/widgets/textBox.h
        ../games/game/maps/demo2/widgets/viewport.h
        ../games/game/maps/demo2/widgets/emptyWidget.h
        ../games/game/maps/demo2/widgets/spellbar/spellbar.h
        ../games/game/maps/demo2/widgets/spellbar/spell.h
        ../games/game/maps/demo2/widgets/drawFunctions/AnimationDraw.h
        ../games/game/maps/demo2/widgets/drawFunctions/CoolDownDraw.h
        ../games/game/maps/demo2/widgets/drawFunctions/FrameDraw.h
        ../games/game/maps/demo2/widgets/drawFunctions/RenderTextureDraw.h
        ../games/game/maps/demo2/widgets/drawFunctions/SpriteDraw.h
        ../games/game/maps/demo2/widgets/drawFunctions/TextDraw.h)
