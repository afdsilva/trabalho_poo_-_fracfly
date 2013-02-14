#ifndef _FSUPERFICIE_H_
    #define _FSUPERFICIE_H_
 
#include <SDL/SDL.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class FSuperficie {
    public:
        FSuperficie();
 
    public:
        static SDL_Surface * NoCarregar(char * Arquivo);
        
        static bool NoDesenhar(SDL_Surface * Surf_Dest, SDL_Surface * Surf_Ori, int X, int Y);
        static bool NoDesenhar(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Ori, int X, int Y, int X2, int Y2, int W, int H);
        static bool Transparencia(SDL_Surface* Surf_Dest, int R, int G, int B);
};
 
#endif
