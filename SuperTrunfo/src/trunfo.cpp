/*
 * trunfo.cpp
 *
 *  Created on: 6 de jun de 2017
 *      Author: breno
 */

#include <iostream>
#include <vector>
#include "jogotrunfo.h"
#include "jogada.h"
#include "regra.h"
#include "cartatrunfo.h"
#include "inteligenciaartificial.h"

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
	std::cout << "Nome do jogador 2: ";
	std::cin >> nome_jogador_2;

	std::vector<std::string> nomes;
	nomes.push_back(nome_jogador_1);
	nomes.push_back(nome_jogador_2);

	//Criando o jogo
	Jogo_trunfo jogo(&regra_trunfo, nomes);

	Jogada jogada(Jogada::Atributos::INVALIDA);

	while(jogo.jogando())
	{
		if(jogo.posicao_jogador_atual() == 1)
		{
			jogada = Inteligencia_artificial::escolhe_jogada();
		}
		else {
			jogada = jogo.recebe_jogada();
		}

		jogo.realiza_jogada(jogada);

		jogo.fim_jogada();
	}

	std::cout << jogo.nome_jogador_atual() << " venceu o jogo!\n";

	return 0;
}
