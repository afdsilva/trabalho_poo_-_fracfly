#include "FracFly.h"

void FracFly::NoEvento(SDL_Event * Evento) {
	FEvento::NoEvento(Evento);
}

void FracFly::OnExit() {
	Rodando = false;
}

void FracFly::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_ESCAPE:
			OnExit();
			break;
		default:
			break;
	}
}
void FracFly::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	
}
