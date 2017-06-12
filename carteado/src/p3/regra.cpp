/*
 * regra.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#include "regra.h"

namespace p3 {

Regra::Regra(std::size_t numero_de_jogadores,
			 int cartas_jogadores,
			 int rodadas /* = -1 */,
			 int pontuacao_max /* = -1 */, 
			 int menor_pontuacao /* = -1 */,
			 int cartas_inicial /* = 52 */,
			 modo_fim fim /* = modo_fim::pontuacao */, 
			 condicao_vitoria vit /* = condicao_vitoria::maior_pontuacao */, 
			 condicao_derrota der /* = condicao_derrota::nenhuma */,
			 int auto_pontos_carta_mao /* = 0 */) : 
			 					_fim(fim), _vit(vit), _der(der), _pont_cartas_mao(auto_pontos_carta_mao) {
	
	_numero_de_jogadores = numero_de_jogadores;
	_cartas_inicial = cartas_inicial;
	_cartas_jogadores = cartas_jogadores;
	_rodadas = rodadas;
	_pontuacao_max = pontuacao_max;
	_menor_pontuacao = menor_pontuacao;
}

Regra::~Regra() {

}

std::size_t Regra::numero_de_jogadores() const {
	return _numero_de_jogadores;
}
int Regra::cartas_inicial() const {//retorna numero de cartas do monte
	return _cartas_inicial;
}
int Regra::cartas_jogadores() const { //retorna cartas iniciais por jogadores
	return  _cartas_jogadores;
}
int Regra::max_rodadas() const {//retorna numero maximo de rodadas
	return _rodadas;
}
int Regra::pontuacao_max() const {//retorna numero de pontos para termino
	return _pontuacao_max;
}

Regra::modo_fim Regra::fim() const {

	return _fim;
}

Regra::condicao_vitoria Regra::cond_vit() const {

	return _vit;
}

Regra::condicao_derrota Regra::cond_der() const {

	return _der;
}

int Regra::pontuacao_carta_mao() const {

	return _pont_cartas_mao;
}

} /* namespace p3 */
