/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FFPS_H_
	#define _FFPS_H_
	
#include <SDL/SDL.h>

class FFPS {
	public:
		static FFPS FPSControle;
		
	private:
		int tempoAntigo;
		int ultimoTempo;
		
		float fatorVelocidade;
		
		int numFrames;
		int frames;
		
	public:
		FFPS();
		
		void NoLaco();
		
	public:
		int GetFPS();
		float GetFatorVelocidade();
};

#endif
