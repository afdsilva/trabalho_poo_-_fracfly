#Makefile

#Compilador
CC=g++

# Objects
OBJETOS=male_libs.o Excecoes.o FSuperficie.o FFonte.o FEvento.o FAnimacao.o FEntidade.o FGerenciadorEstados.o FEntidadeColisao.o FEstado.o FEstadoIntro.o FEstadoJogo.o FEstadoMenu.o FEstadoOptions.o FCamera.o FFPS.o FNave.o FracFly_NaLimpeza.o FracFly_NoEvento.o FracFly_NoInic.o FracFly_NoLaco.o FracFly_NaRenderizacao.o FracFly.o

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
	rm -rf $(EXECUTAVEL)
	$(CC) $(CPPFLAGS) -c FracFly.cpp
male_libs: male_libs.h male_libs.cpp
	rm -rf male_libs.o
	$(CC) $(CPPFLAGS) -c male_libs.cpp
Excecoes: male_libs.o Excecoes.h Excecoes.cpp
	rm -rf Excecoes.o
	$(CC) $(CPPFLAGS) -c Excecoes.cpp
NoInic: FracFly.h FracFly_NoInic.cpp
	rm -rf NoInic.o
	$(CC) $(CPPFLAGS) -c FracFly_NoInic.cpp
NoEvento: FracFly.h FracFly_NoEvento.cpp
	rm -rf NoEvento.o
	$(CC) $(CPPFLAGS) -c FracFly_NoEvento.cpp
NoLaco: FracFly.h FracFly_NoLaco.cpp
	rm -rf NoLaco.o
	$(CC) $(CPPFLAGS) -c FracFly_NoLaco.cpp
NaRenderizacao: FracFly.h FracFly_NaRenderizacao.cpp
	rm -rf NaRenderizacao.o
	$(CC) $(CPPFLAGS) -c FracFly_NaRenderizacao.cpp
NaLimpeza: FracFly.h FracFly_NaLimpeza.cpp
	rm -rf NaLimpeza.o
	$(CC) $(CPPFLAGS) -c FracFly_NaLimpeza.cpp
FSuperficie: FSuperficie.h FSuperficie.cpp
	rm -rf FSuperficie.o
	$(CC) $(CPPFLAGS) -c FSuperficie.cpp
FFonte: FFonte.h FFonte.cpp
	rm -rf FFonte.o
	$(CC) $(CPPFLAGS) -c FFonte.cpp
FEvento: FEvento.h FEvento.cpp
	rm -rf FEvento.o
	$(CC) $(CPPFLAGS) -c FEvento.cpp
FAnimacao: FAnimacao.h FAnimacao.cpp
	rm -rf FAnimacao.o
	$(CC) $(CPPFLAGS) -c FAnimacao.cpp
FEntidade: FEntidade.h FEntidade.cpp
	rm -rf FEntidade.o
	$(CC) $(CPPFLAGS) -c FEntidade.cpp
FEntidadeColisao: FEntidade.h FEntidadeColisao.cpp
	rm -rf FEntidadeColisao.o
	$(CC) $(CPPFLAGS) -c FEntidadeColisao.cpp
FNave: FEntidade.h FNave.h FNave.cpp
	rm -rf FNave.o
	$(CC) $(CPPFLAGS) -c FNave.cpp

Threads: Threads.hpp Threads.cpp 
	rm -rf Threads.o
	$(CC) $(CPPFLAGS) -c Threads.cpp
FundoInteiro: FundoInteiro.hpp FundoInteiro.cpp 
	rm -rf FundoInteiro.o
	$(CC) $(CPPFLAGS) -c FundoInteiro.cpp
FundoParcial: FundoParcial.cpp   FundoParcial.hpp  
	rm -rf FundoParcial.o
	$(CC) $(CPPFLAGS) -c FundoParcial.cpp


FCamera: FCamera.h FCamera.cpp
	rm -rf FCamera.o
	$(CC) $(CPPFLAGS) -c FCamera.cpp
FFPS: FFPS.h FFPS.cpp
	rm -rf FFPS.o
	$(CC) $(CPPFLAGS) -c FFPS.cpp

FGerenciadorEstados: FGerenciadorEstados.h FGerenciadorEstados.cpp
	rm -rf FGerenciadorEstados.o
	$(CC) $(CPPFLAGS) -c FGerenciadorEstados.cpp
FEstado: FEstado.h FEstado.cpp
	rm -rf FEstado.o
	$(CC) $(CPPFLAGS) -c FGerenciadorEstados.cpp
