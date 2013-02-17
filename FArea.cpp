#include "FArea.h"

FArea FArea::ControleArea;

FArea::FArea() {
	TamArea = 0;
}

bool FArea::NoCarregar(char * Arquivo) {
	ListaMapas.clear();
	FILE * arqMan = fopen(Arquivo, "r");
	if (arqMan == NULL) {
		printf("FArea: Não foi possivel abrir %s\n", Arquivo);
		return false;
	}
	char ConjAzulejoArquivo[255];
	fscanf(arqMan, "%s\n", ConjAzulejoArquivo);
	
	if((Surf_ConjAzulejo = FSuperficie::NoCarregar(ConjAzulejoArquivo)) == false)	{
		fclose(arqMan);
		printf("FArea: Não foi possivel abrir %s\n", ConjAzulejoArquivo);
		return false;
	}
	
	fscanf(arqMan, "%d\n", &TamArea);
	for(int X = 0; X < TamArea; X++) {
		for(int Y = 0; Y < TamArea; Y++) {
			char MapArquivo[255];
			fscanf(arqMan, "%s ", MapArquivo);
			
			FMap tempMap;
			if(tempMap.NoCarregar(MapArquivo) == false) {
				fclose(arqMan);
				printf("FArea: Não foi possivel abrir %s\n", MapArquivo);
				return false;
			}
			tempMap.Surf_ConjAzulejo = Surf_ConjAzulejo;
			ListaMapas.push_back(tempMap);
		}
	}
	return true;
}

void FArea::NaRenderizacao(SDL_Surface * Plano_Exibicao, int CameraX, int CameraY) {
	int MapWidth = MAP_WIDTH * TAMANHO_AZULEJO;
	int MapHeight = MAP_HEIGHT * TAMANHO_AZULEJO;
	int PrimeiroID = -CameraX / MapWidth;
		PrimeiroID = PrimeiroID + ((-CameraX / MapHeight) * TamArea);
		
	for(int i = 0; i < 4; i++) {
		int ID = (PrimeiroID + (((i / 2) * TamArea) + (i % 2)));
		if (ID = 0 || ID >= (int) ListaMapas.size()) continue;
		
		int X = ((ID % TamArea) * MapWidth) + CameraX;
		int Y = ((ID / TamArea) * MapHeight) + CameraY;
		
		ListaMapas[ID].NaRenderizacao(Plano_Exibicao, X, Y);
		
	}
}

void FArea::NaLimpeza() {
	if (Surf_ConjAzulejo) {
		SDL_FreeSurface(Surf_ConjAzulejo);
	}
	
	ListaMapas.clear();
}
