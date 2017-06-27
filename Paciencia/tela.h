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

	void jogada_invalida();
	std::string jogada_atual();

	void mostra_carta(Carta *c);
	void pontuacao_tela(Estado_jogo *jogo);
	void nome_jogador(Estado_jogo *jogo);


	void tela_jogo(Estado_jogo *jogo);
};

} /* namespace p3 */

#endif /* TELA_H_ */
