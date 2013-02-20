#include "FracFly.h"

void FracFly::NoEvento(SDL_Event * Evento) {
	FEvento::NoEvento(Evento);
}

void FracFly::OnExit() {
	Rodando = false;
}

void FracFly::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_ESCAPE:
			OnExit();
			break;
		/**
		case SDLK_UP:
			FEntidade::ListaEntidades[1]->moveCima = true;
			break;
		case SDLK_DOWN:
			FEntidade::ListaEntidades[1]->moveBaixo = true;
			break;
		case SDLK_RIGHT:
			FEntidade::ListaEntidades[1]->moveDireita = true;
			break;
		case SDLK_LEFT:
			FEntidade::ListaEntidades[1]->moveEsquerda = true;
			break;
		**/
        case SDLK_UP:
			FCamera::ControleCamera.NoMovimento( 0,  5);
			break;
        case SDLK_DOWN:
			FCamera::ControleCamera.NoMovimento( 0, -5);
			break;
        case SDLK_LEFT:
			FCamera::ControleCamera.NoMovimento( 5,  0);
			break;
        case SDLK_RIGHT:
			FCamera::ControleCamera.NoMovimento(-5,  0);
			break;
		default:
			break;
	}
}
void FracFly::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_UP:
			FEntidade::ListaEntidades[1]->moveCima = false;
			break;
		case SDLK_DOWN:
			FEntidade::ListaEntidades[1]->moveBaixo = false;
			break;
		case SDLK_RIGHT:
			FEntidade::ListaEntidades[1]->moveDireita = false;
			break;
		case SDLK_LEFT:
			FEntidade::ListaEntidades[1]->moveEsquerda = false;
			break;
		default:
			break;
	}
}

void FracFly::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
/**	
	double distancia = sqrt(pow(mX - Arma1.X, 2) + pow(mY - Arma1.Y, 2));
	
	double deltay =  (double) Arma1.Y-mY ;
	
	
	double angulo = (double) 90*(deltay/distancia);
**/    
    /* Rotate */
    //SDL_Surface *extraSurface;
    //extraSurface = rotozoomSurface(Arma1.getSurface(), angulo, 1, 1); 
    //Arma1.setSurface(extraSurface);
    //SDL_FreeSurface(extraSurface);

    //Arma1.Rotacionar(angulo,(double) 1,1);
	
}

void FracFly::OnLButtonDown(int mX, int mY) {
	Arma1.Atirar(mX,mY);
}
void FracFly::OnLButtonUp(int mX, int mY) {
	
}
void FracFly::OnRButtonDown(int mX, int mY) {
	
}
void FracFly::OnRButtonUp(int mX, int mY) {
	
}
void FracFly::OnMButtonDown(int mX, int mY) {
	
}
void FracFly::OnMButtonUp(int mX, int mY) {
	
}




//~ 
//~ 
//~ 
//~ while(SDL_PollEvent(&event)) {
			//~ Uint8 mousestate;
			//~ mousestate = SDL_GetMouseState(NULL, NULL);
//~ 
			//~ if (event.type == SDL_QUIT ) exit = 1;
			//~ 
			//~ if (event.type == SDL_KEYDOWN) {
				//~ if (event.key.keysym.sym == SDLK_SPACE) {
					//~ AimRe = -0.5; // Centro x do mouse
					//~ AimIm = 0.0; // centro y do mouse
					//~ MaxIterations = 30;
					//~ Zoom = 3.0;
				//~ }
//~ 
				//~ if (event.key.keysym.sym == SDLK_q) exit = 1;
				//~ if (event.key.keysym.sym == SDLK_ESCAPE) exit = 1;
//~ 
				//~ if (event.key.keysym.sym == SDLK_KP_PLUS) MaxIterations += 10;
				//~ if (event.key.keysym.sym == SDLK_KP_MINUS) MaxIterations -= 10;
				//~ 
				//~ if (event.key.keysym.sym == SDLK_KP4) KRe -= KStep;
				//~ if (event.key.keysym.sym == SDLK_KP6) KRe += KStep;
				//~ if (event.key.keysym.sym == SDLK_KP8) KIm -= KStep;
				//~ if (event.key.keysym.sym == SDLK_KP2) KIm += KStep;
//~ 
				//~ if (event.key.keysym.sym == SDLK_1) FracType = 1;
				//~ if (event.key.keysym.sym == SDLK_2) FracType = 2;
				//~ if (event.key.keysym.sym == SDLK_3) FracType = 3;
//~ 
				//~ if (event.key.keysym.sym == SDLK_r) {
					//~ ColR = rand() % 256;
					//~ ColG = rand() % 256;
					//~ ColB = rand() % 256;
				//~ }
//~ 
				//~ if (event.key.keysym.sym == SDLK_a) AnimateK = !AnimateK;
				//~ if (event.key.keysym.sym == SDLK_x) ShowAxis = !ShowAxis;
				//~ if (event.key.keysym.sym == SDLK_g) ShowGrid = !ShowGrid;
				//~ if (event.key.keysym.sym == SDLK_d) ShowDot = !ShowDot;
//~ 
				//~ if (event.key.keysym.sym == SDLK_m) {
					//~ MouseMode += 1;
					//~ if (MouseMode > 1) MouseMode = 0;
				//~ }
//~ 
				//~ if (event.key.keysym.sym == SDLK_t) {
					//~ ThreadHL += 1;
					//~ if (ThreadHL > 1) ThreadHL = 0;
				//~ }
//~ 
			//~ }
//~ 
			//~ if(mousestate & SDL_BUTTON(1) && MouseMode == 1){
    			//~ KIm = MaxIm - event.button.y*ImFactor;
				//~ KRe = MinRe + event.button.x*ReFactor;
			//~ } 
//~ 
			//~ if (event.type == SDL_MOUSEBUTTONDOWN && MouseMode == 0 ) { 
				//~ AimIm = MaxIm - event.button.y*ImFactor; // calcula um novo centro 
				//~ AimRe = MinRe + event.button.x*ReFactor;  // calcula um novo centro 
//~ 
				//~ if (event.button.button == SDL_BUTTON_LEFT) Zoom = Zoom*ZoomStep;
				//~ if (event.button.button == SDL_BUTTON_RIGHT) Zoom = Zoom*1.2;
			//~ }
		//~ }
