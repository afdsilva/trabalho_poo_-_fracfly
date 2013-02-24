#include "FundoInteiro.hpp"

int main(){
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) 
	{
		fprintf(stderr, "Unable to init SDL_INIT_VIDEO: %s\n", SDL_GetError());
		return 1;
	}
	
	FundoInteiro fundo;
	
	
	srand((int)time(NULL));
	
	fundo.ExecutarFractal();
	
	return 1;
}
