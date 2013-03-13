/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "FAnimacao.h"
 
FAnimacao::FAnimacao() {
    frameAtual = 0;
    maxFrames = 0;
    frameInc = 1;
 
    frameRate = 100; //Milisegundos
    antTime = 0;
 
    oscilacao = false;
}
 
void FAnimacao::NaAnimacao() {
    if(antTime + frameRate > SDL_GetTicks()) {
        return;
    }
 
    antTime = SDL_GetTicks();
 
    frameAtual += frameInc;
    if(oscilacao) {
        if(frameInc > 0) {
            if(frameAtual >= maxFrames) {
                frameInc = -frameInc;
            }
        }else{
            if(frameAtual <= 0) {
                frameInc = -frameInc;
            }
        }
    }else{
        if(frameAtual >= maxFrames) {
            frameAtual = 0;
        }
    }
}
 
void FAnimacao::SetFrameRate(int rate) {
    frameRate = rate;
}
 
void FAnimacao::SetFrameAtual(int frame) {
    if(frame < 0 || frame >= maxFrames) return;
 
    frameAtual = frame;
}
 
int FAnimacao::GetFrameAtual() {
    return frameAtual;
}
