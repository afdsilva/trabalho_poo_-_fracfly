/**
 * Trabalho POO - Fracfly
 * Integrantes:
 * - André Felipe da Silva
 * - Eliézer Ribeiro
 * - Mario Saldanha
 * - Lucio Leal Bastos
**/

#ifndef _MALE_LIBS_H_
	#define _MALE_LIBS_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Excecoes.h"

using namespace std;

template <typename T> void debug(T texto) {
	cout << texto << endl;
}
template <typename T> void debug(T texto,int linha) {
	cout << "SAIDA: " << texto << " LINHA: " << linha << endl;
}


string itoa(int);

#endif
