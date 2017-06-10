/*
 * RegraTruco.cpp
 *
 *  Created on: 24 de mai de 2017
 *      Author: bruno
 */


#include "regratruco.h"

namespace p4{

Regra_Truco::Regra_Truco(std::size_t numero_de_jogadores,
		  int cartas_jogadores,
		  int rodadas,
		  int pontuacao_max,
		  int menor_pontuacao,
		  int cartas_inicial):p3::Regra(numero_de_jogadores,cartas_jogadores,rodadas,pontuacao_max,
				  menor_pontuacao,cartas_inicial){/*carta_ganhando(0,p3::Carta::Naipe::Paus,false)*/

	if(numero_de_jogadores != 4 && numero_de_jogadores != 2){
		throw std::invalid_argument("Numero de jogadores invalido");
	}
/*
	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<std::size_t> x(0,numero_de_jogadores);

	_valor_pontuacao = 1;
	_rodada = 0;
	_pos_rodada_comeca = x(g);
	_pos_turno_comeca = _pos_rodada_comeca;
	for(int i = 0; i < 3; i ++){
		_rodadas_ganhas[i] = -1;
	}
*/
}

Regra_Truco::~Regra_Truco(){
}
}
 /* namespace p4 */
