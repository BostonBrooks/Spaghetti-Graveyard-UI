SET PATH=C:\winlibs\mingw64\bin
CD C:\Users\bbroo\CLionProjects\Spaghett-Graveyard-Zero\WinLibs
gcc -D SFML_STATIC -D GRAPHICS_LOW -I ../^
  ../test/demo2.c^
  ../source/bbGame.c^
  ../source/bbMap.c^
  ../source/bbDictionary.c^
  ../source/bbTextures.c^
  ../source/bbSprites.c^
  ../source/bbAnimation.c^
  ../source/bbWidget.c^
  ../source/bbGeometry.c^
  ../source/bbPool.c^
  ../source/bbTree.c^
  ../source/bbDispatch.c^
  ../source/bbMouse.c^
  ../source/bbFonts.c^
  ../source/bbCharacter.c^
  ../source/bbList.c^
  ../source/bbWidgetTimer.c^
  ../games/game/maps/demo2/widgets/widgets.c^
  ../source/bbGraphicsSettings.c^
  -lcsfml-system -lcsfml-graphics -lcsfml-window -g -w -lm
a.exe