FEstadoIntro: FEstado.h FEstadoIntro.h FEstadoIntro.cpp
	rm -rf FEstadoIntro.o
	$(CC) $(CPPFLAGS) -c FEstadoIntro.cpp
FEstadoMenu: FEstado.h FEstadoMenu.h FEstadoMenu.cpp
	rm -rf FEstadoMenu.o
	$(CC) $(CPPFLAGS) -c FEstadoMenu.cpp
FEstadoOptions: FEstado.h FEstadoOptions.h FEstadoOptions.cpp
	rm -rf FEstadoOptions.o
	$(CC) $(CPPFLAGS) -c FEstadoMenu.cpp
FEstadoJogo: FEstado.h FEstadoJogo.h FEstadoJogo.cpp
	rm -rf FEstadoJogo.o
	$(CC) $(CPPFLAGS) -c FEstadoJogo.cpp

#dependencias instaladas por apt-get
pacotes:
	sudo apt-get install libsdl-image1.2-dev libsdl-image1.2 libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl1.2-dev libsdl1.2debian libsdl-gfx1.2-4 libsdl-gfx1.2-dev libsdl-mixer1.2

# dependencias instaladas via linha de comando
dependencias:
	@echo "Verifique as dependencias necessarias:"
	@echo "make depM4 : instala m4-1.4.6"
	@echo "make depAutoconf : instala autoconf-2.69"
	@echo "make depAutomake : instala automake-1.13"
	@echo "make depFreetype : instala freetype-2.4.11"
	@echo "make depSDL_ttf : instala SDL_ttf-2.0.11"
	@echo "make depSDL_mixer : instala SDL_mixer-1.2.12"
	@echo "make deplibConfig : instala libconfig-1.4.9"

depM4:
	#verifica se m4 esta instalado
	M4=m4 --version | grep GNU | sed 's/GNU M4 \(.*\)/\1/'
	@echo cd /tmp 
	@echo wget http://ftp.gnu.org/gnu/m4/m4-1.4.6.tar.gz
	@echo tar xvzf m4-1.4.6.tar.gz
	@echo cd /tmp/m4-1.4.6/
	@echo ./configure
	@echo make
	@echo sudo make install

depAutoconf:
	#AUTOCONF=autoconf --version | grep autoconf | grep GNU | sed 's/.*) \(.*\)/\1/'
	@echo cd /tmp 
	@echo wget http://ftpmirror.gnu.org/autoconf/autoconf-2.69.tar.gz
	@echo tar xvzf autoconf-2.69.tar.gz
	@echo cd /tmp/autoconf-2.69/
	@echo ./configure
	@echo make
	@echo sudo make install

depAutomake:
	@echo cd /tmp 
	@echo wget ftp://ftp.gnu.org/gnu/automake/automake-1.13.tar.gz
	@echo tar xvzf automake-1.13.tar.xz
	@echo cd /tmp/automake-1.13/
	@echo ./configure
	@echo make
	@echo sudo make install

depFreetype:
	@echo cd /tmp 
	@echo wget http://download.savannah.gnu.org/releases/freetype/freetype-2.4.11.tar.gz
	@echo tar xvzf freetype-2.4.11.tar.gz
	@echo cd /tmp/freetype-2.4.11/
	@echo ./configure
	@echo make
	@echo sudo make install

depSDL_ttf:
	@echo cd /tmp 
	@echo wget http://www.libsdl.org/projects/SDL_ttf/release/SDL_ttf-2.0.11.tar.gz
	@echo tar xvzf SDL_ttf-2.0.11.tar.gz
	@echo cd /tmp/SDL_ttf-2.0.11/
	@echo ./configure
	@echo make
	@echo sudo make install

depSDL_mixer:
	@echo cd /tmp 
	@echo wget http://www.libsdl.org/projects/SDL_mixer/release/SDL_mixer-1.2.12.tar.gz
	@echo tar xvzf SDL_mixer-1.2.12.tar.gz
	@echo cd /tmp/SDL_mixer-1.2.12/
	@echo ./configure
	@echo make
	@echo sudo make install

deplibConfig:
	@echo nao utilizado
	@echo cd /tmp
	@echo wget http://www.hyperrealm.com/libconfig/libconfig-1.4.9.tar.gz
	@echo tar xvzf libconfig-1.4.9.tar.gz
	@echo cd /tmp/libconfig-1.4.9/
	@echo ./configure
	@echo make
	@echo sudo make install

runtime:
	sudo apt-get install libsdl1.2debian libsdl-gfx1.2-4 libsdl-mixer1.2 libsdl-image1.2 libsdl-ttf2.0-0 
#limpeza
clean:
	rm -rf $(OBJETOS)
#	rm -rf $(EXECUTAVEL)
