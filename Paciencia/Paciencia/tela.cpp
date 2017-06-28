/*
 * tela.cpp
 *
 *  Created on: 19 de jun de 2017
 *      Author: lucas
 */

#include "tela.h"

namespace p3 {


std::string Tela::mostra_carta(Estado_jogo * jogo, int i){

	Carta *c = jogo->_pega_monte_v(i);

	Carta::Naipe np = c->naipe();
	std::string a, b;
	b = std::to_string(c->numero());

	switch(np){

		case Carta::Naipe::Espadas:
			a = "0";
			break;
		case Carta::Naipe::Copas:
			a = "1";
			break;
		case Carta::Naipe::Paus:
			a = "2";
			break;
		case Carta::Naipe::Ouros:
			a = "3";
			break;
	}
	
    if(c->numero() > 0){

		if(!(c->mostra()))
			return "back";	

		return a + b;
	}
	else 
		return "vazio";
}

void Tela::vitoria(){

	std::cout << "\n\nVoce Ganhou!" << std::endl;
}

void Tela::derrota(){

	std::cout << "\n\nVoce Perdeu, Noob!" << std::endl;
}


} /* namespace p3 */
