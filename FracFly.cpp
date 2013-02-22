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
	//cout << FEntidade_Tiro::ListaTiros.size() << endl;
	while(rodando) {
		//checa por eventos e passa um por um para o NoEvento
		while(SDL_PollEvent(&evento)) {
			NoEvento(&evento);
		}
		
		//move dados ou nao
		NoLaco();
		
		//Renderiza o jogo
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

