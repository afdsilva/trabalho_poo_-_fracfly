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
 * Metodo que faz a magica de desenhar as superficies na tela
 **/
void FracFly::NaRenderizacao() {
	
	FGerenciadorEstados::NaRenderizacao(planoExibicao);

	cursor.NaRenderizacao(planoExibicao);
	
	SDL_Flip(planoExibicao);

}
