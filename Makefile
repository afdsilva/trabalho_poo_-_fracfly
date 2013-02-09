#Makefile

#Compilador
CC=g++

# Objects
OBJETOS=FracFly.o FracFly_NaLimpeza.o FracFly_NoEvento.o FracFly_NoInic.o FracFly_NoLaco.o FracFly_NaRenderizacao.o

# Compilador flags - Warning, debug, sdl
CPPFLAGS=-Wall -g `sdl-config --cflags`

# Ligador flags - sdl
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image

EXECUTAVEL=fracfly

#Compila o binario do jogo
jogo: NaLimpeza NoEvento NoInic NoLaco NaRenderezicao FracFly FracFly.cpp
	$(CC) $(OBJETOS) $(CPPFLAGS) $(LDFLAGS) -o $(EXECUTAVEL)

all:
	
FracFly:
	$(CC) $(CPPFLAGS) -c FracFly.cpp
NoInic: FracFly.h FracFly_NoInic.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoInic.cpp
NoEvento: FracFly.h FracFly_NoEvento.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoEvento.cpp
NoLaco: FracFly.h FracFly_NoLaco.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoLaco.cpp
NaRenderezicao: FracFly.h FracFly_NaRenderizacao.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NaRenderizacao.cpp
NaLimpeza: FracFly.h FracFly_NaLimpeza.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NaLimpeza.cpp

#limpeza
clean:
	rm -rf $(OBJETOS)
	rm -rf $(EXECUTAVEL)
