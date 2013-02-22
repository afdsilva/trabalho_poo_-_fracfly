#include "FArea.h"

/**
 * Variavel estatica que controla todas areas 
 **/
FArea FArea::controleArea;

/**
 * Construtor de Area
 **/
FArea::FArea() {
	tamArea = 0;
}

/**
 * Carrega a lista de mapas na area
 **/
bool FArea::NoCarregar(char * arquivo) {
	listaMapas.clear();
	FILE * arqMan = fopen(arquivo, "r");
	if (arqMan == NULL) {
		printf("FArea: Não foi possivel abrir %s\n", arquivo);
		return false;
	}
	char conjAzulejoArquivo[255];
	fscanf(arqMan, "%s\n", conjAzulejoArquivo);
	
	if((superficieConjAzulejo = FSuperficie::NoCarregar(conjAzulejoArquivo)) == false)	{
		fclose(arqMan);
		printf("FArea: Não foi possivel abrir %s\n", conjAzulejoArquivo);
		return false;
	}
	
	fscanf(arqMan, "%d\n", &tamArea);
	for(int x = 0; x < tamArea; x++) {
		for(int y = 0; y < tamArea; y++) {
			char mapArquivo[255];
			fscanf(arqMan, "%s ", mapArquivo);
			
			FMap tempMap;
			if(tempMap.NoCarregar(mapArquivo) == false) {
				fclose(arqMan);
				printf("FArea: Não foi possivel abrir %s\n", mapArquivo);
				return false;
			}
			tempMap.superficieConjAzulejo = superficieConjAzulejo;
			listaMapas.push_back(tempMap);
		}
	}
	return true;
}

/**
 * Renderiza a area
 **/
void FArea::NaRenderizacao(SDL_Surface * planoExibicao, int cameraX, int cameraY) {
	int mapWidth = MAP_WIDTH * TAMANHO_AZULEJO;
	int mapHeight = MAP_HEIGHT * TAMANHO_AZULEJO;
	int primeiroId = -cameraX / mapWidth;
		primeiroId = primeiroId + ((-cameraX / mapHeight) * tamArea);
		
	for(int i = 0; i < 4; i++) {
		int id = (primeiroId + (((i / 2) * tamArea) + (i % 2)));
		
		if (id < 0 || id >= (int) listaMapas.size()) continue;
		
		int x = ((id % tamArea) * mapWidth) + cameraX;
		int y = ((id / tamArea) * mapHeight) + cameraY;
		
		listaMapas[id].NaRenderizacao(planoExibicao, x, y);
		
	}
}

/**
 * coletor de lixo da area
 **/
void FArea::NaLimpeza() {
	if (superficieConjAzulejo) {
		SDL_FreeSurface(superficieConjAzulejo);
	}
	
	listaMapas.clear();
}

/**
 * Retorna um mapa apartir de uma posicao
 **/
FMap * FArea::GetMap(int x, int y) {
	int mapWidth = MAP_WIDTH * TAMANHO_AZULEJO;
	int mapHeight = MAP_HEIGHT * TAMANHO_AZULEJO;
	
	int id = x / mapWidth;
		id = id + (y / mapHeight) * tamArea;
	
	if (id < 0 || id >= (int) listaMapas.size()) {
		return NULL;
	}
	return &listaMapas[id];

}

/**
 * Retorna um azulejo apartir de uma posicao
 **/
FAzulejo * FArea::GetAzulejo(int x, int y) {
	int mapWidth = MAP_WIDTH * TAMANHO_AZULEJO;
	int mapHeight = MAP_HEIGHT * TAMANHO_AZULEJO;
	
	FMap * mapa = GetMap(x, y);
	if (mapa == NULL) return NULL;
	x = x % mapWidth;
	y = y % mapHeight;
	
	return mapa->GetAzulejo(x, y);
}
