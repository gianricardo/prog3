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

	std::string nome;

	std::cout << "Nome Jogador: ";
	std::cin >> nome;

	Paciencia pac(nome);

	do{

		pac.rodada();

	}while(pac.verifica_jogada());

	pac.fim();

	return 0;
}



