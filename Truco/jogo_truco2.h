/*
 * jogo_truco2.h
 *
 *  Created on: 25 de jun de 2017
 *      Author: bruno
 */

#ifndef JOGO_TRUCO2_H_
#define JOGO_TRUCO2_H_
#include "jogo_truco.h"
#include "jogo2.h"


namespace p4 {

class Jogo_Truco2:public Jogo_Truco{
public:
	Jogo_Truco2(p3::Regra *regra, std::vector<std::string> nomes);
	virtual ~Jogo_Truco2();

private:
    Jogo2 *interface;
};

} /* namespace p4 */

#endif /* JOGO_TRUCO2_H_ */
