/*
 * main.cpp

 *
 *  Created on: 24 de mai de 2017
 *      Author: bruno
 */

#include <vector>
#include "jogo_truco.h"
#include "mesa.h"
#include "baralho.h"
#include "regratruco.h"

int main(){
	std::string nome;
	std::size_t numero_jogadores = 0;

	std::cout << "Escolha o numero de jogadores (2/4): ";
	std::cin >> numero_jogadores;

	std::vector<std::string> _jogadores;

	std::cout << "Escolha o nome do seu jogador: ";
	std::cin >> nome;

	_jogadores.push_back(nome);
	switch(numero_jogadores){
	case 2:
		_jogadores.push_back("Computer");
		break;
	case 4:
		_jogadores.push_back("Computer1");
		_jogadores.push_back("Computer2");
		_jogadores.push_back("Computer3");
		break;
	default:
		break;
	}

	p4::Regra_Truco *r1_ptr = new p4::Regra_Truco(numero_jogadores,3,3,12,0,40);
	p4::Jogo_Truco j1(r1_ptr,_jogadores);
	j1.jogar();

	return 0;
}
