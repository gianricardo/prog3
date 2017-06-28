/*
 * paciencia.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: lucas
 */

#include "paciencia.h"

namespace p3 {

Paciencia::Paciencia(std::string nome_jogador){

	_estado_jogo = new Estado_jogo(nome_jogador); // vazamento
}

Paciencia::~Paciencia() {

	delete(_estado_jogo);

}

void Paciencia::rodada(){

	_tela.tela_jogo(_estado_jogo);

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
  	std::istringstream iss(_jogada);
	std::string token;

	std::getline(iss, token, ' ');

	m1 = std::atoi(token.c_str());

	std::getline(iss, token, ' ');
	m2 = std::atoi(token.c_str());

	if(!(_estado_jogo->realiza_jogada(m1, m2))){

		_tela.jogada_invalida();
	}

	if(_estado_jogo->fim_jogo()){

		_jogada = "Vitoria";
		return false;
	}

	return true;
}

void Paciencia::fim(){

	if(_jogada == "Vitoria"){

		_tela.vitoria();
	}
	else{

		_tela.derrota();
	}
}


} /* namespace p3 */
