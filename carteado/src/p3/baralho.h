/*
 * baralho.h
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#ifndef BARALHO_H_
#define BARALHO_H_

#include <iostream>
#include <deque>
#include <random>
#include <algorithm>

#include "carta.h"
#include "jogador.h"

namespace p3 {

template<class CARTA>
class BaralhoBasico {
public:
	//Cria um baralho com "numerocartas" numero de cartas
	BaralhoBasico(std::size_t numerocartas = 0);
	virtual ~BaralhoBasico();

	//Emabaralha o baralho
	void embaralhar();

	//Pega uma carta do topo
	CARTA pega_topo(void);

	//Pega uma carta de baixo
	CARTA pega_baixo(void);

	//Coloca uma carta no topo do baralho
	void coloca_topo(CARTA c);

	//Coloca uma carta em baixa do baralho
	void coloca_baixo(CARTA c);

	//Retorna o numero de cartas do baralho
	std::size_t size() const;

	//Restaura as cartas do baralho as iniciais
	void restaurar();

private:
	std::size_t _numerocartas;
	std::deque<CARTA> _monte;
};


template<class CARTA> BaralhoBasico<CARTA>::BaralhoBasico(std::size_t numerocartas/* = 0 */) : _numerocartas{numerocartas} {

	if(numerocartas % CARTA::n_naipes) std::cerr << "Baralho::Baralho -- numero de cartas nao divisivel pelo numero de naipes\n";

	restaurar();
}

template<class CARTA> BaralhoBasico<CARTA>::~BaralhoBasico() {
}

template<class CARTA> void BaralhoBasico<CARTA>::embaralhar(){
	
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(_monte.begin(), _monte.end(), g);
}

template<class CARTA> CARTA BaralhoBasico<CARTA>::pega_topo(void){
	CARTA c = _monte.front();
	_monte.pop_front();
	return c;
}

template<class CARTA> CARTA BaralhoBasico<CARTA>::pega_baixo(void){
	CARTA c = _monte.back();
	_monte.pop_back();
	return c;
}

template<class CARTA> void BaralhoBasico<CARTA>::coloca_topo(CARTA c){

	_monte.push_front(c);
}

template<class CARTA> void BaralhoBasico<CARTA>::coloca_baixo(CARTA c){

	_monte.push_back(c);
}

template<class CARTA> std::size_t BaralhoBasico<CARTA>::size() const {

	return _monte.size();
}

template<class CARTA> void BaralhoBasico<CARTA>::restaurar(){

	std::size_t cartas_por_naipe = _numerocartas / CARTA::n_naipes;

	_monte.clear();

	for(int naipe = 0; naipe < CARTA::n_naipes; naipe++){
		
		for(std::size_t numero = 1; numero <= cartas_por_naipe; numero++) _monte.emplace_back(numero, (typename CARTA::Naipe) naipe);
	}
}

using Baralho = BaralhoBasico<Carta>;

} /* namespace p3 */

#endif /* BARALHO_H_ */


