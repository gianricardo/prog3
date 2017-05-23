/*
 * jogador.cpp
 *
 *  Created on: 15 de mai de 2017
 *      Author: aluno
 */
#include <iostream>
#include "jogador.h"

namespace p3 {

/* Recebe o nome no construtor */
Jogador::Jogador(std::string name/* = "" */) : _nome{name}, _pontuacao{0}, _apto_para_jogar{true}{
}

Jogador::~Jogador() {

}

std::string Jogador::nome() const {

	return _nome;
}

/* Recebe uma carta como argumento e insere no final
 * do vector _mao. */
void Jogador::recebe_carta(Carta card){
	_mao.push_back(card);
}

bool Jogador::tira_carta(Carta card, bool cmp_face /* = false */){

	for(auto it = _mao.begin(); it != _mao.end(); it++){

		if(*it == card){

			if(cmp_face) if(it->mostra() != card.mostra()) continue;

			_mao.erase(it);

			return true;
		}
	}
	
	return false;
}

int Jogador::pontuacao() const {

	return _pontuacao;
}

void Jogador::pontuacao(int p){

	_pontuacao = p;
}

void Jogador::muda_aptidao(){
	 _apto_para_jogar = !( _apto_para_jogar);
}

bool Jogador::esta_apto() const {
	
	return _apto_para_jogar;
}


const std::vector<Carta> Jogador::mostra_mao() const {

	return _mao;
}


} /* namespace p3 */

