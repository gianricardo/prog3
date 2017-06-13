/*
 * trunfo.cpp
 *
 *  Created on: 6 de jun de 2017
 *      Author: breno
 */

#include <iostream>
#include <vector>
#include "jogo.h"
#include "regra.h"
#include "cartatrunfo.h"

int main()
{
	//2 jogadores, 16 cartas cada, 32 cartas ao total. Restante irrelevante
	p3::Regra regra_trunfo(	2, 16, -1, -1, -1, 32,
							p3::Regra::modo_fim::padrao,
							p3::Regra::condicao_vitoria::maior_pontuacao,
							p3::Regra::condicao_derrota::zero_cartas);

	//Nomes dos jogadores
	std::string nome_jogador_1;
	std::string nome_jogador_2;

	std::cout << "Nome do jogador 1: ";
	std::cin >> nome_jogador_1;
	std::cout << "\nNome do jogador 2:";
	std::cin >> nome_jogador_2;

	std::vector<std::string> nomes;
	nomes.push_back(nome_jogador_1);
	nomes.push_back(nome_jogador_2);

	//Criando o jogo
	p3::JogoBasico<Carta_trunfo> jogo_basico(&regra_trunfo, nomes);

	return 0;
}
