/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FEntidade.h"

/**
 * Inicializacao das Listas de Colisoes
 **/
std::vector<FEntidadeColisao> FEntidadeColisao::listaEntidadesColisoes;

/**
 * Inicializa um objeto colisão entre 2 entidades
 **/
FEntidadeColisao::FEntidadeColisao() {
		this->entidadeA = NULL;
		this->entidadeB = NULL;
}
