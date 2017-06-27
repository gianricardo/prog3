/*
 * main.cpp
 *
 *  Created on: 19 de jun de 2017
 *      Author: lucas
 */

#include <iostream>
#include "paciencia.h"

using namespace p3;

int main(){

	Paciencia pac;
	std::string nome;

	std::cout << "Nome Jogador: ";
	std::cin >> nome;

	Estado_jogo::inicia_jogo(nome);

	do{

		pac.rodada();

	}while(pac.verifica_jogada());


	return 0;
}



