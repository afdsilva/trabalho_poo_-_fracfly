#ifndef _FCAMERA_H_
    #define _FCAMERA_H_
 
#include <SDL/SDL.h>
 
#include "Definicoes.h"
 
enum {
    MODO_ALVO_NORMAL = 0,
    MODO_ALVO_CENTRO
};
 
class FCamera {
    public:
        static FCamera ControleCamera;
 
    private:
        int X;
        int Y;
 
        int* AlvoX;
        int* AlvoY;
 
    public:
        int ModoAlvo;
 
    public:
        FCamera();
 
    public:
        void NoMovimento(int MovX, int MovY);
 
    public:
        int GetX();
        int GetY();
 
    public:
        void SetPos(int X, int Y);
 
        void SetAlvo(int* X, int* Y);
};
 
#endif
