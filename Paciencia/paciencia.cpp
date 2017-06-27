/*
 * paciencia.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: lucas
 */

#include "paciencia.h"

namespace p3 {

Paciencia::Paciencia() {

}

Paciencia::~Paciencia() {

}

void Paciencia::rodada(){

	_tela.pontuacao_tela(&_estado_jogo);
	_tela.tela_jogo(&_estado_jogo);

	Paciencia::set_jogada();
}


void Paciencia::set_jogada(){

	_jogada = _tela.jogada_atual();
}

std::string Paciencia::get_jogada(){
	return _jogada;
}

bool Paciencia::verifica_jogada(){

	int m1, m2 = 1;
	m1 = std::atoi(std::strtok((char *)_jogada, " "));

	if(m1 != 0)
		m2 = std::atoi(std::strtok(NULL, " "));

	if(!(_estado_jogo.realiza_jogada(m1, m2))){

		_tela.jogada_invalida();
	}

	if(_estado_jogo.fim_jogo())
		return false;

	return true;
}


} /* namespace p3 */
