/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FracFly.h"

/**
 * Metodo NoEvento, herdada da classe FEvento, permite o uso dos metodos virtuais
 * implementado os eventos como teclas, movimento e clique do mouse
 **/
void FracFly::NoEvento(SDL_Event * evento) {

	//Chama o NoEvento do metodo pai para tratamento de eventos
	FEvento::NoEvento(evento);

	//controla os eventos do gerenciador de estados (no gerenciador
	FGerenciadorEstados::NoEvento(evento);

	//Quando o estado for ESTADO_NENHUM, sai do programa
	if ((ultimoEstado = FGerenciadorEstados::GetEstadoAtivoId()) == ESTADO_NENHUM) OnExit();
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

}

//Evento de pressionar o botao esquerdo do mouse
void FracFly::OnLButtonDown(int mX, int mY) {
	if (ultimoEstado == FGerenciadorEstados::GetEstadoAtivoId())
		cursor.clique = true;
}
//Evento de soltar o botao esquerdo do mouse
void FracFly::OnLButtonUp(int mX, int mY) {
	cursor.clique = false;
}
