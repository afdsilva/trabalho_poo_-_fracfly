/*
 * Excecoes.h
 *
 *  Created on: 09/03/2013
 *      Author: andref
 */

#ifndef EXCECOES_H_
	#define EXCECOES_H_

#include <iostream>
#include <string>

#include "male_libs.h"

class Excecoes {
public:
	static std::string msgErro;
	static int linhaErro;

public:
	Excecoes();
	virtual ~Excecoes();

public:
	static int TratamentoExcecao();
};

#endif
