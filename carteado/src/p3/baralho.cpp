/*
 * baralho.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#include "baralho.h"

namespace p3 {

Baralho::Baralho(int n_numerocartas = 52) {
	_numerocartas = n_numerocartas;

	for(int j=0;j<4;j++){
		Carta::Naipe np;
		switch(j){
		case 0:
			np=Carta::Naipe::Espadas;
			break;
		case 1:
			np=Carta::Naipe::Copas;
			break;
		case 2:
			np=Carta::Naipe::Paus;
			break;
		case 3:
			np=Carta::Naipe::Ouros;
			break;
		}
		for(int i = 0; i < (_numerocartas)/4; i++){
			_monte.emplace_back(i,np);
		}
	}
}

Baralho::~Baralho() {
}

void Baralho::embaralhar(){
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(_monte.begin(), _monte.end(), g);
}

Carta Baralho::pega_baixo(void){
	Carta c = _monte.back();
	_monte.pop_back();
	return c;
}

Carta Baralho::pega_topo(void){
	Carta c = _monte.front();
	_monte.erase(_monte.begin());
	return c;
}

void Baralho::distribuir(unsigned int qtd_cartas, std::vector<Jogador> jogadores, bool cima=true){
	if(qtd_cartas*jogadores.size()>_numerocartas){
		std::cout<<"Erro";
		return;
	}
	if(cima){
		for(auto k=qtd_cartas;k>0;k--){
			for(auto i=jogadores.size();i>0;i--){
				jogadores[i].recebe_carta(pega_topo());
			}
		}
	}else{
		for(auto k=qtd_cartas;k>0;k--){
			for(auto i=jogadores.size();i>0;i--){
				jogadores[i].recebe_carta(pega_baixo());
			}
		}
	}
}

} /* namespace p3 */
