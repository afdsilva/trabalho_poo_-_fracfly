#ifndef FundoInteiro_H
#define FundoInteiro_H

#include "FundoParcial.hpp"

class FundoInteiro{	
	
	
	SDL_Surface *screen;
	SDL_Event event;
	

	
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	
	unsigned short int epoch_last, epoch_current, frame_last,PauseFrame;
	unsigned short int ShowAxis, ShowGrid, ShowDot, AnimateK;
	
	double MaxRe, MinIm, Zoom, CentreIm, CentreRe, AimIm, AimRe, ZoomStep, AimStep;
	double KStep,stepDirection;
	double AnimateN, AnimateReStep, AnimateImStep;

	
	int i, inc_x, inc_y;
	double y, x;

public:
	static std::vector<FundoParcial*> listaParciais;

public:
	FundoInteiro();
	void startThreads();
	void ExecutarFractal();
	bool Evento();
	
	void calculoParametros();
	
};
#endif
