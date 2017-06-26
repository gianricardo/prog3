/*
 * paciencia.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: lucas
 */

#include "paciencia.h"

namespace p3 {

Paciencia::Paciencia() {
	// TODO Auto-generated constructor stub

}

Paciencia::~Paciencia() {
	// TODO Auto-generated destructor stub
}

void Paciencia::set_jogada(std::string jogada){
	_jogada = jogada;
}

std::string Paciencia::get_jogada(){
	return _jogada;
}

bool Paciencia::verifica_jogada(){

	char * pEnd;

	int m1, m2 = 1;
	m1 = std::atoi(std::strtok(_jogada, " "));

	if(m1 != 0)
		m2 = std::atoi(std::strtok(NULL, " "));

	return Estado_jogo::realiza_jogada(m1, m2);
}


















} /* namespace p3 */
