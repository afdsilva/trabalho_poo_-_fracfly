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
std::string Excecoes::classErro = "";
int Excecoes::linhaErro = -1;

Excecoes::Excecoes() {
}

Excecoes::~Excecoes() {

}

int Excecoes::TratamentoExcecao() {
	string saida = "ERROR:\nCLASS: ";
	saida += Excecoes::classErro;
	saida += " MSG: ";
	saida += Excecoes::msgErro;
	if (Excecoes::linhaErro != -1)
		saida += " LINHA: ";
	saida +=
	debug(Excecoes::msgErro, Excecoes::linhaErro);
	return 1;
}
