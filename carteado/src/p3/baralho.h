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

class Baralho {
public:
	Baralho(std::size_t numerocartas = 0);
	virtual ~Baralho();
	void embaralhar();
	Carta pega_topo(void);
	Carta pega_baixo(void);

	void coloca_topo(Carta c);
	void coloca_baixo(Carta c);

	std::size_t size() const;

	void restaurar();

private:
	std::size_t _numerocartas;
	std::deque<Carta> _monte;
};

} /* namespace p3 */

#endif /* BARALHO_H_ */


