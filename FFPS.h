#ifndef _FFPS_H_
	#define _FFPS_H_
	
#include <SDL/SDL.h>

class FFPS {
	public:
		static FFPS FPSControle;
		
	private:
		int TempoAntigo;
		int UltimoTempo;
		
		float FatorVelocidade;
		
		int NumFrames;
		int Frames;
		
	public:
		FFPS();
		
		void NoLaco();
		
	public:
		int getFPS();
		float getFatorVelocidade();
};

#endif
