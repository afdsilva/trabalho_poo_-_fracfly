#include "FundoParcial.hpp"

		void FundoParcial ::setStart_x(int start_x ){
			this->start_x = start_x;	
		}
		void FundoParcial ::setStart_y(int start_y){
			this->start_y = start_y;	
		}
		void FundoParcial ::setStop_x(int stop_x ){
			this->stop_x = stop_x;
		}
		void FundoParcial ::setStop_y(int stop_y ){
			this->stop_y = stop_y;
		}
		
		void FundoParcial ::setScreen(SDL_Surface * screen ){
			this->screen = screen;
		}
	
		FundoParcial ::FundoParcial(){
		 start_x=0;
	
		}
		
		int FundoParcial :: setpixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b) {			
			Uint32 *pixmem, colour;
			colour = SDL_MapRGB( screen->format, r, g, b);
			pixmem = (Uint32*)screen->pixels + (y*screen->w) + x; 
			*pixmem = colour; 
			return 0;
		}
		
		void FundoParcial :: run(){
			int			isInside;
			unsigned	y,x,n;
			double tmp, c_im, c_re, Z_re, Z_im, Z_re2, Z_im2;

			while(!exit) {
				for (y = start_y; y < stop_y; ++y) {
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
								tmp = (double) (n*9)/(double)MaxIterations; // Mudando o temp se muda as cores tendo uma ideia bem legal
					// Isso occorre porque tem uma gama MAIOR de rgb e logo se é mais perto de 255 então fica com mais cores vivas
								setpixel( screen, x, y, (Uint8)(tmp*ColR), (Uint8)(tmp*ColG), (Uint8)(tmp*ColB));
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
							setpixel( screen, x, y, 25, 255, 150); 
							// Muda o centro onde tudo é uma cor padrão aqui fica legal de mudar algo. 
					}
				}
			}
	}
