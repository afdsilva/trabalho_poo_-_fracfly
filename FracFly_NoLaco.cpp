#include "FracFly.h"

#define FPS 60
Uint16 waittime = 1000.0f/FPS;
Uint16 framestarttime = 0;
Sint16 delaytime;

/**
 * Metodo que controla o laço (loop) do jogo, todas ações que requererem modificar dados das entidades
 * é feita nesse metodo;
 **/
void FracFly::NoLaco() {
	//chama cada entidade na lista de entidades, utilizando o metodo apripriado para as entidades no FEntidade.cpp
	for(int i = 0;i < (int) FEntidade::listaEntidades.size();i++) {
		//como a lista de entidades é um vetor, esse vetor pode ter buracos
		//o if abaixo impede que seja feitas chamadas desnecessarias quando nao existe mais o objeto no vetor
		if(!FEntidade::listaEntidades[i]) continue;
		//reduz o tamanho do vetor se verifica que o ultimo estado da lista é morto, ajuda (espero) na limpeza de objetos
		if (FEntidade::listaEntidades[i]->morto && (int) FEntidade::listaEntidades.size() == i+1) {
			FEntidade::listaEntidades.pop_back();
		}
		//chama o metodo NoLaco() do objeto, definido no FEntidade.cpp
		FEntidade::listaEntidades[i]->NoLaco();
	}
	/** Tiros desabilitados ** /
	for(int i = 0;i < (int) FEntidade_Tiro::ListaTiros.size();i++) {
		if(!FEntidade_Tiro::ListaTiros[i]) continue;
		//verifica se o estado esta ativo, mudar pra flag morto, 
		if (!FEntidade_Tiro::ListaTiros[i]->Ativo && (int) FEntidade_Tiro::ListaTiros.size() == i+1 ) //gambimodeon
			FEntidade_Tiro::ListaTiros.pop_back();
		FEntidade_Tiro::ListaTiros[i]->NoLaco();
	}
	**/
	//Reduz o consumo de CPU adicionando um delay
	delaytime = waittime - (SDL_GetTicks() - framestarttime);
    if(delaytime > 0)
        SDL_Delay((Uint16)delaytime);
    framestarttime = SDL_GetTicks();
}
