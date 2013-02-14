#include "FracFly.h"

bool FracFly::NoInic() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	
	if ((Plano_Exibicao = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}
	
	char bg[] = "res/teste.bmp";
	if((Surf_bg = FSuperficie::NoCarregar(bg)) == NULL) {
        return false;
    }

	char Arquivo[] = "res/yoshi.bmp";
	if((Surf_Test = FSuperficie::NoCarregar(Arquivo)) == NULL) {
        return false;
    }
    FSuperficie::Transparencia(Surf_Test, 255, 0, 255);
    
    Anim_Yoshi.MaxFrames = 8;
    //Anim_Yoshi.Oscilacao = true;
	
	return true;
}
