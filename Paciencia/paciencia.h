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
#include "tela.h"

namespace p3 {

class Paciencia {
public:
	Paciencia();
	virtual ~Paciencia();
	void rodada();
	void set_jogada();
	std::string get_jogada();
	bool verifica_jogada();

private:

	std::string _jogada;
	Tela _tela;
	Estado_jogo _estado_jogo;
};

} /* namespace p3 */

#endif /* PACIENCIA_H_ */
