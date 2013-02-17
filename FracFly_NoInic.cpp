#include "FracFly.h"

bool FracFly::NoInic() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("NoInic: Não foi possivel Inicializar SDL\n");
		return false;
	}
	
	if ((Plano_Exibicao = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		printf("NoInic: Não foi possivel criar Plano Exibição\n");
		return false;
	}
	
	/**
	char bg[] = "res/teste.bmp";
	if ((Surf_bg = FSuperficie::NoCarregar(bg)) == NULL) {
		return false;
	}
	**/

	char Area[] = "maps/1.area";
	if(FArea::ControleArea.NoCarregar(Area) == false) {
		printf("NoInic: Não foi possivel carregar Area: %s\n", Area);
		return false;
	}
	 
	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

	char Arquivo[] = "res/yoshi.png";
	char Arquivo2[] = "res/yoshi.png";

	if((Arma1.NoCarregar(Arquivo, 64, 64, 8)) == false) {
		printf("NoInic: Não foi possivel carregar: %s\n", Arquivo);
        return false;
    }
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

	return true;
}
