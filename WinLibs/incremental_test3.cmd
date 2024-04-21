SET PATH=C:\winlibs\mingw64\bin
CD C:\Users\bbroo\CLionProjects\Spaghett-Graveyard-Zero\WinLibs
gcc -D SFML_STATIC -I ../^
  ../test/Incremental_test3.c^
  ../games/game/maps/demo/widgets/widgets.c^
  -lcsfml-system -lcsfml-graphics -lcsfml-window -g -w -lm
a.exe


