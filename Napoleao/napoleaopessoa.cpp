/*
 * napoleaopessoa.cpp
 *
 *  Created on: 12 de jun de 2017
 *      Author: vitorrussi
 */

#include <iostream>
#include "napoleaopessoa.h"

NapoleaoPessoa::NapoleaoPessoa(std::string nome) {
	_nome = nome;
	// TODO Auto-generated constructor stub

}

NapoleaoPessoa::~NapoleaoPessoa() {
	// TODO Auto-generated destructor stub
}

int NapoleaoPessoa::jogador_pergunta_turnos() {
	return resposta();
}

int NapoleaoPessoa::jogador_jogada() {
	return resposta();
}

int NapoleaoPessoa::escolhe_trunfo(){
	return resposta();
}

std::string NapoleaoPessoa::nome() {
	return _nome;
}

int NapoleaoPessoa::resposta(){
	int resp;
	std::cin >> resp;
	return resp;
}
