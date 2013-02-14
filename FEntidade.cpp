#include "FEntidade.h"

std::vector<FEntidade*> FEntidade::ListaEntidades;

FEntidade::FEntidade() {

	Surf_Entidade = NULL;
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

bool FEntidade::NoCarregar (char * Arquivo, int Width, int Height, int MaxFrames) {
	if ((Surf_Entidade = FSuperficie::NoCarregar(Arquivo)) == NULL) {
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
	if (moveCima && Y > 0) Y--;
	if (moveBaixo && Y < (480-Width)) Y++;
	if (moveDireita && X < (640-Height)) X++;
	if (moveEsquerda && X > 0) X--;
	
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
