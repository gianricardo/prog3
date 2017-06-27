/*
 * tela.cpp
 *
 *  Created on: 19 de jun de 2017
 *      Author: lucas
 */

#include "tela.h"

namespace p3 {


void Tela::jogada_invalida(){

	std::cout << "Jogada Invalida!" << std::endl;

}

std::string Tela::jogada_atual(){

	std::string jogada;

	std::cout << "Jogada :";
	std::cin >> jogada;

	return jogada;
}

void Tela::mostra_carta(Carta *c){

	std::cout << c->numero() << " " << c->Naipe() << "\n";

}

void Tela::pontuacao_tela(Estado_jogo *jogo){

	std::cout << jogo->pontuacao_jogador_atual();

}

void Tela::nome_jogador(Estado_jogo *jogo){

	std::cout << jogo->nome_jogador_atual();

}

void Tela::tela_jogo(Estado_jogo *jogo){

	int i;

	std::cout << Tela::nome_jogador(jogo) << "\t\t" << Tela::pontuacao_tela(jogo) << std::endl;

	std::cout << "\n\n" << Tela::mostra_carta(jogo->_pega_monte(0)) << "\t" << Tela::mostra_carta(jogo->_pega_monte(1)) << "\t\t";

	for(i = 2; i <= 5; i++)
		std::cout << Tela::mostra_carta(jogo->_pega_monte(i)) << "\t";

	std::cout << "\n\n\n\n" << std::endl;

	for(i = 6; i <= 12; i++)
		std::cout << Tela::mostra_carta(jogo->_pega_monte(i)) << "\t";

	std::cout << "\n\n" << std::endl;

}

} /* namespace p3 */
