#include "FCamera.h"
 
FCamera FCamera::controleCamera;
 
FCamera::FCamera() {
    x = y = 0;
 
    alvoX = alvoY = NULL;
 
    modoAlvo = MODO_ALVO_NORMAL;
}
 
void FCamera::NoMovimento(int movX, int movY) {
    x += movX;
    y += movY;
}
 
int FCamera::GetX() {
    if(alvoX != NULL) {
        if(modoAlvo == MODO_ALVO_CENTRO) {
            return * alvoX - (WWIDTH / 2);
        }
 
        return * alvoX;
    }
 
    return x;
}
 
int FCamera::GetY() {
    if(alvoY != NULL) {
        if(modoAlvo == MODO_ALVO_CENTRO) {
            return * alvoY - (WHEIGHT / 2);
        }
 
        return * alvoY;
    }
 
    return y;
}
 
void FCamera::SetPos(int X, int Y) {
    this->x = x;
    this->y = y;
}
 
void FCamera::SetAlvo(int * x, int * y) {
    alvoX = x;
    alvoY = y;
}
