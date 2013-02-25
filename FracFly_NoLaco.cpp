#include "FracFly.h"

#define FPS 60
Uint16 waittime = 1000.0f/FPS;
Uint16 framestarttime = 0;
Sint16 delaytime;

/**
 * Metodo que controla o laço (loop) do jogo, todas ações que requererem modificar dados das entidades
 * é feita nesse metodo;
 **/
void FracFly::NoLaco() {
	FGerenciadorEstados::NoLaco();
	
	FFPS::FPSControle.NoLaco();

	char buffer[255];
	sprintf(buffer, "Fracfly - FPS: %d", FFPS::FPSControle.GetFPS());
	SDL_WM_SetCaption(buffer, buffer);

	cursor.NoLaco();
	
	//Reduz o consumo de CPU adicionando um delay
	delaytime = waittime - (SDL_GetTicks() - framestarttime);
    if(delaytime > 0)
        SDL_Delay((Uint16)delaytime);
    framestarttime = SDL_GetTicks();
}
