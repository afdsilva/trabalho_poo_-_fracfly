#include "FFPS.h"

FFPS FFPS::FPSControle;

FFPS::FFPS() {
	tempoAntigo = 0;
	ultimoTempo = 0;
	
	fatorVelocidade = 0;
	
	frames = 0;
	numFrames = 0;
}

void FFPS::NoLaco() {
	if(tempoAntigo + 1000 < (int)SDL_GetTicks()) {
		tempoAntigo = SDL_GetTicks();
		numFrames = frames;
		frames = 0;
	}
	fatorVelocidade = ((SDL_GetTicks() - ultimoTempo) / 1000.0f) * 40.0f;
	
	ultimoTempo = SDL_GetTicks();
	
	frames++;
}

int FFPS::GetFPS() {
	return numFrames;
}

float FFPS::GetFatorVelocidade() {
	return fatorVelocidade;
}
