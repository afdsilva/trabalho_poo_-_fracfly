#include "FracFly.h"
/**
 * Metodo de Inicializacao de variaveis, configurações e de carregar recursos
 **/
bool FracFly::NoInic() {
	//inicializa todos recursos do SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("NoInic: Não foi possivel Inicializar SDL\n");
		return false;
	}
	//inicializa um plano de exibicao, todas outras superficies são criadas em cima dela
	if ((planoExibicao = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		printf("NoInic: Não foi possivel criar Plano Exibição\n");
		return false;
	}
	
	/** Areas serao carregas no estado correto (futura implementacao) **/
	//carrega Area (areas sao conjuntos de mapas)
	char area[] = "maps/1.area";
	if(FArea::controleArea.NoCarregar(area) == false) {
		printf("NoInic: Não foi possivel carregar Area: %s\n", area);
		return false;
	}
	 
	//SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
	/* Fim area */

	/**
	 * Personagem devera ser carregado no estado de jogo
	char Arquivo[] = "res/yoshi.png";
	char Arquivo2[] = "res/yoshi.png";
	

	if((Arma1.NoCarregar(Arquivo, 64, 64, 8)) == false) {
		printf("NoInic: Não foi possivel carregar: %s\n", Arquivo);
        return false;
    }
    
	//~ if((fundoFractal.NoCarregar()) == false) {
		//~ printf("NoInic: Não foi possivel carregar: %s\n", Arquivo);
        //~ return false;
    //~ }
    
	if((Arma2.NoCarregar(Arquivo2, 64, 64, 8)) == false) {
		printf("NoInic: Não foi possivel carregar: %s\n", Arquivo2);
        return false;
    }
    
    //Arma1.Surf_Entidade = FSuperficie::Rotacionar(Arma1.Surf_Entidade,0.5,1,0);
	Arma1.X = 0;
	Arma2.X = 640 - (Arma2.Width);
	Arma1.Y = 480 - (Arma1.Height);
	Arma2.Y = 480 - (Arma2.Height);

	FEntidade::ListaEntidades.push_back(&Arma1);
	FEntidade::ListaEntidades.push_back(&Arma2);
	**/
	char naveArquivo[] = "res/yoshi.png";
	if (nave.NoCarregar(naveArquivo,64, 64, 8) == false) {
		return false;
	}
	nave.flags = ENTIDADE_FLAG_ESPACO | ENTIDADE_FLAG_SOMENTEMAPA;
	nave.x =  (WWIDTH / 2) - (nave.width / 2);
	nave.y =  (WHEIGHT / 2) - (nave.height / 2);
	
	FEntidade::listaEntidades.push_back(&nave);
	FCamera::controleCamera.modoAlvo = MODO_ALVO_CENTRO;
	FCamera::controleCamera.SetAlvo(&nave.x, &nave.y);
	
	return true;
}
