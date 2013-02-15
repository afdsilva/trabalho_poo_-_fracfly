#include "FracFly.h"

/**
 * Construtor Da classe principal
 **/
FracFly::FracFly() {
	Surf_bg = NULL;
	Plano_Exibicao = NULL;
	Rodando = true;
}

/**
 * Classe de execução do programa
 **/
int FracFly::naExec() {
	//Verifica se todas inicializacoes foram feitas corretamente
	if (NoInic() == false) {
		return -1;
	}
	
	SDL_Event Evento;
	
	//Permanece no loop infinito enquanto nao for especificado para sair
	//cout << FEntidade_Tiro::ListaTiros.size() << endl;
	while(Rodando) {
		//checa por eventos e passa um por um para o NoEvento
		while(SDL_PollEvent(&Evento)) {
			NoEvento(&Evento);
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

