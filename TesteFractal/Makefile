#Makefile

#Compilador
CC=g++

# Objects
OBJETOS = main.o Threads.o FundoInteiro.o FundoParcial.o
# Compilador flags - Warning, debug, sdl
CPPFLAGS=-std=c++0x -Wall -g -lm `sdl-config --cflags`

# Ligador flags - sdl
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lSDL_gfx

EXECUTAVEL=fracfly

#Compila o binario do jogo
#jogo: NaLimpeza FSuperficie NoEvento NoInic NoLaco NaRenderezicao FracFly FracFly.cpp
jogo: $(OBJETOS)
	$(CC) $(OBJETOS) $(CPPFLAGS) $(LDFLAGS) -o $(EXECUTAVEL)

main: $(OBJETOS) main.cpp 
	$(CC) $(CPPFLAGS) -c main.cpp

Threads: $(OBJETOS) Threads.hpp Threads.cpp 
	$(CC) $(CPPFLAGS) -c Threads.cpp

FundoParcial: $(OBJETOS) FundoParcial.hpp FundoParcial.cpp 
	$(CC) $(CPPFLAGS) -c FundoParcial.cpp

FundoInteiro: $(OBJETOS) FundoInteiro.cpp FundoInteiro.hpp
	$(CC) $(CPPFLAGS) -c FundoInteiro.cpp



#Instalar SDL
pacotes:
	sudo apt-get install libsdl-image1.2-dev libsdl-image1.2 libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl1.2-dev libsdl1.2debian freeglut3 freeglut3-dev

#limpeza
clean:
	rm -rf $(OBJETOS)
#	rm -rf $(EXECUTAVEL)
