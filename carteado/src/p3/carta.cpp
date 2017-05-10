/*
 * carta.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#include "carta.h"

namespace p3 {

Carta::Carta(int num, Naipe np,bool f=false):	//por padrao carta virada para baixo
		_numero{num},_naipe{np},_frente{f}{
}

Carta::~Carta() {
}

int Carta::numero(){
	return _numero;
}

Carta::Naipe Carta::naipe(){
	return _naipe;
}

void Carta::vira(){
	_frente=!_frente;
}

bool Carta::mostra(){
	return _frente;
}

}/* namespace p3 */
