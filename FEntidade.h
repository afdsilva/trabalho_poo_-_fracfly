#ifndef _FENTIDADE_H
  #define _FENTIDADE_H

#include <vector>
#include <iostream>

#include "FArea.h"
#include "FAnimacao.h"
#include "FCamera.h"
#include "FFPS.h"
#include "FSuperficie.h"

using namespace std;


enum {
	TIPO_ENTIDADE_GENERICO = 0,
	TIPO_ENTIDADE_JOGADOR,
	TIPO_ENTIDADE_TIRO
	
};

enum {
	ENTIDADE_FLAG_NONE = 0,
	
	ENTIDADE_FLAG_GRAVIDADE		= 0x00000001,
	ENTIDADE_FLAG_FANTASMA		= 0x00000002,
	ENTIDADE_FLAG_SOMENTEMAPA	= 0x00000004,
	ENTIDADE_FLAG_ESPACO		= 0x00000008,
};

class FEntidade {
	public:
		static vector<FEntidade*> listaEntidades;
		
	protected:
		FAnimacao 			controleAnimacao;
		SDL_Surface * 		superficieEntidade;

	public:
		float	x;
		float 	y;

		int 	width; //nomes da variavel em ingles
		int 	height; //pra facilitar o entendimento Width = largura, Height = altura
		
		bool 	moveCima;
		bool 	moveBaixo;
		bool 	moveDireita;
		bool 	moveEsquerda;
		
	public:
		int 	tipo;
		
		bool 	morto;
		int 	flags;
		
	protected:
		float 	velX;
		float 	velY;
		
		float 	acelX;
		float 	acelY;
		
	public:
		float 	velMaxX;
		float 	velMaxY;
	
	protected: //variaveis de Animacao
		int 	frameAtualCol;
		int 	frameAtualLinha;

	protected: //variaveis de colisao
		int 	colX;
		int 	colY;
		int 	colWidth;
		int 	colHeight;
		
	public:
		FEntidade();
		
		virtual ~FEntidade();
		
	public:
		virtual bool NoCarregar (char * arquivo, int width, int height, int maxFrames);
		virtual void NoLaco();
		virtual void NaRenderizacao(SDL_Surface * planoExibicao);
		virtual void NaLimpeza();
		virtual void NaAnimacao();
		virtual bool NaColisao(FEntidade * entidade);

		SDL_Surface * GetSuperficie();
		void SetSuperficie(SDL_Surface *);
		virtual bool Rotacionar(double angulo, double zoom, int smooth);
		
	public:
		void	NoMovimento(float moveX, float moveY);
		void	PararMovimento();

	public:
		bool Colisoes(int oX, int oY, int oW, int oH);
	
	private:
		bool PosValido(int novoX, int novoY);
		bool PosValidoAzulejo(FAzulejo * azulejo);
		bool PosValidoEntidade(FEntidade * entidade, int novoX, int novoY);
		
};

class FEntidadeColisao {
	public:
		static std::vector<FEntidadeColisao> listaEntidadesColisoes;
	
	public:
		FEntidade * entidadeA;
		FEntidade * entidadeB;
		
	public:
		FEntidadeColisao();
};

#endif
