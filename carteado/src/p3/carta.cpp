/*
 * carta.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#include "carta.h"

namespace p3 {

Carta::Carta(int num, Naipe np, bool f /* =false */):	//por padrao carta virada para baixo
		_numero{num},_naipe{np},_frente{f}{
}

Carta::~Carta() {
}

int Carta::numero() const {
	return _numero;
}

Carta::Naipe Carta::naipe() const {
	return _naipe;
}

void Carta::vira(){
	_frente=!_frente;
}

bool Carta::mostra() const {
	return _frente;
}

bool Carta::operator==(const Carta& c) const {

	if(this->_numero != c._numero) return false;
	if(this->_naipe != c._naipe) return false;
	return true;
}

bool Carta::operator!=(const Carta& c) const {

	return !(*this == c);
}

bool Carta::operator<(const Carta& c) const {

	if(this->_numero < c._numero) return true;
	if(this->_naipe < c._naipe) return true;

	return false;
}

bool Carta::operator>(const Carta& c) const{

	return !(*this <= c);
} 

bool Carta::operator<=(const Carta& c) const{

	return (*this == c || *this < c);
}

bool Carta::operator>=(const Carta& c) const{

	return !(*this < c);
}



}/* namespace p3 */



