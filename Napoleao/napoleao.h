/*
 * napoleao.h
 *
 *  Created on: 6 de jun de 2017
 *      Author: vitorrussi
 */

#ifndef NAPOLEAO_H_
#define NAPOLEAO_H_

#include "jogo.h"
using namespace p3;
class Napoleao {
public:
	Napoleao();
	void inicia_jogo();
	void inicia_rodada();
	bool roda_turno();
	void define_trunfo(Carta::Naipe trunfo);
	virtual ~Napoleao();

private:
	Jogo *_jogo;
	unsigned int _turno = 1;
	Carta::Naipe _trunfo = Carta::Naipe::Ouros;
	int _aposta_max = -1;
	int _declarante = 0;
};

#endif /* NAPOLEAO_H_ */
