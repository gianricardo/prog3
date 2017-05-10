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

	for(Carta::Naipe j = 0 ; j < 4; j++){
		for(int i = 0; i < (_numerocartas)/4; i++){
			_monte.emplace_back(i,j);
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

Carta pega_baixo(void){
	Carta c = _monte.back();
	_monte.pop_back();
	return c;
}

Carta pega_topo(void){
	Carta c = _monte.front();
	_monte.erase(_monte.begin());
	return c;
}

void Baralho::distribuir(int qtd_cartas){

}
}

} /* namespace p3 */
