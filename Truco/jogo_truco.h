/*
 * jogo_truco.h
 *
 *  Created on: 30 de mai de 2017
 *      Author: bruno
 */

#ifndef JOGO_TRUCO_H_
#define JOGO_TRUCO_H_

#include "jogo.h"
#include "regra.h"
#include "jogador.h"

namespace p4 {

class Jogo_Truco:public p3::Jogo{
public:
	Jogo_Truco(p3::Regra *regra, std::vector<std::string> nomes);
	virtual ~Jogo_Truco();
};

} /* namespace p4 */

#endif /* JOGO_TRUCO_H_ */
