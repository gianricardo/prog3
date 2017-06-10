/*
 * jogo_truco.cpp
 *
 *  Created on: 30 de mai de 2017
 *      Author: bruno
 */

#include "jogo_truco.h"

namespace p4 {

Jogo_Truco::Jogo_Truco(p3::Regra *regra, std::vector<std::string> nomes):p3::Jogo(regra, nomes){
	_truco = false;
	_valor_truco = 0;

	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<std::size_t> x(0,numero_de_jogadores());

	_jogador_comeca_turno  = x(g);
	_jogador_comeca = _jogador_comeca_turno;
	_jog_atual = _jogador_comeca;

	if(_jogador_comeca == 0){
		_jogador_termina = numero_de_jogadores();
	}
	else{
		_jogador_termina = _jogador_comeca;
	}

	_rodada = 0;
	for(auto i = 0; i < max_rodadas(); i++){
		_jogadores_ganharam.push_back(numero_de_jogadores());
	}
}

Jogo_Truco::~Jogo_Truco() {
	// TODO Auto-generated destructor stub
}

bool Jogo_Truco::checa_fim_rodada(){
	if(_jog_atual == _jogador_termina){
		return true;
	}

	else{
		return false;
	}
}

void Jogo_Truco::fim_rodada(std::size_t _jogador_ganhou){
	if(_jogador_ganhou == numero_de_jogadores()){
		_jogador_comeca = _jogador_comeca_turno;
		_jog_atual = _jogador_comeca;
	}
	else{
		_jogador_comeca = _jogador_ganhou;
		_jog_atual = _jogador_comeca;
	}

	if(_jogador_comeca == 0){
		_jogador_termina = numero_de_jogadores();
	}
	else{
		_jogador_termina = _jogador_comeca;
	}

	for(auto i = 0; i < (int)mostra_monte(2).size() ; i++){
		move_carta_mm(2,0,true,true);
	}

	_rodada++;
}


void Jogo_Truco::truco(std::size_t j1){
	if(pontuacao_jogador_atual() == 11){
		_truco = false;
	}
	else if(_truco == false){
		_valor_truco = 3;
		_truco = true;
	}
	else if(_truco == true){
		if(_valor_truco == 12){
			_valor_truco = 12;
		}
		else{
			_valor_truco += 3;
		}
	}
}

bool Jogo_Truco::truco(){
	return _truco;
}

int Jogo_Truco::valor_truco(){
	return _valor_truco;
}

int Jogo_Truco::valor_pontuacao(){
	if(_truco == false){
		return 1;
	}
	else{
		return _valor_truco;
	}
}

std::size_t Jogo_Truco::jogador_comeca(){
	return _jogador_comeca;
}

std::vector<p3::Carta> Jogo_Truco::mostra_mao_jogador(std::size_t _jogador){
	if(_jogador > numero_de_jogadores()){
		throw std::invalid_argument("Invalid Argument");
	}
	else{
		return _mesa.ver_jogador(_jogador).mostra_mao();
	}
}



int Jogo_Truco::compara(p3::Carta c1, p3::Carta c2,p3::Carta _vira){
	if(_vira.numero() == 10){
		return compara_vira_12(c1,c2);
	}
	else{
		if(c1.numero() == _vira.numero() + 1 && c2.numero() == _vira.numero() + 1){
			if(compara_naipe(c1,c2) == true){
				return (int)(Compara::Maior);
			}
			else{
				return (int)(Compara::Menor);
			}
		}
		else if(c1.numero() == _vira.numero() + 1){
			return (int)(Compara::Maior);
		}
		else if(c2.numero() == _vira.numero() + 1){
			return (int)(Compara::Menor);
		}
		else{
			return compara_valor(c1,c2);
		}
	}
}

void Jogo_Truco::jogador_ganhou_rodada(std::size_t _jogador){
	if(_jogador >= numero_de_jogadores()){
		_jogadores_ganharam[_rodada] = 2;
	}
	else{
		_jogadores_ganharam[_rodada] = _jogador % 2;
		return;
	}
}

bool Jogo_Truco::fim_turno(){
	int cont1 = 0, cont2 = 0,cont3 = 0;
	for(int i = 0; i <	(int)_rodada; i++){
		if(_jogadores_ganharam[i] == 0){
			cont1 ++;
		}
		else if(_jogadores_ganharam[i] == 1){
			cont2 ++;
		}
		else if(_jogadores_ganharam[i] == 2){
			cont3 ++;
		}
	}
	if (_rodada == 3 || cont1 == 2 || cont2 == 2 || (cont3 == 1 && (cont2 == 1 || cont1 == 1))){
		return true;
	}
	else{
		return false;
	}

}

std::size_t Jogo_Truco::jogador_ganhou_turno(){
	if(_jogadores_ganharam[0] == 2 && _jogadores_ganharam[1] != _jogadores_ganharam[0]){
		std::size_t vencedor = _jogadores_ganharam[1];
		for(int i; i < (int)_rodada; i++){
			_jogadores_ganharam[i] = 3;
		}
		_rodada = 0;
		return vencedor;
	}
	else{
		int cont1 = 0,cont2 = 0,cont3 = 0;
		for(int i = 0; i < (int)_rodada ;i++){
			if(_jogadores_ganharam[i] == 0){
				cont1 ++;
			}
			else if(_jogadores_ganharam[i] == 1){
				cont2 ++;
			}
			else if(_jogadores_ganharam[i] == 2){
				cont3 ++;
			}
		}
		if(cont1 > cont2){
			for(int i; i <(int)_rodada; i++){
				_jogadores_ganharam[i] = 3;
			}
			_rodada = 0;
			return 0;
		}
		else if(cont2 > cont1){
			for(int i; i < (int)_rodada; i++){
				_jogadores_ganharam[i] = 3;
			}
			_rodada = 0;
			return 1;
		}
		else if(cont3 == 3){
			for(int i; i < (int)_rodada; i++){
				_jogadores_ganharam[i] = 3;
			}
			_rodada = 0;
			return 2;
		}
		else if(cont1 == cont2){
			for(int i; i <(int)_rodada; i++){
				_jogadores_ganharam[i] = 3;
			}
			_rodada = 0;
			return _jogadores_ganharam[0];
		}
	}
	return 3;
}

void Jogo_Truco::comeca_novo_turno(){
	_truco = false;
	_rodada = 0;

	_jogador_comeca_turno++;
	if(_jogador_comeca_turno == numero_de_jogadores()){
		_jogador_comeca_turno = 0;
	}

	_jogador_comeca = _jogador_comeca_turno;
	_jog_atual = _jogador_comeca_turno;

	if(_jogador_comeca == 0){
		_jogador_termina = numero_de_jogadores();
	}
	else{
		_jogador_termina = _jogador_comeca;
	}



	for(auto i = 0; i < max_rodadas(); i++){
		_jogadores_ganharam[i] = 4;
	}

	for(std::size_t pos_jogador=0; pos_jogador < numero_de_jogadores(); pos_jogador++)
	{
		for(std::size_t pos_carta = 0; pos_carta < mostra_mao_jogador(pos_jogador).size(); pos_carta++){
			_mesa.jogador_tira_carta(mostra_mao_jogador(pos_jogador)[0], pos_jogador);
		}
	}

	move_carta_mm(1,0,true,true);
	for(auto i = 0; i < (int)mostra_monte(2).size() ; i++){
		move_carta_mm(2,0,true,true);
	}
	_mesa.monte_mesa().embaralhar();

	if(_mesa.n_montes() > 1){
		for(std::size_t pos_monte = 1; pos_monte < _mesa.n_montes(); pos_monte++){
			_mesa.deleta_monte(pos_monte);
		}
	}

	_mesa.distribuir(cartas_jogadores());

}


void Jogo_Truco::incrementa_jog_atual(){
	if(_jogador_comeca == 0){
		if(_jog_atual == numero_de_jogadores()){
			_jog_atual = 0;
		}
		else{
			_jog_atual ++;
		}
	}
	else{
		if(_jog_atual == numero_de_jogadores() -1){
			_jog_atual = 0;
			return;
		}
		else{
			_jog_atual++;
		}
	}
}


int Jogo_Truco::pontuacao(std::size_t _jogador){
	if(_jogador > numero_de_jogadores()){
		throw std::invalid_argument("Invalid Argument");
	}
	else{
		return _mesa.ver_jogador(_jogador).pontuacao();
	}
}

void Jogo_Truco::jogador_soma_pontos(std::size_t _jogador,int pontos){
	if(numero_de_jogadores() == 4){
		if(_jogador  == 0){
			_mesa.jogador_soma_pontos(pontos, 0);
			_mesa.jogador_soma_pontos(pontos, _jogador + 2);
		}
		else if(_jogador  == 1){
			_mesa.jogador_soma_pontos(pontos, _jogador);
			_mesa.jogador_soma_pontos(pontos, _jogador +2);
		}
	}
	else{
		_mesa.jogador_soma_pontos(pontos, _jogador);
	}
}

bool Jogo_Truco::verifica_truco(std::size_t _jogador_trucou){
	std::size_t posicao = _jogador_trucou;
	int aceitou_truco = 0;
	int cartas_altas = 0;

	posicao++;
	while(posicao != _jogador_trucou){
		cartas_altas = 0;
		if(posicao != posicao_jogador_atual() + 2){
			for(int i = 0; i < (int)(mostra_mao_jogador(posicao)).size(); i++){
				if((mostra_mao_jogador(posicao))[i].numero() >= 9 ||
					(mostra_mao_jogador(posicao))[i].numero() == (mostra_monte(1))[i].second.numero() + 1){

					cartas_altas++;
				}
			}
		}
		if(cartas_altas < 2){
			aceitou_truco++;
		}
		if(posicao == numero_de_jogadores() - 1){
			posicao = 0;
		}
		else{
			posicao++;
		}
	}

	if(aceitou_truco == 2){
		return true;
	}
	else{
		return false;
	}
}


//Funcoes privadas

bool Jogo_Truco::compara_naipe(p3::Carta c1,p3::Carta c2){
	if(c1.naipe() == p3::Carta::Naipe::Paus){
		return true;
	}
	else if(c1.naipe() == p3::Carta::Naipe::Copas){
		if(c2.naipe() == p3::Carta::Naipe::Paus){
			return false;
		}
		else{
			return true;
		}
	}
	else if(c1.naipe() == p3::Carta::Naipe::Espadas){
		if(c2.naipe() == p3::Carta::Naipe::Copas || c2.naipe() ==p3::Carta::Naipe::Paus){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}
}

int Jogo_Truco::compara_vira_12(p3::Carta c1,p3::Carta c2){
	if(c1.numero() == 1 && c2.numero() == 1){
		if(compara_naipe(c1,c2) == true){
			return (int)(Compara::Maior);
		}
		else{
			return (int)(Compara::Menor);
		}
	}
	else if(c1.numero() == 1 && c2.numero() != 1){
		return (int)(Compara::Maior);
	}
	else if(c2.numero() == 1 && c1.numero() != 1){
		return (int)(Compara::Menor);
	}
	else{
		return compara_valor(c1,c2);
	}
}

int Jogo_Truco::compara_valor(p3::Carta c1 , p3::Carta c2){
	if((c1.numero() == 3 || c1.numero() == 2 || c1.numero() == 1) &&
			(c2.numero() == 3 || c2.numero() == 2 || c2.numero() == 1)){
		if(c1.numero() > c2.numero()){
			return (int)(Compara::Maior);
		}
		else if(c1.numero() == c2.numero()){
			return (int)(Compara::Igual);
		}
		else{
			return (int)(Compara::Menor);
		}
	}
	else if(c1.numero() == 3 || c1.numero() == 2 || c1.numero() == 1){
		if(c2.numero() != 3 && c2.numero() != 2 && c2.numero() != 1){
			return (int)(Compara::Maior);
		}
	}
	else if(c2.numero() == 3 || c2.numero() == 2 || c2.numero() == 1){
		if(c1.numero() != 3 && c1.numero() != 2 && c1.numero() != 1){
			return (int)(Compara::Menor);
		}
	}
	else{
		if(c1.numero() > c2.numero()){
			return (int)(Compara::Maior);
		}
		else if(c1.numero() == c2.numero()){
			return (int)(Compara::Igual);
		}
		else{
			return (int)(Compara::Menor);
		}
	}
	return -1;
}



} /* namespace p4 */