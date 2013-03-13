/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _FANIMACAO_H_
    #define _FANIMACAO_H_
 
#include <SDL/SDL.h>
 
class FAnimacao {
	private:
		int    frameAtual;
		int     frameInc;

    private:
        int     frameRate;
        long    antTime;
 
    public:
        int    maxFrames;
        bool    oscilacao;
 
    public:
        FAnimacao();
        void NaAnimacao();
 
    public:
        void SetFrameRate(int rate);
        void SetFrameAtual(int frame);
        int GetFrameAtual();
};

#endif
