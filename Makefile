#Makefile

#Compilador
CC=g++

# Objects
OBJETOS=male_libs.o FSuperficie.o FFonte.o FEvento.o FAnimacao.o FEntidade.o FGerenciadorEstados.o FEntidadeColisao.o FEstado.o FEstadoIntro.o FEstadoJogo.o FEstadoMenu.o FAzulejo.o FMap.o FCamera.o FFPS.o FArea.o FNave.o FracFly_NaLimpeza.o FracFly_NoEvento.o FracFly_NoInic.o FracFly_NoLaco.o FracFly_NaRenderizacao.o FracFly.o FundoParcial.o FundoInteiro.o Threads.o

# Compilador flags - Warning, debug, sdl
CPPFLAGS=-std=c++0x -Wall -g -lm `sdl-config --cflags`

# Ligador flags - sdl
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf 

EXECUTAVEL=fracfly

#Compila o binario do jogo
#jogo: NaLimpeza FSuperficie NoEvento NoInic NoLaco NaRenderezicao FracFly FracFly.cpp
jogo: $(OBJETOS) FracFly.h FracFly.cpp
	$(CC) $(OBJETOS) $(CPPFLAGS) $(LDFLAGS) -o $(EXECUTAVEL)
FracFly: $(OBJETOS) FracFly.h FracFly.cpp
	$(CC) $(CPPFLAGS) -c FracFly.cpp
male_libs: male_libs.h male_libs.cpp
	$(CC) $(CPPFLAGS) -c male_libs.cpp
NoInic: FracFly.h FracFly_NoInic.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoInic.cpp
NoEvento: FracFly.h FracFly_NoEvento.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoEvento.cpp
NoLaco: FracFly.h FracFly_NoLaco.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NoLaco.cpp
NaRenderizacao: FracFly.h FracFly_NaRenderizacao.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NaRenderizacao.cpp
NaLimpeza: FracFly.h FracFly_NaLimpeza.cpp
	$(CC) $(CPPFLAGS) -c FracFly_NaLimpeza.cpp
FSuperficie: FSuperficie.h FSuperficie.cpp
	$(CC) $(CPPFLAGS) -c FSuperficie.cpp
FFonte: FFonte.h FFonte.cpp
	$(CC) $(CPPFLAGS) -c FFonte.cpp
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


Threads: Threads.hpp Threads.cpp 
	$(CC) $(CPPFLAGS) -c Threads.cpp
	
FundoInteiro: FundoInteiro.hpp FundoInteiro.cpp 
	$(CC) $(CPPFLAGS) -c FundoInteiro.cpp
	
FundoParcial: FundoParcial.cpp   FundoParcial.hpp  
	$(CC) $(CPPFLAGS) -c FundoParcial.cpp


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

FGerenciadorEstados: FGerenciadorEstados.h FGerenciadorEstados.cpp
	$(CC) $(CPPFLAGS) -c FGerenciadorEstados.cpp
FEstado: FEstado.h FEstado.cpp
	$(CC) $(CPPFLAGS) -c FGerenciadorEstados.cpp
FEstadoIntro: FEstado.h FEstadoIntro.h FEstadoIntro.cpp
	$(CC) $(CPPFLAGS) -c FEstadoIntro.cpp
FEstadoMenu: FEstado.h FEstadoMenu.h FEstadoMenu.cpp
	$(CC) $(CPPFLAGS) -c FEstadoMenu.cpp
FEstadoJogo: FEstado.h FEstadoJogo.h FEstadoJogo.cpp
	$(CC) $(CPPFLAGS) -c FEstadoJogo.cpp
#Instalar SDL
pacotes:
	sudo apt-get install libsdl-image1.2-dev libsdl-image1.2 libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl1.2-dev libsdl1.2debian libsdl-gfx1.2-4 libsdl-gfx1.2-dev libsdl-mixer1.2

dependencias:
	@echo "Dependencias"
	#verifica se m4 esta instalado
	#M4=m4 --version | grep GNU | sed 's/GNU M4 \(.*\)/\1/'
	#cd /tmp 
	#wget http://ftp.gnu.org/gnu/m4/m4-1.4.6.tar.gz
	#tar xvzf m4-1.4.6.tar.gz
	#cd /tmp/m4-1.4.6/
	#./configure
	#make
	#sudo make install

	#AUTOCONF=autoconf --version | grep autoconf | grep GNU | sed 's/.*) \(.*\)/\1/'
	#cd /tmp 
	#wget http://ftpmirror.gnu.org/autoconf/autoconf-2.69.tar.gz
	#tar xvzf autoconf-2.69.tar.gz
	#cd /tmp/autoconf-2.69/
	#./configure
	#make
	#sudo make install

	#cd /tmp 
	#wget ftp://ftp.gnu.org/gnu/automake/automake-1.13.tar.gz
	#tar xvzf automake-1.13.tar.xz
	#cd /tmp/automake-1.13/
	#./configure
	#make
	#sudo make install


	#cd /tmp 
	#wget http://download.savannah.gnu.org/releases/freetype/freetype-2.4.11.tar.gz
	#tar xvzf freetype-2.4.11.tar.gz
	#cd /tmp/freetype-2.4.11/
	#./configure
	#make
	#sudo make install


	#cd /tmp 
	#wget http://www.libsdl.org/projects/SDL_ttf/release/SDL_ttf-2.0.11.tar.gz
	#tar xvzf SDL_ttf-2.0.11.tar.gz
	#cd /tmp/SDL_ttf-2.0.11/
	#./configure
	#make
	#sudo make install

	#cd /tmp 
	#wget http://www.libsdl.org/projects/SDL_mixer/release/SDL_mixer-1.2.12.tar.gz
	#tar xvzf SDL_mixer-1.2.12.tar.gz
	#cd /tmp/SDL_mixer-1.2.12/
	#./configure
	#make
	#sudo make install

runtime:
	sudo apt-get install libsdl1.2debian libsdl-gfx1.2-4 libsdl-mixer1.2 libsdl-image1.2 libsdl-ttf2.0-0 
#limpeza
clean:
	rm -rf $(OBJETOS)
#	rm -rf $(EXECUTAVEL)
