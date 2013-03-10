/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
 *
 * Classe para tratamento de excecoes
 **/
#include "Excecoes.h"

std::string Excecoes::msgErro = "";
int Excecoes::linhaErro = 0;

Excecoes::Excecoes() {
}

Excecoes::~Excecoes() {

}

int Excecoes::TratamentoExcecao() {
	debug(Excecoes::msgErro, Excecoes::linhaErro);
	return 1;
}
