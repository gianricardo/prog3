/*
 * jogador.h
 *
 *  Created on: 15 de mai de 2017
 *      Author: aluno
 */

#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "carta.h"

namespace p3 {

class Jogador {
public:
	Jogador(std::string name);
	virtual ~Jogador();
	void recebe_carta(Carta card);
	Carta joga_carta();
private:
	std::vector<Carta> _mao;
	std::string _nome;
	int seleciona_carta();
};

} /* namespace p3 */

#endif /* JOGADOR_H_ */
