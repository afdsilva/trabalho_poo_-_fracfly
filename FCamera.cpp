#include "FCamera.h"
 
FCamera FCamera::ControleCamera;
 
FCamera::FCamera() {
    X = Y = 0;
 
    AlvoX = AlvoY = NULL;
 
    ModoAlvo = MODO_ALVO_NORMAL;
}
 
void FCamera::NoMovimento(int MovX, int MovY) {
    X += MovX;
    Y += MovY;
}
 
int FCamera::GetX() {
    if(AlvoX != NULL) {
        if(ModoAlvo == MODO_ALVO_CENTRO) {
            return *AlvoX - (WWIDTH / 2);
        }
 
        return * AlvoX;
    }
 
    return X;
}
 
int FCamera::GetY() {
    if(AlvoY != NULL) {
        if(ModoAlvo == MODO_ALVO_CENTRO) {
            return *AlvoY - (WHEIGHT / 2);
        }
 
        return *AlvoY;
    }
 
    return Y;
}
 
void FCamera::SetPos(int X, int Y) {
    this->X = X;
    this->Y = Y;
}
 
void FCamera::SetAlvo(int* X, int* Y) {
    AlvoX = X;
    AlvoY = Y;
}
