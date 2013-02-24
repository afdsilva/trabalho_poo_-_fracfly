#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "Threads.hpp"



using namespace std;

struct process_args {
	SDL_Surface 	*screen;
	int		start;
	int		stop;
	int		r;
	int		g;
	int		b;
	int		id;
};

int contador=0;


class FundoFractal {

	static double MinRe, MaxIm, ReFactor, ImFactor;
	
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	
	 unsigned short int epoch_last, epoch_current, frame_last,PauseFrame;
	 static unsigned short int FracType,ColR, ColG, ColB, ThreadHL;
	 unsigned short int ShowAxis, ShowGrid, ShowDot, AnimateK, MouseMode;
	
	 double MaxRe, MinIm, fps, Zoom, CentreIm, CentreRe, AimIm, AimRe, ZoomStep, AimStep;
	 static double KRe, KIm;
	 double KStep;
	 double AnimateN, AnimateReStep, AnimateImStep;
	 static unsigned short MaxIterations;
	 static int exit;
	//~ static unsigned short int fthreads[NUM_THREADS];

	static struct process_args process_args_array[NUM_THREADS];	
	

private:
	int				i, inc, rc, frame, id, tmp;
	double			y, x;
	SDL_Surface		*screen;
	SDL_Event		event;

	
public:
	
	void run(){
		
	}
	
	FundoFractal(){
				
				
		ShowAxis =  0;
		ShowGrid = 0;
		ShowDot = 0;

		AnimateK = 0;
		MouseMode = 0;
		epoch_current = 0;
		frame_last = 0;
		PauseFrame = 0;
		epoch_last = (int)time(NULL);


		KStep =  0.02;

		MaxRe = 0; 
		MinIm = 0; 
		fps = 0;
		CentreIm = 0;
		CentreRe = 0;
		AimIm = 0;

		Zoom =979.847712;
		ZoomStep = 0.9;
		AimStep = 0.0001;

		AimRe = -0.5;
		AnimateN = 0;			

		
				
		
		const SDL_VideoInfo * videoInfo;	
	
		videoInfo = SDL_GetVideoInfo();	
		
		SCREEN_HEIGHT = 480;	
		SCREEN_WIDTH = 720;	
		//~ SCREEN_HEIGHT = videoInfo->current_h;	
		//~ SCREEN_WIDTH = videoInfo->current_w;	
		
		
		int videoFlags;			
		videoFlags  = SDL_OPENGL;									// Enable OpenGL in SDL
		videoFlags |= SDL_GL_DOUBLEBUFFER;							// Enable double buffering
		videoFlags |= SDL_HWPALETTE;     							// Store the palette in hardware
		videoFlags |= SDL_RESIZABLE;      							// Enable window resizing
		videoFlags |= SDL_FULLSCREEN;      							// Enable full screen mode

		if (videoInfo->hw_available)								// Check to see if surfaces can be stored in memory
			videoFlags |= SDL_HWSURFACE;
		else
			videoFlags |= SDL_SWSURFACE;

		if (videoInfo->blit_hw)										// Checks if hardware blits can be done
			videoFlags |= SDL_HWACCEL;

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);				// Sets up OpenGL double buffering
		 
		
		i = rc = frame = id = tmp =0;
		inc = (int)floor((SCREEN_HEIGHT/NUM_THREADS));
		y = x =0;
		screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
		
		SDL_WM_SetCaption("Fractal", "puzzle.png" ); // Barra te titulo
		
