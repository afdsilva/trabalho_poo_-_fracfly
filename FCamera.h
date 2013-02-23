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
        static FCamera controleCamera;
 
    private:
        int x;
        int y;
 
        float * alvoX;
        float * alvoY;
 
    public:
        int modoAlvo;
 
    public:
        FCamera();
 
    public:
        void NoMovimento(int movX, int movY);
 
    public:
        int GetX();
        int GetY();
 
    public:
        void SetPos(int x, int y);
 
        void SetAlvo(float * x, float * y);
};
 
#endif
