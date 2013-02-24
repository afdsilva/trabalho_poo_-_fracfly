#ifndef FundoInteiro_H
#define FundoInteiro_H

#include "FundoParcial.hpp"

class FundoInteiro{	
	SDL_Surface *screen;
	SDL_Event event;
	static std::vector<FundoParcial*> listaParciais;

	
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
	FundoInteiro();
	void NoInic();
	void ExecutarFractal();
	void Evento();
	
	bool todasThreadsCalcularam();
	void resumeThreads();
};
#endif
