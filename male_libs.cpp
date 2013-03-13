/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#include "male_libs.h"


string itoa(int num) {
	string retorno;
	string invertido;
	char const digit[] = "0123456789";
	invertido.clear();
	retorno.clear();
	int res = 0;
	do {
		res = num % 10;
		invertido += digit[res];
	} while ((num = (num / 10)) > 0);
	for (int i=(int) invertido.size() -1; i >= 0 ;i--)
		retorno += invertido[i];

	return retorno;
}
