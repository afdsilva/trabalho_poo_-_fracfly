#ifndef FundoInteiro_H
#define FundoInteiro_H

#include "FundoParcial.hpp"

class FundoInteiro{	
	
	
	SDL_Surface *screen;
	SDL_Event event;
	

	
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	
	unsigned short int epoch_last, epoch_current, frame_last,PauseFrame;
	unsigned short int ShowAxis, ShowGrid, ShowDot, AnimateK, MouseMode;
	
	double MaxRe, MinIm, fps, Zoom, CentreIm, CentreRe, AimIm, AimRe, ZoomStep, AimStep;
	double KStep;
	double AnimateN, AnimateReStep, AnimateImStep;

	
	int i, inc_x, inc_y, rc, frame, id, tmp;
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
