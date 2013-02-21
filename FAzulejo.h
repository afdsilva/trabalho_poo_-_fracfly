#ifndef _FAZULEJO_H
	#define _FAZULEJO_H

#include "Definicoes.h"

//
enum {
	AZULEJO_TIPO_NONE = 0,
	AZULEJO_TIPO_NORMAL,
	AZULEJO_TIPO_BLOCO
};

class FAzulejo {
	public:
		FAzulejo();
	public:
		int azulejoId;
		int tipoId;
};

#endif
