/*
 * paciencia.cpp
 *
 *  Created on: 7 de jun de 2017
 *      Author: lucas
 */

#include "paciencia.h"

namespace p3 {

Paciencia::Paciencia(){

    _estado_jogo = new Estado_jogo(_nome_jogador);
}

Paciencia::~Paciencia() {

	delete(_estado_jogo);

}

bool Paciencia::verifica_jogada(int m1, int m2){

	if(!(_estado_jogo->realiza_jogada(m1, m2))){

        _jogada = "Jogada Invalida!";
	}
	else
		_jogada = " ";

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

std::string Paciencia::nome_jogador(){

	return _nome_jogador;
}

std::string Paciencia::pontuacao(){

    return std::to_string(_estado_jogo->pontuacao_jogador());
}

std::string Paciencia::jogada_atual(){

	return _jogada;
}

void Paciencia::nome_jogador(std::string nome){

	_nome_jogador = nome;

	std::cout << nome << std::endl;
}


Estado_jogo *Paciencia::get_jogo(){

	return _estado_jogo;
}


} /* namespace p3 */
