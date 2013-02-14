#include "FAnimacao.h"
 
FAnimacao::FAnimacao() {
    FrameAtual = 0;
    MaxFrames = 0;
    FrameInc = 1;
 
    FrameRate = 100; //Milisegundos
    AntTime = 0;
 
    Oscilacao = false;

    printf("FrameAtual: %d \n", FrameAtual);

}
 
void FAnimacao::NaAnimacao() {
    if(AntTime + FrameRate > SDL_GetTicks()) {
        return;
    }
 
    AntTime = SDL_GetTicks();
 
    FrameAtual += FrameInc;
    if(Oscilacao) {
        if(FrameInc > 0) {
            if(FrameAtual >= MaxFrames) {
                FrameInc = -FrameInc;
            }
        }else{
            if(FrameAtual <= 0) {
                FrameInc = -FrameInc;
            }
        }
    }else{
        if(FrameAtual >= MaxFrames) {
            FrameAtual = 0;
        }
    }
}
 
void FAnimacao::SetFrameRate(int Rate) {
    FrameRate = Rate;
}
 
void FAnimacao::SetFrameAtual(int Frame) {
    if(Frame < 0 || Frame >= MaxFrames) return;
 
    FrameAtual = Frame;
}
 
int FAnimacao::GetFrameAtual() {
    return FrameAtual;
}
