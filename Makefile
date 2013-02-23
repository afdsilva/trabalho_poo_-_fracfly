#Makefile

#Compilador
CC=g++

# Objects
OBJETOS=FSuperficie.o FEvento.o FAnimacao.o FEntidade.o FEntidadeColisao.o FAzulejo.o FMap.o FCamera.o FFPS.o FArea.o FNave.o FracFly_NaLimpeza.o FracFly_NoEvento.o FracFly_NoInic.o FracFly_NoLaco.o FracFly_NaRenderizacao.o FracFly.o 

# Compilador flags - Warning, debug, sdl
CPPFLAGS=-std=c++0x -Wall -g -lm `sdl-config --cflags`

# Ligador flags - sdl
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lSDL_gfx

EXECUTAVEL=fracfly

#Compila o binario do jogo
#jogo: NaLimpeza FSuperficie NoEvento NoInic NoLaco NaRenderezicao FracFly FracFly.cpp
jogo: $(OBJETOS) FracFly.h FracFly.cpp
	$(CC) $(OBJETOS) $(CPPFLAGS) $(LDFLAGS) -o $(EXECUTAVEL)
FracFly: $(OBJETOS) FracFly.h FracFly.cpp
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
FSuperficie: FSuperficie.h FSuperficie.cpp
	$(CC) $(CPPFLAGS) -c FSuperficie.cpp
FEvento: FEvento.h FEvento.cpp
	$(CC) $(CPPFLAGS) -c FEvento.cpp
FAnimacao: FAnimacao.h FAnimacao.cpp
	$(CC) $(CPPFLAGS) -c FAnimacao.cpp
FEntidade: FEntidade.h FEntidade.cpp
	$(CC) $(CPPFLAGS) -c FEntidade.cpp
FEntidadeColisao: FEntidade.h FEntidadeColisao.cpp
	$(CC) $(CPPFLAGS) -c FEntidadeColisao.cpp
FNave: FEntidade.h FNave.h FNave.cpp
	$(CC) $(CPPFLAGS) -c FNave.cpp


FCamera: FCamera.h FCamera.cpp
	$(CC) $(CPPFLAGS) -c FCamera.cpp
FArea: FMap.h FArea.h FArea.cpp
	$(CC) $(CPPFLAGS) -c FArea.cpp
FMap: FMap.h FMap.cpp
	$(CC) $(CPPFLAGS) -c FMap.cpp
FAzulejo: FAzulejo.h FAzulejo.cpp
	$(CC) $(CPPFLAGS) -c FAzulejo.cpp
FFPS: FFPS.h FFPS.cpp
	$(CC) $(CPPFLAGS) -c FFPS.cpp

#Instalar SDL
pacotes:
	sudo apt-get install libsdl-image1.2-dev libsdl-image1.2 libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl1.2-dev libsdl1.2debian libsdl-gfx1.2-4 libsdl-gfx1.2-dev

#limpeza
clean:
	rm -rf $(OBJETOS)
#	rm -rf $(EXECUTAVEL)
