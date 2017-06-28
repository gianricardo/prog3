/*
 * tela.h
 *
 *  Created on: 19 de jun de 2017
 *      Author: lucas
 */

//Responsavel pelas impressoes na tela

#ifndef TELA_H_
#define TELA_H_

#include <iostream>
#include "estadojogo.h"

namespace p3 {

class Tela {
public:

    std::string mostra_carta(Estado_jogo *jogo, int i);

	void vitoria();
	void derrota();

};

} /* namespace p3 */

#endif /* TELA_H_ */
