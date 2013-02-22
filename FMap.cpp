#include "FMap.h"

/**
 * Construtor do mapa;
 **/
FMap::FMap() {
	superficieConjAzulejo = NULL;
}

/**
 * Carrega um recurso de mapa
 **/
bool FMap::NoCarregar(char * arquivo) {
	listaAzulejo.clear();
	
	FILE * arqMan = fopen(arquivo, "r");
	
	if(arqMan == NULL) {
		printf("FMap: Não foi possivel abrir %s\n", arquivo);
		return false;
	}
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			FAzulejo tmpAzulejo;
			fscanf(arqMan, "%d:%d", &tmpAzulejo.azulejoId, &tmpAzulejo.tipoId);
			listaAzulejo.push_back(tmpAzulejo);
		}
		fscanf(arqMan, "\n");
	}
	fclose(arqMan);

	return true;
}

/**
 * Renderiza o Mapa
 **/
void FMap::NaRenderizacao(SDL_Surface * planoExibicao, int mapX, int mapY) {
	if (superficieConjAzulejo == NULL) return;
	int conjAzulejoWidth = superficieConjAzulejo->w / TAMANHO_AZULEJO;
	//int ConjAzulejoHeight = superficieConjAzulejo->h / TAMANHO_AZULEJO;
	
	int id = 0;
	for (int y = 0; y < MAP_HEIGHT;y++) {
		for (int x = 0; x < MAP_HEIGHT;x++) {
			if(listaAzulejo[id].tipoId == AZULEJO_TIPO_NONE) {
				id++;
				continue;
			}
			int tX = mapX + (x * TAMANHO_AZULEJO);
			int tY = mapY + (y * TAMANHO_AZULEJO);
			
			int conjAzulejoX = (listaAzulejo[id].azulejoId % conjAzulejoWidth) * TAMANHO_AZULEJO;
			int conjAzulejoY = (listaAzulejo[id].azulejoId / conjAzulejoWidth) * TAMANHO_AZULEJO;
			
			FSuperficie::NoDesenhar(planoExibicao, superficieConjAzulejo, tX, tY, conjAzulejoX, conjAzulejoY, TAMANHO_AZULEJO, TAMANHO_AZULEJO);
			
			id++;
		}
	}
}

/**
 * Retorna um azulejo apartir de uma posicao
 **/
FAzulejo * FMap::GetAzulejo(int x, int y) {
	int id = 0;
	id = x / TAMANHO_AZULEJO;
	id = id + (MAP_WIDTH * (y / TAMANHO_AZULEJO));
	if (id < 0 || id >= (int)listaAzulejo.size()) {
		return NULL;
	}
	
	return &listaAzulejo[id];
}
