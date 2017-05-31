/*
 * jogo_truco.h
 *
 *  Created on: 30 de mai de 2017
 *      Author: bruno
 */

#ifndef JOGO_TRUCO_H_
#define JOGO_TRUCO_H_

#include "jogo.h"

namespace p4 {

class Jogo_Truco:public p3::Jogo{
public:
	Jogo_Truco(p3::Regra *regra, std::vector<std::string> nomes);
	virtual ~Jogo_Truco();

	int compara(std::size_t pos_jog,p3::Carta c1,p3::Carta c2,p3::Carta _vira);

	void truco(p3::Jogador j1);

	bool truco();

	int valor_pontuacao();

	std::size_t joga_turno(std::size_t j_posicao, int comparou);
};

} /* namespace p4 */

#endif /* JOGO_TRUCO_H_ */
