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
	//Construtor
	//recebe o numero de cartas total do baralho
	//se o numero de cartas nao for divisivel pelo numero de naipes, retorna um baralho com o valor truncado da divisao
	//de numerocartas por numero de naipes do baralho;
	BaralhoBasico(std::size_t numerocartas = 0);

	//Destrutor
	virtual ~BaralhoBasico();

	//Emabaralha o baralho
	//utiliza um algoritimo que faz trocas de posicoes aleatorias no vetor de cartas
	void embaralhar();

	//Pega uma carta do topo
	//retorna a primeira carta do vetor de cartas e remove ela do vetor
	CARTA pega_topo(void);

	//Pega uma carta de baixo
	//retorna a ultima carta do vetor de cartas e remove ela do vetor
	CARTA pega_baixo(void);

	//Coloca uma carta no topo do baralho
	//a carta passada como argumento é colocada no inicio do vetor de cartas
	void coloca_topo(CARTA c);

	//Coloca uma carta em baixa do baralho
	//a carta passada como argumento é colocada no final do vetor de cartas
	void coloca_baixo(CARTA c);

	//Retorna o numero de cartas do baralho
	std::size_t size() const;

	//Restaura as cartas do baralho as iniciais
	//limpa o vetor de cartas e recoloca todas elas no vetor de cartas novamente como se fosse o baralho inicial
	void restaurar();

	// vira a carta do topo do baralho
	//
	// nao retorna nada
	//
	// ex: baralho.vira_topo();
	//
    void vira_topo();

    // vira a carta de baixo do baralho
	//
	// nao retorna nada
	//
	// ex: baralho.vira_baixo();
	//
    void vira_baixo();

    // vira uma carta de um jogador
	//
	// retorna um vetor contendo cartas e um booleano, caso a carta na respectiva posicao esteja virada para baixo, 
	// o booleano sera false e a carta tera um valor padrao indicando estar virada para baixo, caso a carta esteja
	// virada para cima o booleano sera true e a carta correspondera ao valor da carta do baralho na posicao
	//
	// ex: baralho.mostra_baralho()[0].second; // acesso a carta no topo
	//     baralho.mostra_baralho()[baralho.size() - 1].first; // verifica se a carta em baixo do baralho esta virada para cima
	//
    std::vector<std::pair<bool, CARTA> > mostra_baralho() const;
    
private:

    //guarda o numero de cartas inicial passado ao baralho
	std::size_t _numerocartas;

	//vetor de cartas que representa o baralho
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
		
		for(std::size_t numero = 0; numero < cartas_por_naipe; numero++){

			_monte.emplace_back((numero%CARTA::n_numeros) + 1, (typename CARTA::Naipe) naipe);
		}
	}
}

template<class CARTA> void BaralhoBasico<CARTA>::vira_topo(){
    
    _monte.front().vira();
}

template<class CARTA> void BaralhoBasico<CARTA>::vira_baixo(){
    
    _monte.back().vira();
}

template<class CARTA> std::vector<std::pair<bool, CARTA> > BaralhoBasico<CARTA>::mostra_baralho() const {

	std::vector<std::pair<bool, CARTA> > vec;

	vec.reserve(this->size());

	for(auto carta : _monte) vec.emplace_back(carta.mostra(), carta.mostra() ? carta : CARTA(0, static_cast<typename CARTA::Naipe>(0)));

	return vec;
}

using Baralho = BaralhoBasico<Carta>;

} /* namespace p3 */

#endif /* BARALHO_H_ */


