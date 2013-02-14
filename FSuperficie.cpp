#include "FSuperficie.h"

FSuperficie::FSuperficie() {
}
 
SDL_Surface * FSuperficie::NoCarregar(char * Arquivo) {
    
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Retorno = NULL;

    if((Surf_Temp = SDL_LoadBMP(Arquivo)) == NULL) {
        return NULL;
    }
 
    Surf_Retorno = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
 
    return Surf_Retorno;
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
