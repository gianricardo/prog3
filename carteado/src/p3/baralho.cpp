/*
 * baralho.cpp
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#include "baralho.h"

namespace p3 {

Baralho::Baralho(std::size_t numerocartas/* = 0 */) : _numerocartas{numerocartas} {

	if(numerocartas % Carta::n_naipes) std::cerr << "Baralho::Baralho -- numero de cartas nao divisivel pelo numero de naipes\n";

	restaurar();
}

Baralho::~Baralho() {
}

void Baralho::embaralhar(){
	
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(_monte.begin(), _monte.end(), g);
}

Carta Baralho::pega_topo(void){
	Carta c = _monte.front();
	_monte.pop_front();
	return c;
}

Carta Baralho::pega_baixo(void){
	Carta c = _monte.back();
	_monte.pop_back();
	return c;
}

void Baralho::coloca_topo(Carta c){

	_monte.push_front(c);
}

void Baralho::coloca_baixo(Carta c){

	_monte.push_back(c);
}

std::size_t Baralho::size() const {

	return _monte.size();
}

void Baralho::restaurar(){

	std::size_t cartas_por_naipe = _numerocartas / Carta::n_naipes;

	_monte.clear();

	for(int naipe = 0; naipe < Carta::n_naipes; naipe++){
		
		for(std::size_t numero = 1; numero <= cartas_por_naipe; numero++) _monte.emplace_back(numero, (Carta::Naipe) naipe);
	}
}


} /* namespace p3 */
