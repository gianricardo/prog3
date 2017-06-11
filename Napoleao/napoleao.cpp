/*
 * napoleao.cpp
 *
 *  Created on: 6 de jun de 2017
 *      Author: vitorrussi
 */
#include <iostream>
#include "napoleao.h"

#define MAO 5


Napoleao::Napoleao() {
	std::cout << "Inicio do construtor Napoleao" << std::endl;

	int jogadores, rodadas;
	std::cout << "NAPOLEAO: Insira o numero de jogadores: ";
	std::cin >> jogadores;
	std::cout << "NAPOLEAO: Insira o numero de rodadas: ";
	std::cin >> rodadas;

	Regra *Rules = new Regra(jogadores,MAO,rodadas,rodadas*10,0,52, (Regra::modo_fim::rodadas));

	std::vector<std::string> nomes(jogadores);
	for(auto &i:nomes) {
		std::cout << "NAPOLEAO: Insira o nome do jogador: ";
		std::cin >> i;
	}
	std::cout << "NAPOLEAO: NUMERO DE JOGADORES = " << nomes.size() << std::endl;
	for(auto &i:nomes) {
			std::cout << "\tNAPOLEAO: NOME = " << i << std::endl;
	}
	_jogo = new Jogo(Rules, nomes);
	std::cout << "Fim do construtor Napoleao" << std::endl;
}

Napoleao::~Napoleao() {
}


void Napoleao::inicia_jogo(){
	inicia_rodada();


}

void Napoleao::inicia_rodada() {


}

// Incrementa 1 na quantidade do turno atual. Se chegar ao limite( no caso, 5), retorna 1, dizendo que acabou aquele turno
//, senao retorna 0
bool Napoleao::roda_turno(){
	_turno++;
	if(_turno == 5) {
		_turno = 1;
		return 1;
	}
	return 0;
}

// Define qual o naipe de trunfo da rodada atual
void Napoleao::define_trunfo(Carta::Naipe trunfo) {
	_trunfo = trunfo;
}




