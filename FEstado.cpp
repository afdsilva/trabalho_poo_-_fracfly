/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FEstado.h"

/**
 * Constutor do Metodo FEstado, puramente virtual, implementacao real depende do estado corrente
 */
FEstado::FEstado() {
}
/**
 * Metodo que sera executado quando o estado for ativado, puramente virtual, implementacao real depende do estado corrente
 */
void FEstado::NaAtivacao() {
}

/**
 * Metodo que sera executado quando o mudar de estado, puramente virtual, implementacao real depende do estado corrente
 */
void FEstado::NaDesativacao() {
}

/**
 * Metodo que faz o controle de dados do estado, puramente virtual, implementacao real depende do estado corrente
 */
void FEstado::NoLaco() {
}

/**
 * Metodo que renderiza as camadas do estado, puramente virtual, implementacao real depende do estado corrente
 */
void FEstado::NaRenderizacao(SDL_Surface * planoExibicao) {
}
