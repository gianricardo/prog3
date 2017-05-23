/*
 * jogo.cpp
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#include "jogo.h"

namespace p3 {

Jogo::~Jogo() {}

std::size_t Jogo::numero_de_jogadores() const {
	return _regra->numero_de_jogadores();
}

int Jogo::cartas_inicial() const {
	return _regra->cartas_inicial();
}

int Jogo::cartas_jogadores() const {
	return _regra->cartas_jogadores();
}

int Jogo::max_rodadas() const {
	return _regra->rodadas();
}

int Jogo::pontuacao_max() const {
	return _regra->pontuacao_max();
}

void Jogo::reiniciar(){
}

void Jogo::fim_jogada(){

	verifica_vitoria();

	if(!_jogando) return;

	while(!_mesa.ver_jogador(++_jog_atual).esta_apto()){

		if(_jog_atual == numero_de_jogadores()){

			_jog_atual = 0;

			_rodada++;

			verifica_vitoria();
		}
	}
}

bool Jogo::jogando() const {

	return _jogando;
}

std::size_t Jogo::pos_jog() const {

	return _jog_atual;
}

std::string Jogo::nome_jog() const {

	return _mesa.ver_jogador(_jog_atual).nome();
}

std::vector<Carta> Jogo::ver_cartas_jog() const {

	return _mesa.ver_jogador(_jog_atual).mostra_mao();
}

int Jogo::pont_jog() const {

	return _mesa.ver_jogador(_jog_atual).pontuacao();
}

void Jogo::jog_ganha_pontos(int pontos){

	_mesa.jogador_soma_pontos(pontos, _jog_atual);
}

void Jogo::jog_perde_pontos(int pontos){

	jog_ganha_pontos(-pontos);
}

bool Jogo::move_carta_j(Carta carta, std::size_t j){

	return move_carta_jj(carta, jogador_atual, j);
}

bool Jogo::move_carta_m(std::size_t m, bool p_cima /* = true */, bool m_cima /* = true */){

	return move_carta_mm(0, m, p_cima, m_cima);
}

bool Jogo::move_carta_jj(Carta carta, std::size_t j1, std::size_t j2 /* = jogador_atual */){

	if(j1 == jogador_atual) j1 = _jog_atual;
	if(j2 == jogador_atual) j2 = _jog_atual;

	if(!carta.mostra()) carta.vira();

	if(_mesa.jogador_tira_carta(carta, j1)){

		_mesa.jogador_recebe_carta(carta, j2);

		return true;
	}

	return false;
}

bool Jogo::move_carta_jm(Carta carta, std::size_t j /* = jogador_atual */, std::size_t m /* = 0 */, bool m_cima /* = true */){

	if(j == jogador_atual) j = _jog_atual;

	if(!_mesa.jogador_tira_carta(carta, j)) return false;

	_coloca_monte(carta, m, m_cima);

	return true;
}

bool Jogo::move_carta_mj(std::size_t m /* = 0 */, std::size_t j /* =  jogador_atual */, bool m_cima /* = true */){

	if(_mesa.tamanho_monte(m) == 0) return 0;

	if(j == jogador_atual) j = _jog_atual;

	_mesa.jogador_recebe_carta(_pega_monte(m, m_cima), j);

	return true;
}

bool Jogo::move_carta_mm(std::size_t m1, std::size_t m2 /* = 0 */, bool m1_cima /* = true */, bool m2_cima /* = true */){

	if(_mesa.tamanho_monte(m1) == 0) return false;

	_coloca_monte(_pega_monte(m1, m1_cima), m2, m2_cima);

	return true;
}

void Jogo::novo_monte(){

	_mesa.novo_monte();
}

void Jogo::deleta_monte(std::size_t i){

	_mesa.deleta_monte(i);
}

void Jogo::verifica_vitoria() {

	if(!_jogando) return;

	verifica_derrota();

	if(_regra->cond_der() != Regra::condicao_derrota::nenhuma && numero_de_jogadores() != 1){

		verifica_jogador_unico();

		if(!_jogando) return;
	}

	if(_regra->fim() == Regra::modo_fim::zero_cartas) verifica_fim_zero_cartas();

	if(!_jogando) return;

}

void Jogo::verifica_derrota() {


}


void Jogo::verifica_fim_zero_cartas(){

	for(std::size_t i = 0; i < numero_de_jogadores(); i++){

		if(_mesa.ver_jogador(i).mostra_mao().size() == 0){

			declara_fim_de_jogo();
		}
	}
}

void Jogo::verifica_jogador_unico(){

	std::size_t jog_aptos = 0;
	std::size_t last = _jog_atual;

	for(std::size_t i = 0; i < _mesa.numero_jogadores(); i++){

		if(_mesa.ver_jogador(i).esta_apto()){
		
			jog_aptos++;

			last = i;
		}
	}

	if(jog_aptos > 1) return;

	declara_vencedor(last);
}

void Jogo::declara_fim_de_jogo(){

}

void Jogo::declara_vencedor(std::size_t j){

	_jog_atual = j;

	_jogando = false;
}

void Jogo::_coloca_monte(Carta c, std::size_t m, bool topo){

	if(topo) _mesa.coloca_topo(c, m);
	else _mesa.coloca_baixo(c, m);
}

Carta Jogo::_pega_monte(std::size_t m, bool topo){

	if(topo) return _mesa.pega_topo(m);
	else return _mesa.pega_baixo(m);
}

void Jogo::construct_players(){

	if(numero_de_jogadores() != _mesa.numero_jogadores()){

		std::cerr << "Jogo::Jogo -- Numero incorreto de nomes passado\n";

		while(numero_de_jogadores() > _mesa.numero_jogadores()) _mesa.add_jogador();
	}
}

} /* namespace p3 */




