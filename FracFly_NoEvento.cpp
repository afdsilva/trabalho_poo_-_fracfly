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
