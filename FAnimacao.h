#ifndef _FANIMACAO_H_
    #define _FANIMACAO_H_
 
#include <SDL/SDL.h>
 
class FAnimacao {
	private:
		int    FrameAtual;
		int     FrameInc;

    private:
        int     FrameRate;
        long    AntTime;
 
    public:
        int    MaxFrames;
        bool    Oscilacao;
 
    public:
        FAnimacao();
        void NaAnimacao();
 
    public:
        void SetFrameRate(int Rate);
        void SetFrameAtual(int Frame);
        int GetFrameAtual();
};

#endif