		//~ SDL_WM_GrabInput(SDL_GRAB_ON);  // Mouse só dentro da tela.
		
	}
	
	
	void startTredes(){
		cout << "criando Treds" << endl;
		
		pthread_t threads[NUM_THREADS];
		for (int i = 0; i < NUM_THREADS; ++i){
			process_args_array[i].id = i; 
			process_args_array[i].screen = screen; // copia do fundo
			process_args_array[i].start = i*inc; // Altura inicial SCREEN
			process_args_array[i].stop = (i+1)*inc; // Altura final SCREEN
			process_args_array[i].r = rand() % 256; // cor de cada Tred para bonito
			process_args_array[i].g = rand() % 256;
			process_args_array[i].b = rand() % 256;
			rc = pthread_create(&threads[i], NULL, process, (void *) &process_args_array[i] );
		}
	}
	
	static int setpixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b) {
		
		Uint32 *pixmem, colour;

		colour = SDL_MapRGB( screen->format, r, g, b); // escolhe o melhor RGB para a cor :)
		
		pixmem = (Uint32*)screen->pixels + (y*screen->w) + x; // pega o y e x referente ao pixel na tela
		 //pega a largura, multiplica por altura(y) e tem o pixel y como se fosse o calculo de malloc para matriz
						// (i*col)+j
		*pixmem = colour; // seta as cores que ele pegou na anterior e seta no pixel que ele pegou acima.
		
		return 0;
	}

	
	static void *process(void *threadarg) {

		struct process_args *thargs = (struct process_args *) threadarg;

		unsigned start = thargs->start;
		unsigned stop = thargs->stop;

		int			isInside;
		unsigned	y,x,n,r,g,b;
		double tmp, c_im, c_re, Z_re, Z_im, Z_re2, Z_im2;

		SDL_Surface *screen = thargs->screen;

		r = thargs->r;
		g = thargs->g;
		b = thargs->b;

// MaxIm ImFactor Unicos usados que estão fora do processo 
// MinRe ReFactor

		while(!exit) {
			for (y = start; y < stop; ++y) {
				c_im = MaxIm - y*ImFactor;

				for (x = 0; x < (unsigned)SCREEN_WIDTH; ++x) {
					c_re = MinRe + x*ReFactor;
					isInside = 1;

					Z_re = c_re;
					Z_im = c_im;

					for(n = 0; n < MaxIterations; ++n) { //macInteration muda se aperto "+" ou "-" COMPLEXIDADE(mains iteracoes)
					
						Z_re2 = Z_re*Z_re; 
						Z_im2 = Z_im*Z_im;

						if(Z_re2 + Z_im2 > 4) {
							isInside = 0;
							tmp = (double) (n*9)/(double)MaxIterations; // Mudando o temp se muda as cores tendo uma ideia bem legal
				// Isso occorre porque tem uma gama MAIOR de rgb e logo se é mais perto de 255 então fica com mais cores vivas
							setpixel( thargs->screen, x, y, (Uint8)(tmp*ColR), (Uint8)(tmp*ColG), (Uint8)(tmp*ColB));
							break;
						}

						switch(FracType) {
						case 1:
							Z_im = 2*Z_re*Z_im + c_im;
							Z_re = Z_re2 - Z_im2 + c_re;
							break;
						case 2:
							Z_im = 2*Z_re*Z_im + KIm;
							Z_re = Z_re2 - Z_im2 + KRe;
							break;
						case 3:
							Z_im = 2*sqrt(Z_re2)*sqrt(Z_im2) + c_im;
							Z_re = Z_re2 - Z_im2 + c_re;
							break;
						}
					}
					if (isInside) 
						setpixel( thargs->screen, x, y, 25, 255, 150); 
						// Muda o centro onde tudo é uma cor padrão aqui fica legal de mudar algo. 
				}
			}
		}		
		pthread_exit(0);

		return 0;
	}
	
	void ExecutarFractal(){
	startTredes();
	while(!exit){
		if (CentreRe != AimRe) CentreRe = 
			(AimRe+CentreRe)/2;
		if (CentreIm != AimIm) 
			CentreIm = (AimIm+CentreIm)/2;

		if ( (CentreRe/AimRe) < 0.01 ) 
			CentreRe = AimRe;
		if ( (CentreIm/AimIm) < 0.01 ) 
			CentreIm = AimIm;

		MinRe = CentreRe - (Zoom/2.0); 
		MaxRe = CentreRe + (Zoom/2.0);
		MinIm = CentreIm + (((MaxRe-MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);
		MaxIm = CentreIm - (((MaxRe-MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);  //

		ReFactor = (MaxRe-MinRe)/(SCREEN_WIDTH-1);	
		ImFactor = (MaxIm-MinIm)/(SCREEN_HEIGHT-1);

		if (AnimateK) // Animacao 
		{
			double r = (1.0/1.0)*cos(6.0*AnimateN);
						
			KRe = r*cos(AnimateN);
			KIm = r*sin(AnimateN);
			
			
			AnimateN += 0.0002;
		}

		if (MaxIterations <= 0) MaxIterations = 10;

					
		SDL_Flip(screen);
		
		
		contador++;
		if(contador == 1000){ // ALGO MUDA AQUI MAS é TIPO ISSo
			Zoom = Zoom*ZoomStep;
			contador=0;
			}
			
		Evento();
		}
	}
	
	void Evento(){

		while(SDL_PollEvent(&event)) {
			Uint8 mousestate;
			mousestate = SDL_GetMouseState(NULL, NULL);

			if (event.type == SDL_QUIT ) exit = 1;
			
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_SPACE) {
					AimRe = -0.5; // Centro x do mouse
					AimIm = 0.0; // centro y do mouse
					MaxIterations = 30;
					Zoom = 3.0;
				}

				if (event.key.keysym.sym == SDLK_q) exit = 1;
				if (event.key.keysym.sym == SDLK_ESCAPE) exit = 1;

				if (event.key.keysym.sym == SDLK_KP_PLUS) MaxIterations += 10;
				if (event.key.keysym.sym == SDLK_KP_MINUS) MaxIterations -= 10;
				
				if (event.key.keysym.sym == SDLK_KP4) KRe -= KStep;
				if (event.key.keysym.sym == SDLK_KP6) KRe += KStep;
				if (event.key.keysym.sym == SDLK_KP8) KIm -= KStep;
				if (event.key.keysym.sym == SDLK_KP2) KIm += KStep;

				if (event.key.keysym.sym == SDLK_1) 
					FracType = 1;
				if (event.key.keysym.sym == SDLK_2) 
					FracType = 2;
				if (event.key.keysym.sym == SDLK_3) 
					FracType = 3;

				if (event.key.keysym.sym == SDLK_r) {
					ColR = rand() % 256;
					ColG = rand() % 256;
					ColB = rand() % 256;
				}

				//~ if (event.key.keysym.sym == SDLK_a) AnimateK = !AnimateK;
				if (event.key.keysym.sym == SDLK_x) ShowAxis = !ShowAxis;
				
				//~ AimIm = MaxIm - event.button.y*ImFactor; // calcula um novo centro 
				//~ AimRe = MinRe + event.button.x*ReFactor;  // calcula um novo centro 
				
				//~ if (event.key.keysym.sym == SDLK_a) AimIm = AimIm;
				if (event.key.keysym.sym == SDLK_w) contador=contador+100;
				//~ if (event.key.keysym.sym == SDLK_d) AimRe = !ShowAxis;
				
				
				if (event.key.keysym.sym == SDLK_g) ShowGrid = !ShowGrid;
				if (event.key.keysym.sym == SDLK_d) ShowDot = !ShowDot;

				if (event.key.keysym.sym == SDLK_m) {
					MouseMode += 1;
					if (MouseMode > 1) MouseMode = 0;
				}

				if (event.key.keysym.sym == SDLK_t) {
					ThreadHL += 1;
					if (ThreadHL > 1) ThreadHL = 0;
				}

			}

			if(mousestate & SDL_BUTTON(1) && MouseMode == 1){
    			KIm = MaxIm - event.button.y*ImFactor;
				KRe = MinRe + event.button.x*ReFactor;
			} 

			if (event.type == SDL_MOUSEBUTTONDOWN && MouseMode == 0 ) { 
				AimIm = MaxIm - event.button.y*ImFactor; // calcula um novo centro 
				AimRe = MinRe + event.button.x*ReFactor;  // calcula um novo centro 

				if (event.button.button == SDL_BUTTON_LEFT) Zoom = Zoom*ZoomStep;
				if (event.button.button == SDL_BUTTON_RIGHT) {
					
					Zoom = Zoom*1.2;
					printf( "%f \n",Zoom);
					}
			}
			
		
		}
		
		
	}
	
};
