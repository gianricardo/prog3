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
#include "regra.h"
#include "cartatrunfo.h"
#include "jogada.h"

class Jogo_trunfo : public p3::JogoBasico<Carta_trunfo>{
public:
	Jogo_trunfo(p3::Regra *regra, std::vector<std::string> nomes);
	Jogada::Atributos recebe_jogada();
	void realiza_jogada();

private:

};





















#endif /* SRC_JOGOTRUNFO_H_ */
