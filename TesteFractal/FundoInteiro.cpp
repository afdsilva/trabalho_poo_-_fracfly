#include "FundoInteiro.hpp"

unsigned short FundoParcial::MaxIterations=500;

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

vector<FundoParcial*> FundoInteiro:: listaParciais;

	
int FundoParcial:: exit=0;



FundoInteiro :: FundoInteiro(){
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

		//~ Zoom =979.847712;
		Zoom =3.0;
		ZoomStep = 0.9;
		AimStep = 0.0001;

		AimRe = -0.5;
		AnimateN = 0;			

		
		 
		SCREEN_HEIGHT = 768;	
		SCREEN_WIDTH = 1024;	
		
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);				// Sets up OpenGL double buffering
		 
		i=0;
		
		inc_y = (int)floor((SCREEN_HEIGHT/NUM_THREADS));
		
		y = x =0;
		
		screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
		
		//~ SDL_WM_SetCaption("Fractal", "puzzle.png" ); // Barra te titulo
		
		//~ SDL_WM_GrabInput(SDL_GRAB_ON);  // Mouse só dentro da tela.
		
	}
	void FundoInteiro ::  resumeThreads(){
		for(int i=0; i < NUM_THREADS ; i++){
			FundoInteiro:: listaParciais[i]->setRunning(true) ;
		}
	}
	 
	bool FundoInteiro ::  todasThreadsCalcularam() {
		for(int i=0; i< NUM_THREADS ; i++){
			if(FundoInteiro:: listaParciais[i]->getRunning() == true){
				return false;
			}
		}
		return true;
	}
	
	void FundoInteiro:: NoInic() {
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
			if (CentreRe != AimRe) CentreRe = 
				(AimRe+CentreRe)/2;
			if (CentreIm != AimIm) 
				CentreIm = (AimIm+CentreIm)/2;

			if ( (CentreRe/AimRe) < 0.01 ) 
				CentreRe = AimRe;
			if ( (CentreIm/AimIm) < 0.01 ) 
				CentreIm = AimIm;

			FundoParcial::MinRe = CentreRe - (Zoom/2.0); 
			MaxRe = CentreRe + (Zoom/2.0);
			MinIm = CentreIm + (((MaxRe-FundoParcial::MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);
			FundoParcial::MaxIm = CentreIm - (((MaxRe-FundoParcial::MinRe)*SCREEN_HEIGHT/SCREEN_WIDTH)/2);  //

			FundoParcial::ReFactor = (MaxRe-FundoParcial::MinRe)/(SCREEN_WIDTH-1);	
			FundoParcial::ImFactor = (FundoParcial::MaxIm-MinIm)/(SCREEN_HEIGHT-1);

			if (AnimateK) // Animacao 
			{
				double r = (1.0/1.0)*cos(6.0*AnimateN);
							
				FundoParcial::KRe = r*cos(AnimateN);
				FundoParcial::KIm = r*sin(AnimateN);
				
				
				AnimateN += 0.0002;
			}

			if (FundoParcial::MaxIterations <= 0) FundoParcial::MaxIterations = 10;

			if(todasThreadsCalcularam()){
				SDL_Flip(screen);
				
			}
			
			
			//~ contador++;
			//~ if(contador == 1000){ // ALGO MUDA AQUI MAS é TIPO ISSo
				//~ Zoom = Zoom*ZoomStep;
				//~ contador=0;
				//~ }
				
			Evento();
			}
			
	}
	
	void FundoInteiro :: Evento(){

		while(SDL_PollEvent(&event)) {
			
			Uint8 mousestate;
			mousestate = SDL_GetMouseState(NULL, NULL);

			if (event.type == SDL_QUIT ) FundoParcial::exit = 1;
			
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_SPACE) {
					AimRe = -0.5; // Centro x do mouse
					AimIm = 0.0; // centro y do mouse
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
				
				if (event.key.keysym.sym == SDLK_a) AnimateK = !AnimateK;

				//~ if (event.key.keysym.sym == SDLK_w) contador=contador+100;

			}

			if(mousestate & SDL_BUTTON(1) && MouseMode == 1){
    			FundoParcial::KIm =FundoParcial::MaxIm - event.button.y*FundoParcial::ImFactor;
				FundoParcial::KRe = FundoParcial::MinRe + event.button.x*FundoParcial::ReFactor;
			} 

			if (event.type == SDL_MOUSEBUTTONDOWN && MouseMode == 0 ) {
				resumeThreads(); 
				AimIm = FundoParcial::MaxIm - event.button.y*FundoParcial::ImFactor; // calcula um novo centro 
				AimRe = FundoParcial::MinRe + event.button.x*FundoParcial::ReFactor;  // calcula um novo centro 

				if (event.button.button == SDL_BUTTON_LEFT) Zoom = Zoom*ZoomStep;
				if (event.button.button == SDL_BUTTON_RIGHT) {
					
					Zoom = Zoom*1.2;
					printf( "%f \n",Zoom);
					}
			}
			
		
		}
		
		
	}
