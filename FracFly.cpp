/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
 *
 * Classe Principal do jogo
 **/

#include "FracFly.h"

/**
 * Construtor Da classe principal
 **/
FracFly::FracFly() {
	planoExibicao = NULL;
	rodando = true;
}
/**
 * Classe de execução do programa
 **/
int FracFly::naExec() {
	//Verifica se todas inicializacoes foram feitas corretamente
	if (NoInic() == false) {
		return -1;
	}
	
	SDL_Event evento;
	
	//Permanece no loop infinito enquanto nao for especificado para sair
	while(rodando) {
		//Checa os eventos e faz o tratamento no metodo NoEvento
		while(SDL_PollEvent(&evento)) {
			NoEvento(&evento);
		}
		
		//Controle de dados
		NoLaco();
		
		//Renderiza os graficos
		NaRenderizacao();
	}
	
	//na saida faz a limpeza de lixo
	NaLimpeza();
	return 0;
}

int main(int argc, char* argv[]) {
	FracFly oJogo;
	
	return oJogo.naExec();
}

