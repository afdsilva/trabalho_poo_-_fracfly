#include "FFPS.h"

FFPS FFPS::FPSControle;

FFPS::FFPS() {
	TempoAntigo = 0;
	UltimoTempo = 0;
	
	FatorVelocidade = 0;
	
	Frames = 0;
	NumFrames = 0;
}

void FFPS::NoLaco() {
	if(TempoAntigo + 1000 < SDL_GetTicks()) {
		TempoAntigo = SDL_GetTicks();
		NumFrames = Frames;
		Frames = 0;
	}
	FatorVelocidade = ((SDL_GetTicks() - UltimoTempo) / 1000.0f) * 32.0f;
	
	UltimoTempo = SDL_GetTicks();
	
	Frames++;
}

int FFPS::GetFPS() {
	return NumFrames;
}

float FFPS::GetFatorVelocidade() {
	return FatorVelocidade;
}
