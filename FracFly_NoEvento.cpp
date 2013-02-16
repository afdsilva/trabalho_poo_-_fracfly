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
		case SDLK_UP:
			FEntidade::ListaEntidades[1]->moveCima = true;
			break;
		case SDLK_DOWN:
			FEntidade::ListaEntidades[1]->moveBaixo = true;
			break;
		case SDLK_RIGHT:
			FEntidade::ListaEntidades[1]->moveDireita = true;
			break;
		case SDLK_LEFT:
			FEntidade::ListaEntidades[1]->moveEsquerda = true;
			break;
		default:
			break;
	}
}
void FracFly::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_UP:
			FEntidade::ListaEntidades[1]->moveCima = false;
			break;
		case SDLK_DOWN:
			FEntidade::ListaEntidades[1]->moveBaixo = false;
			break;
		case SDLK_RIGHT:
			FEntidade::ListaEntidades[1]->moveDireita = false;
			break;
		case SDLK_LEFT:
			FEntidade::ListaEntidades[1]->moveEsquerda = false;
			break;
		default:
			break;
	}
}

void FracFly::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	
	double distancia = sqrt(pow(mX - Arma1.X, 2) + pow(mY - Arma1.Y, 2));
	
	double deltay =  (double) Arma1.Y-mY ;
	
	
	double angulo = (double) 90*(deltay/distancia);
    
    /* Rotate */
    SDL_Surface *extraSurface;
    extraSurface = rotozoomSurface(Arma1.getSurface(), angulo, 1, 1); 
    Arma1.setSurface(extraSurface); 			
	
}

void FracFly::OnLButtonDown(int mX, int mY) {
	Arma1.Atirar(mX,mY);
}
void FracFly::OnLButtonUp(int mX, int mY) {
	
}
void FracFly::OnRButtonDown(int mX, int mY) {
	
}
void FracFly::OnRButtonUp(int mX, int mY) {
	
}
void FracFly::OnMButtonDown(int mX, int mY) {
	
}
void FracFly::OnMButtonUp(int mX, int mY) {
	
}
