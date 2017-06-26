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
				  menor_pontuacao,cartas_inicial){

	if(numero_de_jogadores != 4 && numero_de_jogadores != 2){
		throw std::invalid_argument("Numero de jogadores invalido");
	}

	for(auto i = 0; i < max_rodadas(); i++){
		_jogadores_ganharam.push_back(3);
	}

	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<std::size_t> x(0,numero_de_jogadores -1);

	_jogador_comeca_turno  = x(g);
	_jogador_comeca = _jogador_comeca_turno;
	if(_jogador_comeca == 0){
		_jogador_termina = numero_de_jogadores;
	}
	else{
		_jogador_termina = _jogador_comeca;
	}
}

Regra_Truco::~Regra_Truco(){
}


int Regra_Truco::compara(p3::Carta c1, p3::Carta c2, p3::Carta _vira){
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

bool Regra_Truco::checa_fim_rodada(std::size_t pos){
	if(pos == _jogador_termina){
		return true;
	}
	else{
		return false;
	}
}

std::size_t  Regra_Truco::jogador_ganhou_turno(){
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

void Regra_Truco::recomeca_turno(){
	for(int i = 0; i < max_rodadas(); i++){
		_jogadores_ganharam[i] = 3;
	}
}

void Regra_Truco::jogador_ganhou_rodada(std::size_t jogador,std::size_t rodada){
	if(jogador >= _numero_de_jogadores){
		if(rodada == 3){
			_jogadores_ganharam[rodada - 1] = 2;
		}
		_jogadores_ganharam[rodada] = 2;
	}
	else{
		if(rodada == 3){
			_jogadores_ganharam[rodada -1] = jogador %2;
		}
		_jogadores_ganharam[rodada] = jogador % 2;
		return;
	}
}

bool Regra_Truco::fim_turno(std::size_t rodada, std::size_t ganhou){
	if(ganhou != 3 || rodada == 3){
		return true;
	}
	else{
		return false;
	}
}

int Regra_Truco::valor_pontuacao(bool cond,int valor){
	if(cond == true){
		return valor*1;
	}
	else{
		return 1;
	}
}


std::size_t Regra_Truco::jogador_comeca(){
	return _jogador_comeca;
}

void Regra_Truco::jogador_comeca(std::size_t n_pos){
	_jogador_comeca = n_pos;
}

std::size_t Regra_Truco::jogador_termina(){
	return _jogador_termina;
}

void Regra_Truco::jogador_termina(std::size_t n_pos){
	_jogador_termina = n_pos;
}

std::size_t Regra_Truco::jogador_comeca_turno(){
	return _jogador_comeca_turno;
}

void Regra_Truco::jogador_comeca_turno(std::size_t n_pos){
	_jogador_comeca_turno = n_pos;
}

//Funcoes Privadas

bool Regra_Truco::compara_naipe(p3::Carta c1,p3::Carta c2){
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

int Regra_Truco::compara_vira_12(p3::Carta c1,p3::Carta c2){
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

int Regra_Truco::compara_valor(p3::Carta c1 , p3::Carta c2){
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


}
 /* namespace p4 */
