#ifndef _FENTIDADE_ARMA_H
  #define _FENTIDADE_ARMA_H

#include "FEntidade.h"

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#define SCREEN_WIDTH 980
#define SCREEN_HEIGHT 540
#define NUM_THREADS 20

struct process_args {
	SDL_Surface 	*screen;
	int		start;
	int		stop;
	int		r;
	int		g;
	int		b;
	int		id;
};


#include "FEntidade.h"

srand((int)time(NULL));

class FundoFractal: public FEntidade {
	static unsigned short int epoch_last, epoch_current, frame_last, ColR, ColG, ColB,  PauseFrame;
	static unsigned short intFracType=1;
	static unsigned short int ShowAxis, ShowGrid, ShowDot, AnimateK, MouseMode, ThreadHL;
	static double MinRe, MaxRe, MinIm, MaxIm, ReFactor, ImFactor, fps, Zoom, CentreIm, CentreRe, AimIm, AimRe, ZoomStep, AimStep;
	static double KRe, KIm, KStep;
	static double AnimateN, AnimateReStep, AnimateImStep;
	static unsigned short MaxIterations = 500;
	static unsigned short int fthreads[NUM_THREADS];
	static struct process_args process_args_array[NUM_THREADS];	
	static pthread_t threads[NUM_THREADS];

private:
	int i, inc, rc, frame, exit, id, tmp;
	double y, x;
	
public:
	FundoFractal(){
		// OBSERVAR QUE TEM QUE INICIAR UNS STATICAMENTE
		
		inc = (int)floor((SCREEN_HEIGHT/NUM_THREADS));
		
		frame = 0;
		exit = 0;
		epoch_last = (int)time(NULL);
		frame_last = 0;
		MouseMode = 0;
		ThreadHL = 0;


		ShowGrid = 0;
		ShowAxis = 0;
		ShowDot = 0;
		AnimateK = 0;

		AnimateN = 0.0;

		ColR = rand() % 256;
		ColG = rand() % 256;
		ColB = rand() % 256;

		Zoom = 4.0;
		ZoomStep = 0.2;
		AimStep = 0.0001;

		KRe = 0.353;
		KIm = 0.288;
		KStep = 0.02;

		AimRe = -0.5;  //Usado quando o zoom acionado;;
		AimIm = 0.0;

		CentreRe = 0.0; 
		CentreIm = 0.0;

		id = 0;
		
		}
	
	int setpixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b);
	void plot(SDL_Surface *screen, double real, double imaginary);

	static void *process(void *threadarg);

	void startTredes(){
		for (i = 0; i < NUM_THREADS; ++i){
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
	
	int setpixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b) {

		Uint32		*pixmem, colour;

		y = y*screen->pitch/4;
		
		colour = SDL_MapRGB( screen->format, r, g, b);
		pixmem = (Uint32*)screen->pixels + y + x;
		*pixmem = colour;
		
		return 0;
	}

	void plot(SDL_Surface *screen, double real, double imaginary) {

		int x = (int)ceil((real - MinRe)/ReFactor);
		int y = (int)ceil((MaxIm - imaginary)/ImFactor);

		if (x >= 0 && x < SCREEN_WIDTH) {
			if (y >= 0 && y < SCREEN_HEIGHT) {
				setpixel(screen, x, y, 255, 255, 255);
			}
		}

	}
	
	NoCarregar();

	static void *process(void *threadarg) {

		struct process_args *thargs = (struct process_args *) threadarg;

		unsigned start = thargs->start;
		unsigned stop = thargs->stop;

		unsigned short int id = thargs->id;

		int			isInside;
		unsigned	y,x,n,r,g,b;
		double tmp, c_im, c_re, Z_re, Z_im, Z_re2, Z_im2;

		SDL_Surface *screen = thargs->screen;

		r = thargs->r;
		g = thargs->g;
		b = thargs->b;

		// infinite loop, kill thread when done.
		while(1) // deve ter uma variavel global que evento ou algo possa acessar e assim ACABAR com o processo.
		{
			printf("%d running...\n", id);

			for (y = start; y < stop; ++y) {
				c_im = MaxIm - y*ImFactor;

				for (x = 0; x < SCREEN_WIDTH; ++x) {
					c_re = MinRe + x*ReFactor;
					isInside = 1;

					Z_re = c_re;
					Z_im = c_im;

					for(n = 0; n < MaxIterations; ++n) { //macInteration muda se aperto "+" ou "-" COMPLEXIDADE(mains iteracoes)
					
						Z_re2 = Z_re*Z_re; 
						Z_im2 = Z_im*Z_im;

						if(Z_re2 + Z_im2 > 4) {
							isInside = 0;
							tmp = (double)n/(double)MaxIterations;  

							if (ThreadHL) {
								setpixel(screen, x, y, (Uint8)(tmp*r), (Uint8)(tmp*g), (Uint8)(tmp*b));
							} else {
								setpixel(screen, x, y, (Uint8)(tmp*ColR), (Uint8)(tmp*ColG), (Uint8)(tmp*ColB));//SEMPRE FAZ ESTE CALCULO 1;; caso aperte t ele muda
							}

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
					if (isInside) setpixel(screen, x, y, 25, 255, 150);

				}
			}

			fthreads[id] = 1;
		}

		pthread_exit(0);

		return 0;
	}
	
};

#endif
