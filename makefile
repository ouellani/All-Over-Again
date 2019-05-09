Prog:fonction.o main.o
	gcc fonction.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
fonction.o:fonction.c
	gcc -c fonction.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

