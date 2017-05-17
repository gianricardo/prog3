/*
 * jogo.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#include "jogo.h"

namespace p3 {

Jogo::Jogo(std::unique_ptr<Regra> regra):
	_regra{regra} {
}

Jogo::~Jogo() {}

void Jogo::distribuir(unsigned int qtd_cartas, bool cima){
	_mesa.distribuir(qtd_cartas, cima);
}

void Jogo::add_jogador(std::string name = ""){
	_mesa.add_jogador(name);
}

void Jogo::rem_jogador(std::size_t pos){
	_mesa.rem_jogador(pos);
}

Carta Jogo::pega_topo(std::size_t monte = 0){
	_mesa.pega_topo(monte);
}

Carta Jogo::pega_baixo(std::size_t monte = 0){
	_mesa.pega_baixo(monte);
}

int Jogo::numero_de_jogadores(){
	return _regra->numero_de_jogadores();
}

int Jogo::cartas_inicial(){
	return _regra->cartas_inicial();
}

int Jogo::cartas_jogadores(){
	return _regra->cartas_jogadores();
}

int Jogo::montes(){
	return _regra->montes();
}

int Jogo::rodadas(){
	return _regra->rodadas();
}

int Jogo::pontuacao_max(){
	return _regra->pontuacao_max();
}

} /* namespace p3 */
