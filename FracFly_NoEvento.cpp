#include "FracFly.h"

void FracFly::NoEvento(SDL_Event * Evento) {
	if(Evento->type == SDL_QUIT) {
		Rodando = false;
	}
}
