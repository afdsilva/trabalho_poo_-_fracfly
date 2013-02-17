#include "FMap.h"

FMap::FMap() {
	Surf_ConjAzulejo = NULL;
}

bool FMap::NoCarregar(char * Arquivo) {
	ListaAzulejo.clear();
	
	FILE * arqMan = fopen(Arquivo, "r");
	
	if(arqMan == NULL) {
		printf("FMap: Não foi possivel abrir %s\n", Arquivo);
		return false;
	}
	for (int Y = 0; Y < MAP_HEIGHT; Y++) {
		for (int X = 0; X < MAP_WIDTH; X++) {
			FAzulejo tmpAzulejo;
			fscanf(arqMan, "%d:%d", &tmpAzulejo.AzulejoID, &tmpAzulejo.TipoID);
			ListaAzulejo.push_back(tmpAzulejo);
		}
		fscanf(arqMan, "\n");
	}
	fclose(arqMan);

	return true;
}

void FMap::NaRenderizacao(SDL_Surface * Plano_Exibicao, int MapX, int MapY) {
	if (Surf_ConjAzulejo == NULL) return;
	int ConjAzulejoWidth = Surf_ConjAzulejo->w / TAMANHO_AZULEJO;
	//int ConjAzulejoHeight = Surf_ConjAzulejo->h / TAMANHO_AZULEJO;
	
	int ID = 0;
	for (int Y = 0; Y < MAP_HEIGHT;Y++) {
		for (int X = 0; X < MAP_HEIGHT;X++) {
			if(ListaAzulejo[ID].TipoID == AZULEJO_TIPO_NONE) {
				ID++;
				continue;
			}
			int tX = MapX + (X * TAMANHO_AZULEJO);
			int tY = MapY + (Y * TAMANHO_AZULEJO);
			
			int ConjAzulejoX = (ListaAzulejo[ID].AzulejoID % ConjAzulejoWidth) * TAMANHO_AZULEJO;
			int ConjAzulejoY = (ListaAzulejo[ID].AzulejoID / ConjAzulejoWidth) * TAMANHO_AZULEJO;
			
			FSuperficie::NoDesenhar(Plano_Exibicao, Surf_ConjAzulejo, tX, tY, ConjAzulejoX, ConjAzulejoY, TAMANHO_AZULEJO, TAMANHO_AZULEJO);
			
			ID++;
		}
	}
}
