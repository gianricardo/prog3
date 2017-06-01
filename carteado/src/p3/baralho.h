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

	//Altera posicao da carta
	//a carta passada como parametro terá sua posicao invertida(cima->baixo, baixo->cima)
    void vira_carta(CARTA c);
    
private:

    //guarda o numero de cartas inicial passado ao baralho
	std::size_t _numerocartas;

	//vetor de cartas que representa o baralho
	std::deque<CARTA> _monte;
};

template<class CARTA> void BaralhoBasico<CARTA>::vira_carta(CARTA c){
    c.vira();
}

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


