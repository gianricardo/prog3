/*
 * baralho.h
 *
 *  Created on: 10 de mai de 2017
 *      Author: aluno
 */

#ifndef BARALHO_H_
#define BARALHO_H_

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

#include "carta.h"
#include "jogador.h"

namespace p3 {

class Baralho {
public:
	Baralho(int n_numerocartas);
	virtual ~Baralho();
	void embaralhar();
	Carta pega_topo(void);
	Carta pega_baixo(void);

private:
	int _numerocartas;
	std::vector<Carta> _monte;
};

} /* namespace p3 */

#endif /* BARALHO_H_ */
