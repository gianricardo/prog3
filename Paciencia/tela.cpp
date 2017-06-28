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
	std::getline(std::cin, jogada);

	std::cout << "\n\n\n\n\n\n\n\n\n";

	return jogada;
}

void Tela::mostra_carta(Carta *c){

	Carta::Naipe np = c->naipe();
	std::string a;

	switch(np){

		case Carta::Naipe::Espadas:
			a = "Espadas";
			break;
		case Carta::Naipe::Copas:
			a = "Copas";
			break;
		case Carta::Naipe::Paus:
			a = "Paus";
			break;
		case Carta::Naipe::Ouros:
			a = "Ouros";
			break;
	}
	
	if(c->numero() > 0)
		std::cout << c->numero() << " " << a << " - " << c->mostra();

	else 
		std::cout << c->numero();
}

void Tela::pontuacao_tela(Estado_jogo *jogo){

	std::cout << jogo->pontuacao_jogador();

}

void Tela::nome_jogador(Estado_jogo *jogo){

	std::cout << jogo->nome_jogador();

}

void Tela::tela_jogo(Estado_jogo *jogo){

	int i;

	std::cout << "\n";
	Tela::nome_jogador(jogo);
	std::cout << "\t\t";
	Tela::pontuacao_tela(jogo);
	std::cout << std::endl;

	std::cout << "\n";
	
	std::cout << "(0) ";
	Tela::mostra_carta(jogo->_pega_monte_v(0));
	std::cout << "   |   ";
	std::cout << "(1) ";
	Tela::mostra_carta(jogo->_pega_monte_v(1));
	std::cout << "\t\t";

	for(i = 2; i <= 5; i++){
		
		std::cout << "(" << i << ") ";
		Tela::mostra_carta(jogo->_pega_monte_v(i));
		std::cout << "   |   ";
	}

	std::cout << "\n\n\n\n" << std::endl;

	for(i = 6; i <= 12; i++){

		std::cout << "(" << i << ") ";
		Tela::mostra_carta(jogo->_pega_monte_v(i));
		std::cout << "  |  ";
	}

	std::cout << "\n\n" << std::endl;

}


void Tela::vitoria(){

	std::cout << "\n\nVoce Ganhou!" << std::endl;
}

void Tela::derrota(){

	std::cout << "\n\nVoce Perdeu, Noob!" << std::endl;
}


} /* namespace p3 */
