#include "FSuperficie.h"

FSuperficie::FSuperficie() {
}
 
SDL_Surface * FSuperficie::NoCarregar(char * Arquivo) {
    
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Retorno = NULL;

	printf("Arquivo: %s\n", Arquivo);
	/**
	char * ext;
	strtok(Arquivo,".");
	ext = strtok(NULL,".");
	printf("ext: %s", ext);
	**/
	/**
	string bmp;
	string png;
	string gif;
	printf("%s: %d\n",bmp,bmp);
	printf("%s: %d\n",png,png);
	printf("%s: %d\n",gif,gif);
	**/
	//switch atoi(ext)

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
