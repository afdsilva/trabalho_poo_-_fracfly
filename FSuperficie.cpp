#include "FSuperficie.h"
#include <iostream>
using namespace std;

FSuperficie::FSuperficie() {
}
 
SDL_Surface * FSuperficie::NoCarregar(char * arquivo) {
	SDL_Surface * retorno = NULL;

	try {
		SDL_Surface * _temp = NULL;
		if ((_temp = IMG_Load(arquivo)) == NULL)
			throw 1;
		retorno = SDL_DisplayFormatAlpha(_temp);
		SDL_FreeSurface(_temp);
	} catch(int e) {
		string msgErro = "FSuperficie::NoCarregar ";
		switch(e) {
			case 1:
				msgErro+= "Não foi possivel carregar imagem";
				break;
		}
		debug(msgErro);
	}

    return retorno;
}

bool FSuperficie::NoDesenhar(SDL_Surface * Surf_Dest, SDL_Surface * Surf_Ori, int X, int Y) {
    if(Surf_Dest == NULL || Surf_Ori == NULL) {
        return false;
    }

    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_BlitSurface(Surf_Ori, NULL, Surf_Dest, &DestR);
 
    return true;
}

bool FSuperficie::NoDesenhar(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Ori, int X, int Y, int X2, int Y2, int W, int H) {
    if(Surf_Dest == NULL || Surf_Ori == NULL) {
        return false;
    }
 
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_Rect OriR;
 
    OriR.x = X2;
    OriR.y = Y2;
    OriR.w = W;
    OriR.h = H;
 
    SDL_BlitSurface(Surf_Ori, &OriR, Surf_Dest, &DestR);
 
    return true;
}

bool FSuperficie::Transparencia(SDL_Surface * Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }
 
    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));
 
    return true;
}
