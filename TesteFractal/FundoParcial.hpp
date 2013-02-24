#ifndef FundoParcial_H
#define FundoParcial_H

#include "Threads.hpp"

class FundoParcial : public Thread {
public:
	
	static SDL_Surface *screen;	 
	static double KRe, KIm;
	static double MinRe, MaxIm, ReFactor, ImFactor;
	static unsigned short MaxIterations;
	static unsigned short int FracType,ColR, ColG, ColB;
	static unsigned SCREEN_WIDTH;
	
	static int exit;
	
	unsigned start_x;
	unsigned start_y;
	unsigned stop_x;
	unsigned stop_y;
		
	public:
		FundoParcial();
		
		void setStart_x(int start_x );
		void setStart_y(int start_y);
		void setStop_x(int stop_x );
		void setStop_y(int stop_y );
		
		
		
		int setpixel(SDL_Surface *screen, int x, int y, Uint8 r, Uint8 g, Uint8 b) ;
		
		void run();
		
		void pauseThread();
		bool getRunning();
		void setRunning(bool m_running );

};
#endif
