SET PATH=C:\winlibs\mingw64\bin
CD C:\Users\bbroo\CLionProjects\Spaghett-Graveyard-Zero\WinLibs
gcc -D SFML_STATIC -I ../^
  ../source/bbPool.c^
  ../source/bbPriorityQueue.c^
  ../test/bbPriorityQueue_test.c^
  -lcsfml-system -lcsfml-graphics -lcsfml-window -g -w -lm
a.exe

