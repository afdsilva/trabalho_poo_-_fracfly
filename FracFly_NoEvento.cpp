#include "FracFly.h"

/**
 * Metodo NoEvento, herdada da classe FEvento, permite o uso dos metodos virtuais
 * implementado os eventos como teclas, movimento e clique do mouse
 **/
void FracFly::NoEvento(SDL_Event * evento) {

	FEvento::NoEvento(evento);

	FGerenciadorEstados::NoEvento(evento);

	if (FGerenciadorEstados::GetEstadoAtivoId() == ESTADO_NENHUM) OnExit();
}

/**
 * Metodos de Eventos
 **/

//Evento de saida, seta a variavel rodando como falsa, finalizando o laço infinito
void FracFly::OnExit() {
	rodando = false;
}

//Evento de movimentação do mouse e cliques enquanto se move
void FracFly::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	cursor.x = mX - (cursor.width / 2);
	cursor.y = mY - (cursor.height / 2);
	//cursor.SetAcel(relX,relY);
	//cout << "relX: " << relX << " relY: " << relY << endl;

}

//Evento de pressionar o botao esquerdo do mouse
void FracFly::OnLButtonDown(int mX, int mY) {
	cursor.clique = true;
}
//Evento de soltar o botao esquerdo do mouse
void FracFly::OnLButtonUp(int mX, int mY) {
	cursor.clique = false;
}
