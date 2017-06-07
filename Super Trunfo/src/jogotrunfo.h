/*
 * jogotrunfo.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: breno
 */

#ifndef SRC_JOGOTRUNFO_H_
#define SRC_JOGOTRUNFO_H_

#include <memory>

#include "jogo.h"
#include "cartatrunfo.h"
#include "jogada.h"

class Jogo_trunfo {
public:
	Jogo_trunfo(p3::JogoBasico<Carta_trunfo>* jogo_basico);
	Jogada::Atributos recebe_jogada();
	void realiza_jogada();


private:
	std::unique_ptr<p3::JogoBasico<Carta_trunfo>> _jogo_basico;

};

#endif /* SRC_JOGOTRUNFO_H_ */
