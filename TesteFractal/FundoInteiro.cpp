#include "FundoInteiro.hpp"

unsigned short FundoParcial::MaxIterations=50;

unsigned short int FundoParcial:: FracType = 1;
unsigned short int FundoParcial:: ColR = rand()%256;
unsigned short int FundoParcial:: ColG = rand()%256;
unsigned short int FundoParcial:: ColB = rand()%256;

double FundoParcial:: KIm = 0.288;
double FundoParcial:: KRe = 0.353;
double FundoParcial:: MinRe = 0; 
double FundoParcial:: MaxIm = 0; 
double FundoParcial:: ReFactor = 0; 
double FundoParcial:: ImFactor = 0; 

unsigned FundoParcial :: SCREEN_WIDTH=1024;

SDL_Surface * FundoParcial:: screen; 


vector <FundoParcial*> FundoInteiro:: listaParciais;

	
int FundoParcial:: exit=0;



FundoInteiro :: FundoInteiro(){
		ShowAxis =  0;
		ShowGrid = 0;
		ShowDot = 0;
		stepDirection=9;
		AnimateK = 0;
		
		
		KStep =  0.02;

		MaxRe = 0; 
		MinIm = 0; 
	
		CentreIm = 0;
		CentreRe = 0;
		AimIm = 0;

		//~ Zoom =979.847712;
		Zoom =3.0;
		ZoomStep = 0.99;
		AimStep = 0.0001;

		AimRe = -0.5;
		AnimateN = 1;			

		
		 
		SCREEN_HEIGHT = 768;	
		SCREEN_WIDTH = 1024;	
		
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);				// Sets up OpenGL double buffering
		 
		i=0;
		
		inc_y = (int)floor((SCREEN_HEIGHT/NUM_THREADS));
		
		y = x =0;
		
		screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
		
		
	}
	
	void joinThreads(){
		for(int i = 0; i < NUM_THREADS; i++) {
			 FundoInteiro:: listaParciais[i]->Join();
		}
		 FundoInteiro:: listaParciais.clear();
	}
	
	void FundoInteiro:: startThreads() {
		FundoParcial:: screen = screen;
		for(int i = 0; i < NUM_THREADS; i++) {
				FundoParcial * tFrac = new FundoParcial();
				tFrac->setStart_y(i*inc_y);
				tFrac->setStop_y((i+1)*inc_y);
				tFrac->Start();
				 FundoInteiro:: listaParciais.push_back(tFrac);

			}
		}
	
		void FundoInteiro :: ExecutarFractal(){
		
		while(!FundoParcial::exit){
			
			Evento() ;
							
			calculoParametros();
			
			startThreads();
			
			joinThreads();
			
			SDL_Flip(screen);
			
			
		}		
	}
			

	
	bool FundoInteiro :: Evento(){
		bool retorno=false;
		while(SDL_PollEvent(&event)) {
				
			
			if (event.key.keysym.sym == SDLK_k) AnimateK = !AnimateK;

			if (event.type == SDL_QUIT ) FundoParcial::exit = 1;
			
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_SPACE) {
					AimRe = -0.5;
					AimIm = 0.0; 
					FundoParcial::MaxIterations = 30;
					Zoom = 3.0;
				}

				if (event.key.keysym.sym == SDLK_q) FundoParcial::exit = 1;
				if (event.key.keysym.sym == SDLK_ESCAPE) FundoParcial::exit = 1;

				if (event.key.keysym.sym == SDLK_KP_PLUS) FundoParcial::MaxIterations += 10;
				if (event.key.keysym.sym == SDLK_KP_MINUS) FundoParcial::MaxIterations -= 10;
				
				
				if (event.key.keysym.sym == SDLK_1) 
					FundoParcial::FracType = 1;
				if (event.key.keysym.sym == SDLK_2) 
					FundoParcial::FracType = 2;
				if (event.key.keysym.sym == SDLK_3) 
					FundoParcial::FracType = 3;

				if (event.key.keysym.sym == SDLK_r) {
					FundoParcial::ColR = rand() % 256;
					FundoParcial::ColG = rand() % 256;
					FundoParcial::ColB = rand() % 256;
				}	
				
				if (event.key.keysym.sym == SDLK_s) {
					AimIm -= stepDirection * FundoParcial::ImFactor;
				}
				if (event.key.keysym.sym == SDLK_w) {
					AimIm += stepDirection * FundoParcial::ImFactor;
				}
				if (event.key.keysym.sym == SDLK_a) {
					AimRe -= stepDirection * FundoParcial::ReFactor;
				}
				if (event.key.keysym.sym == SDLK_d) {
					AimRe += stepDirection* FundoParcial::ReFactor;
				}
				
				
			}
			
			retorno = true;
		}
		
		return retorno;
		
	}
	
	
	void FundoInteiro :: calculoParametros (){
		Zoom = Zoom*ZoomStep;
		FundoParcial::MinRe = CentreRe - (Zoom/2.0); 
		MaxRe = CentreRe + (Zoom/2.0);
		MinIm = CentreIm + (((MaxRe-FundoParcial::MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);
		FundoParcial::MaxIm = CentreIm - (((MaxRe-FundoParcial::MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);  //

		FundoParcial::ReFactor = (MaxRe-FundoParcial::MinRe)/(SCREEN_WIDTH-1);	
		FundoParcial::ImFactor = (FundoParcial::MaxIm-MinIm)/(SCREEN_HEIGHT-1);
		
		if (CentreRe != AimRe) 
			CentreRe = (AimRe+CentreRe)/2;
		if (CentreIm != AimIm) 
			CentreIm = (AimIm+CentreIm)/2;

		if ( (CentreRe/AimRe) < 0.01 ) 
			CentreRe = AimRe;
		if ( (CentreIm/AimIm) < 0.01 ) 
			CentreIm = AimIm;


		if (AnimateK) // Animacao 
		{
			double r = (1.0/1.0)*cos(6.0*AnimateN);
						
			FundoParcial::KRe = r*cos(AnimateN);
			FundoParcial::KIm = r*sin(AnimateN);
			
			
			AnimateN += 0.0002;
		}

		if (FundoParcial::MaxIterations <= 0) FundoParcial::MaxIterations = 10;
		
	}
