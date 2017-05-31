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
		  int cartas_inicial):p3::Regra(numero_de_jogadores,cartas_jogadores,rodadas,pontuacao_max,
				  cartas_inicial), _carta_ganhando(0,p3::Carta::Naipe::Paus,false){

	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<std::size_t> x(0,numero_de_jogadores);

	_truco = false;
	_valor_truco = 0;
	_valor_pontuacao = 1;
	_rodada = 0;
	_pos_rodada_comeca = x(g);
	_pos_turno_comeca = _pos_rodada_comeca;
	for(int i = 0; i < 3; i ++){
		_rodadas_ganhas[i] = -1;
	}
}

Regra_Truco::~Regra_Truco(){
}

void Regra_Truco::truco(p3::Jogador j1){
	if(_truco == false && j1.pontuacao() < 11){
		_truco = true;
	}
	if(_valor_truco < 12){
		_valor_truco += 3;
	}
	return;
}

bool Regra_Truco::truco(){
	return _truco;
}

int Regra_Truco::compara(std::size_t pos_jog,p3::Carta c1, p3::Carta c2,p3::Carta _vira){
	if(_vira.numero() == 10){
		return compara_vira_12(pos_jog,c1,c2);
	}
	else{
		if(c1.numero() == _vira.numero() + 1 && c2.numero() == _vira.numero() + 1){
			if(compara_naipe(pos_jog,c1,c2) == true){
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
			return compara_valor(pos_jog,c1,c2);
		}
	}
}

int Regra_Truco::valor_pontuacao(){
	if(_truco == true){
		return _valor_truco*_valor_pontuacao;
	}
	else{
		return _valor_pontuacao;
	}
}


std::size_t Regra_Truco::joga_turno(std::size_t j_posicao, int comparou){
	if(!fim_turno()){
		if(comparou != (int)Compara::Igual){
			_rodadas_ganhas[_rodada] = (j_posicao)%2;
			_rodada++;
		}
		else{
			_rodadas_ganhas[_rodada] = (int)Compara::Igual;
			_rodada++;
		}		_pos_rodada_comeca = j_posicao;
		return -1;
	}
	else{
		if(_truco == true){
			_truco = false;
		}
		if(_pos_turno_comeca == 4){
			_pos_turno_comeca = 0;
		}
		else{
			_pos_turno_comeca++;
		}
		return vencedor_turno();
	}
}

void Regra_Truco::carta_ganhando(p3::Carta n_carta){
	_carta_ganhando = n_carta;
}

p3::Carta Regra_Truco::carta_ganhando(){
	return _carta_ganhando;
}

int Regra_Truco::rodada(){
	return _rodada;
}

void Regra_Truco::pos_rodada_comeca(std::size_t n_posicao){
	_pos_rodada_comeca = n_posicao;
}

std::size_t Regra_Truco::pos_rodada_comeca(){
	return _pos_rodada_comeca;
}

std::size_t Regra_Truco::pos_turno_comeca(){
	return _pos_turno_comeca;
}
//Funcoes Privadas:

bool Regra_Truco::compara_naipe(std::size_t pos_jog,p3::Carta c1,p3::Carta c2){
	if(c1.naipe() == p3::Carta::Naipe::Paus){
		_pos_rodada_comeca = pos_jog;
		_carta_ganhando = c1;
		return true;
	}
	else if(c1.naipe() == p3::Carta::Naipe::Copas){
		if(c2.naipe() == p3::Carta::Naipe::Paus){
			_carta_ganhando = c2;
			return false;
		}
		else{
			_pos_rodada_comeca = pos_jog;
			_carta_ganhando = c1;
			return true;
		}
	}
	else if(c1.naipe() == p3::Carta::Naipe::Espadas){
		if(c2.naipe() == p3::Carta::Naipe::Copas || c2.naipe() ==p3::Carta::Naipe::Paus){
			_carta_ganhando = c2;
			return false;
		}
		else{
			_pos_rodada_comeca = pos_jog;
			_carta_ganhando = c1;
			return true;
		}
	}
	else{
		return false;
	}
}

int Regra_Truco::compara_vira_12(std::size_t pos_jog,p3::Carta c1,p3::Carta c2){
	if(c1.numero() == 1 && c2.numero() == 1){
		if(compara_naipe(pos_jog,c1,c2) == true){
			_pos_rodada_comeca = pos_jog;
			return (int)(Compara::Maior);
		}
		else{
			return (int)(Compara::Menor);
		}
	}
	else if(c1.numero() == 1){
		_pos_rodada_comeca = pos_jog;
		_carta_ganhando = c1;
		return (int)(Compara::Maior);
	}
	else{
		_carta_ganhando = c2;
		return (int)(Compara::Menor);
	}
}

int Regra_Truco::compara_valor(std::size_t pos_jog,p3::Carta c1 , p3::Carta c2){
	if((c1.numero() == 3 || c1.numero() == 2 || c1.numero() == 1) &&
			(c2.numero() == 3 || c2.numero() == 2 || c2.numero() == 1)){
		if(c1.numero() > c2.numero()){
			_pos_rodada_comeca = pos_jog;
			_carta_ganhando = c1;
			return (int)(Compara::Maior);
		}
		else if(c1.numero() == c2.numero()){
			return (int)(Compara::Igual);
		}
		else{
			_carta_ganhando = c2;
			return (int)(Compara::Menor);
		}
	}
	else if(c1.numero() == 3 || c1.numero() == 2 || c1.numero() == 1){
		if(c2.numero() != 3 && c2.numero() != 2 && c2.numero() != 1){
			_pos_rodada_comeca = pos_jog;
			_carta_ganhando = c1;
			return (int)(Compara::Maior);
		}
	}
	else if(c2.numero() == 3 || c2.numero() == 2 || c2.numero() == 1){
		if(c1.numero() != 3 && c1.numero() != 2 && c1.numero() != 1){
			_carta_ganhando = c2;
			return (int)(Compara::Menor);
		}
	}
	else{
		if(c1.numero() > c2.numero()){
			_pos_rodada_comeca = pos_jog;
			_carta_ganhando = c1;
			return (int)(Compara::Maior);
		}
		else if(c1.numero() == c2.numero()){
			return (int)(Compara::Igual);
		}
		else{
			_carta_ganhando = c2;
			return (int)(Compara::Menor);
		}
	}
	return -1;
}

bool Regra_Truco::fim_turno(){
	int cont1 = 0, cont2 = 0,cont3 = 0;
	for(int i = 0; i < 3; i++){
		if(_rodadas_ganhas[i] == 0){
			cont1 ++;
		}
		else if(_rodadas_ganhas[i] == 1){
			cont2 ++;
		}
		else if(_rodadas_ganhas[i] == 2){
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

std::size_t Regra_Truco::vencedor_turno(){
	if(_rodadas_ganhas[0] == (int)Compara::Igual && _rodadas_ganhas[1] != _rodadas_ganhas[0]){
		for(int i; i < _rodada; i++){
			_rodadas_ganhas[i] = -1;
		}
		_rodada = 0;
		return _rodadas_ganhas[1];
	}
	else{
		int cont1 = 0,cont2 = 0,cont3 = 0;
		for(int i = 0; i < _rodada ;i++){
			if(_rodadas_ganhas[i] == 0){
				cont1 ++;
			}
			else if(_rodadas_ganhas[i] == 1){
				cont2 ++;
			}
			else if(_rodadas_ganhas[i] == 2){
				cont3 ++;
			}
		}
		if(cont1 > cont2){
			for(int i; i < _rodada; i++){
				_rodadas_ganhas[i] = -1;
			}
			_rodada = 0;
			return 0;
		}
		else if(cont2 > cont1){
			for(int i; i < _rodada; i++){
				_rodadas_ganhas[i] = -1;
			}
			_rodada = 0;
			return 1;
		}
		else if(cont3 == 3){
			for(int i; i < _rodada; i++){
				_rodadas_ganhas[i] = -1;
			}
			_rodada = 0;
			return 2;
		}
		else if(cont1 == cont2){
			for(int i; i < _rodada; i++){
				_rodadas_ganhas[i] = -1;
			}
			_rodada = 0;
			return _rodadas_ganhas[0];
		}
	}
	return -1;
}

}
 /* namespace p4 */
