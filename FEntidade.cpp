#include "FEntidade.h"

std::vector<FEntidade*> FEntidade::ListaEntidades;

FEntidade::FEntidade() {

	Surf_Entidade = NULL;
	Surf_EntidadeOriginal = NULL;
	X = Y = 0.0f;
	
	Width = Height = 0;
	
	AnimEstado = 0;

	moveCima = false;
	moveBaixo = false;
	moveDireita = false;
	moveEsquerda = false;
	
	Aceleracao = 2;

}

FEntidade::~FEntidade() {
}

SDL_Surface *FEntidade::getSurface(){
	return Surf_EntidadeOriginal;
	}

void FEntidade::setSurface(SDL_Surface *novo){
	Surf_Entidade = novo;
}	

bool FEntidade::NoCarregar (char * Arquivo, int Width, int Height, int MaxFrames) {
	if ((Surf_Entidade = Surf_EntidadeOriginal= FSuperficie::NoCarregar(Arquivo)) == NULL) {
		return false;
	}
	FSuperficie::Transparencia(Surf_Entidade, 255, 0, 255);
	
	this->Width = Width;
	this->Height = Height;
	
	Anim_Control.MaxFrames = MaxFrames;
	
	return true;
}

void FEntidade::NoLaco() {
	Anim_Control.NaAnimacao();
}

void FEntidade::NaRenderizacao(SDL_Surface * Plano_Exibicao) {
	if (Surf_Entidade == NULL || Plano_Exibicao == NULL) return;
	
	FSuperficie::NoDesenhar(Plano_Exibicao, Surf_Entidade, X, Y, AnimEstado * Width, Anim_Control.GetFrameAtual() * Height, Width, Height);
}

void FEntidade::NaLimpeza() {
	if(Surf_Entidade) {
		SDL_FreeSurface(Surf_Entidade);
	}
	Surf_Entidade = NULL;
}

bool FEntidade::Rotacionar(double angulo, double zoom, int smooth) {
	if(Surf_Entidade == NULL) {
		return false;
	}
	FSuperficie::Rotacionar(Surf_Entidade, angulo, zoom, smooth);
	return true;
}
