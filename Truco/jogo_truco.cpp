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
	std::uniform_int_distribution<std::size_t> x(0,numero_de_jogadores() -1);

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
	for(auto i = 0; i < _regra->max_rodadas(); i++){
		_jogadores_ganharam.push_back(3);
	}
}

Jogo_Truco::~Jogo_Truco() {
}

void Jogo_Truco::fim_jogo(){
	verifica_fim_de_jogo();
	return;
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

	if(!mostra_monte(2).empty()){
		std::size_t _tamanho_monte = mostra_monte(2).size();

		for(std::size_t i = 0; i < _tamanho_monte ; i++){
			move_carta_mm(2,0,true,true);
		}
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
		if(_rodada == 3){
			_jogadores_ganharam[_rodada - 1] = 2;
		}
		_jogadores_ganharam[_rodada] = 2;
	}
	else{
		if(_rodada == 3){
			_jogadores_ganharam[_rodada -1] = _jogador %2;
		}
		_jogadores_ganharam[_rodada] = _jogador % 2;
		return;
	}
}

bool Jogo_Truco::fim_turno(){
	if (jogador_ganhou_turno() != 3||_rodada == 3 ){
		return true;
	}
	else{
		return false;
	}

}

std::size_t Jogo_Truco::jogador_ganhou_turno(){
	std::size_t vencedor = 3;
	int cont1 = 0,cont2 = 0,cont3 = 0;

	if(_jogadores_ganharam[0] == 2 && _jogadores_ganharam[1] != 2 && _jogadores_ganharam[1] != 3){
		vencedor = _jogadores_ganharam[1];

	}
	else if(_jogadores_ganharam[0] == 2 && _jogadores_ganharam[1] == 2 && _jogadores_ganharam[2]!= 2 &&
						_jogadores_ganharam[2] != 3){

		vencedor = _jogadores_ganharam[2];
	}
	else{
		for(int i = 0; i < (int)_jogadores_ganharam.size();i++){
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
		if(cont1 >= 2){
			vencedor = 0;
		}
		else if(cont2 >= 2){
			vencedor =  1;
		}
		else if((_jogadores_ganharam[1] == 2|| _jogadores_ganharam[2] ==2) && cont1 == cont2 && cont1 == 1){
			vencedor = _jogadores_ganharam[0];
		}
		else if(cont3 == 3){
			vencedor=  2;
		}
	}
	return vencedor;
}

void Jogo_Truco::comeca_novo_turno(){
	_truco = false;
	_valor_truco = 0;
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
		_jogadores_ganharam[i] = 3;
	}

	for(std::size_t pos_jogador=0; pos_jogador < numero_de_jogadores(); pos_jogador++)
	{
		esvazia_mao(pos_jogador);
	}

	move_carta_mm(1,0,true,true);
	std::size_t _tamanho_monte = mostra_monte(2).size();

	for(std::size_t i = 0; i < _tamanho_monte ; i++){
		move_carta_mm(2,0,true,true);
	}

	if(jogando()){

		restaurar_monte_inicial();
		embaralhar_monte_principal();
		_mesa.distribuir(cartas_jogadores());

		move_carta_mm(0,1,true,true);
		vira_carta_monte(1,true);
	}

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

void Jogo_Truco::mao_de_11(){
	if(_jog_atual == 0){
		for(int i = 0; i < cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(_jog_atual)[0],_jog_atual, _jog_atual + 2);
		}
		for(int i = 0; i < cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(_jog_atual + 2)[0], _jog_atual + 2, _jog_atual);
		}
	}
	else if(_jog_atual == 1){
		for(int i = 0; i < cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(_jog_atual)[0],_jog_atual, _jog_atual + 2);
		}
		for(int i = 0; i < cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(_jog_atual + 2)[0], _jog_atual + 2, _jog_atual);
		}
	}
	else if(_jog_atual == 2){
		for(int i = 0; i < cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(_jog_atual)[0],_jog_atual, 0);
		}
		for(int i = 0; i < cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(0)[0], 0, _jog_atual);
		}
	}
	else if(_jog_atual == 3){
		for(int i = 0; i < cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(_jog_atual)[0],_jog_atual, 1);
		}
		for(int i = 0; i <cartas_jogadores(); i++){
			move_carta_jj(mostra_mao_jogador(1)[0], 1, _jog_atual);
		}
	}
}


void Jogo_Truco::jogador_soma_pontos(std::size_t _jogador,int pontos){
	if(numero_de_jogadores() == 4){
		if(_jogador  == 0){
			_mesa.jogador_soma_pontos(pontos, 0);
			_mesa.jogador_soma_pontos(pontos, 2);
		}
		else if(_jogador  == 1){
			_mesa.jogador_soma_pontos(pontos, 1);
			_mesa.jogador_soma_pontos(pontos, 3);
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

	if (posicao == numero_de_jogadores() -1){
		posicao =0;
	}
	posicao++;
	while(posicao != _jogador_trucou){
		cartas_altas = 0;
		if(posicao != posicao_jogador_atual() + 2){
			for(int i = 0; i < (int)(mostra_mao_jogador(posicao)).size(); i++){
				if((mostra_mao_jogador(posicao))[i].numero() <= 3 ||
					(mostra_mao_jogador(posicao))[i].numero() == (mostra_monte(1))[0].second.numero() + 1){

					cartas_altas++;
				}
			}
		}
		if(cartas_altas >= 1){
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

int Jogo_Truco::checa_mao_de_11(){
	int _mao1 = 0;
	int _mao2 = 0;
	std::size_t _jogador;
	for(std::size_t pos = 0; pos < numero_de_jogadores(); pos++){
		if(pontuacao(pos) == 11){
			if(pos == 0 || pos == 2){
				_jogador = 0;
				_mao1 ++;
			}
			else if(pos == 1 || pos == 3){
				_jogador = 1;
				_mao2 ++;
			}
		}
	}
	if(_mao1 >= 1 && _mao2 >= 1){
		return 2;
	}
	else if(_mao1 >=1 || _mao2 >= 1){
		return _jogador;
	}
	return -1;
}

bool Jogo_Truco::ia_aceita_mao_11(){
	int cartas_altas = 0;
	for(std::size_t i = 0 ; i < mostra_mao_jogador(1).size(); i++){
		if(mostra_mao_jogador(1)[i].numero() <= 3 ||
				mostra_mao_jogador(1)[i].numero() == (mostra_monte(1)[0].second).numero() +1){
			cartas_altas ++;
		}
	}
	for(std::size_t i = 0 ; i < mostra_mao_jogador(3).size(); i++){
		if(mostra_mao_jogador(3)[i].numero() <= 3 ||
				mostra_mao_jogador(3)[i].numero() == (mostra_monte(1)[0].second).numero() +1){
			cartas_altas ++;
		}
	}
	if(cartas_altas == 3){
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
	if((c1.numero() <=3) &&
			(c2.numero() <= 3)){
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
	else if(c1.numero() <= 3){
		if(c2.numero() > 3){
			return (int)(Compara::Maior);
		}
	}
	else if(c2.numero() <= 3){
		if(c1.numero() > 3){
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
