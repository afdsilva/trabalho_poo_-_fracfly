/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef EXCECOES_H_
	#define EXCECOES_H_

#include <iostream>
#include <string>

#include "male_libs.h"

class Excecoes {
public:
	static std::string msgErro;
	static std::string classErro;
	static int linhaErro;

public:
	Excecoes();
	virtual ~Excecoes();

public:
	static int TratamentoExcecao();
};

#endif
