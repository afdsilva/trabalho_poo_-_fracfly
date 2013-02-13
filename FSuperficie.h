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
};
 
#endif
