#include "FracFly.h"

/**
 * Metodo NoEvento, herdada da classe FEvento, permite o uso dos metodos virtuais
 * implementado os eventos como teclas, movimento e clique do mouse
 **/
void FracFly::NoEvento(SDL_Event * Evento) {
	FEvento::NoEvento(Evento);
}

/**
 * Metodos de Eventos
 **/

//Evento de saida, seta a variavel rodando como falsa, finalizando o laço infinito
void FracFly::OnExit() {
	rodando = false;
}

//Evento de tecla pressionada
void FracFly::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_ESCAPE: //Esc
			OnExit();
			break;
		default:
			break;
	}
}
//Evento de soltar a tecla pressionada
void FracFly::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		default:
			break;
	}
}

//Evento de movimentação do mouse e cliques enquanto se move
void FracFly::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
}
//Evento de pressionar o botao esquerdo do mouse
void FracFly::OnLButtonDown(int mX, int mY) {
	//Arma1.Atirar(mX,mY);
}
//Evento de soltar o botao esquerdo do mouse
void FracFly::OnLButtonUp(int mX, int mY) {
	
}
//Evento de pressionar o botao direito do mouse
void FracFly::OnRButtonDown(int mX, int mY) {
	
}
//Evento de soltar o botao direito do mouse
void FracFly::OnRButtonUp(int mX, int mY) {
	
}
//Evento de pressionar o botao do meio do mouse
void FracFly::OnMButtonDown(int mX, int mY) {
	
}
//Evento de soltar o botao do meio do mouse
void FracFly::OnMButtonUp(int mX, int mY) {
	
}
