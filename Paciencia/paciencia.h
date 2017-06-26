/*
 * paciencia.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: lucas
 */

//Jogadas e verificacao de jogadas

#ifndef PACIENCIA_H_
#define PACIENCIA_H_

#include <cstring>
#include <stdlib.h>
#include "estadojogo.h"

namespace p3 {

class Paciencia {
public:
	Paciencia();
	virtual ~Paciencia();
	void set_jogada(std::string jogada);
	std::string get_jogada();
	bool verifica_jogada();

private:

	std::string _jogada;
};

} /* namespace p3 */

#endif /* PACIENCIA_H_ */
