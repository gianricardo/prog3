/*
 * jogador.cpp
 *
 *  Created on: 15 de mai de 2017
 *      Author: aluno
 */

#include "jogador.h"

namespace p3 {

Jogador::Jogador(std::string name) {
	_nome=name;
}

Jogador::~Jogador() {

}

void Jogador::recebe_carta(Carta card){
	_mao.push_back(card);
}

Carta Jogador::joga_carta(){
	int car=seleciona_carta();
	Carta c=_mao[car];
	_mao.erase(_mao.begin()+car);
	return c;
}

int Jogador::seleciona_carta(){
	int number, count=0;
	Carta::Naipe np;
	std::cin>>number;
	std::cin>>np;
	Carta card(number,np,);
	Carta aux=_mao[count];
	while(card!=*aux && count<_mao.size()){
		count++;
		aux=_mao[count];
	}
	if(count==_mao.size){
		return seleciona_carta();
	}
	return count;
}

} /* namespace p3 */
