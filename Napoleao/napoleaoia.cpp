/*
 * napoleaoia.cpp
 *
 *  Created on: 12 de jun de 2017
 *      Author: vitorrussi
 */
#include <random>
#include "napoleaoia.h"

NapoleaoIA::NapoleaoIA(std::string nome) {
	_nome = nome;
}

NapoleaoIA::~NapoleaoIA() {

}

int NapoleaoIA::jogador_pergunta_turnos() {
	return decisao_aleatoria(0,5);
}

int NapoleaoIA::jogador_jogada() {
	return decisao_aleatoria(0,4);
}

std::string NapoleaoIA::nome() {
	return _nome;
}

int NapoleaoIA::decisao_aleatoria(int min,int max){
	auto const seed = std::random_device()();
	std::mt19937 rg(seed);
	std::uniform_int_distribution<int> dist(min, max);
	int r = dist(rg);
	return r;
}

int NapoleaoIA::escolhe_trunfo(){
	return decisao_aleatoria(0,3);
}
