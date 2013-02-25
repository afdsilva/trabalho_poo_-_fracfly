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

using namespace std;

template <typename T> void debug(T texto) {
	cout << "Texto: " << texto << endl;
}
template <typename T> void debug(T texto,int linha) {
	cout << "TEXTO: " << texto << " LINHA: " << linha << endl;
}


#endif
