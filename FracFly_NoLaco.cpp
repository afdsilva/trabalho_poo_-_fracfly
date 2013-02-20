#include "FracFly.h"

#define FPS 60
Uint16 waittime = 1000.0f/FPS;
Uint16 framestarttime = 0;
Sint16 delaytime;

void FracFly::NoLaco() {
	// CUIDANDO DO FUNDO
		//~ if (CentreRe != AimRe) CentreRe = (AimRe+CentreRe)/2;
		//~ if (CentreIm != AimIm) CentreIm = (AimIm+CentreIm)/2;
//~ 
		//~ if ( (CentreRe/AimRe) < 0.01 ) CentreRe = AimRe;
		//~ if ( (CentreIm/AimIm) < 0.01 ) CentreIm = AimIm;
//~ 
		//~ MinRe = CentreRe - (Zoom/2.0); 
		//~ MaxRe = CentreRe + (Zoom/2.0);
		//~ MinIm = CentreIm + (((MaxRe-MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);
		//~ MaxIm = CentreIm - (((MaxRe-MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);  
//~ 
		//~ ReFactor = (MaxRe-MinRe)/(SCREEN_WIDTH-1);	
		//~ ImFactor = (MaxIm-MinIm)/(SCREEN_HEIGHT-1);
//~ 
		//~ if (AnimateK) 
		//~ {
			//~ double r = (1.0/1.0)*cos(6.0*AnimateN);
						//~ 
			//~ KRe = r*cos(AnimateN);
			//~ KIm = r*sin(AnimateN);
			//~ 
			//~ AnimateN += 0.0002;
		//~ }
//~ 
		//~ if (MaxIterations <= 0) MaxIterations = 10;
//~ 
		//~ if (FracType == 1 && ShowDot) plot(screen, KRe, KIm);
//~ 
		//~ if (ShowAxis) {
			//~ for (y = -2.0; y <= 2.0; y += 0.003 ) plot(screen, 0, y);
			//~ for (x = -2.0; x <= 2.0; x += 0.003 ) plot(screen, x, 0);
		//~ }
//~ 
		//~ if (ShowGrid) {
			//~ for (y = -2.0; y <= 2.0; y += 0.25 ) {
				//~ for (x = -2.0; x <= 2.0; x += 0.25 ) {
					//~ plot(screen, x, y);
				//~ }
			//~ }
		//~ }
		
	// FIM FUNDO
	
	
	
	for(int i = 0;i < (int) FEntidade::ListaEntidades.size();i++) {
		if(!FEntidade::ListaEntidades[i]) continue;
		FEntidade::ListaEntidades[i]->NoLaco();
	}
	//cout << "Tam: " << (int) FEntidade_Tiro::ListaTiros.size() << endl;
	for(int i = 0;i < (int) FEntidade_Tiro::ListaTiros.size();i++) {
		if(!FEntidade_Tiro::ListaTiros[i]) continue;
		if (!FEntidade_Tiro::ListaTiros[i]->Ativo && (int) FEntidade_Tiro::ListaTiros.size() == i+1 ) //gambimodeon
			FEntidade_Tiro::ListaTiros.pop_back();
		FEntidade_Tiro::ListaTiros[i]->NoLaco();
	}
	//Reduz o consumo de CPU adicionando um delay
	delaytime = waittime - (SDL_GetTicks() - framestarttime);
    if(delaytime > 0)
        SDL_Delay((Uint16)delaytime);
    framestarttime = SDL_GetTicks();
}
