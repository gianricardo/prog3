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

	/*
	 *	Cria um baralho com "numerocartas" numero de cartas
	 */
	Baralho(std::size_t numerocartas = 0);
	virtual ~Baralho();

	/*
	 *	Emabaralha o baralho
	 */
	void embaralhar();

	/*
	 *	Pega uma carta do topo
	 */
	Carta pega_topo(void);
	/*
	 *	Pega uma carta de baixo
	 */
	Carta pega_baixo(void);

	/*
	 *	Coloca uma carta no topo do baralho
	 */
	void coloca_topo(Carta c);
	/*
	 *	Coloca uma carta em baixa do baralho
	 */
	void coloca_baixo(Carta c);

	/*
	 *	Retorna o numero de cartas do baralho
	 */
	std::size_t size() const;

	/*
	 *	Restaura as cartas do baralho as iniciais
	 */
	void restaurar();

private:
	std::size_t _numerocartas;
	std::deque<Carta> _monte;
};

} /* namespace p3 */

#endif /* BARALHO_H_ */


