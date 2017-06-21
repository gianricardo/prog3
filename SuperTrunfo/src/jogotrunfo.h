/*
 * jogotrunfo.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: breno
 */

#ifndef SRC_JOGOTRUNFO_H_
#define SRC_JOGOTRUNFO_H_

#include <memory>
#include <iostream>

#include "jogo.h"
#include "regra.h"
#include "cartatrunfo.h"
#include "jogada.h"

class Jogo_trunfo : public p3::JogoBasico<Carta_trunfo>{
public:
	Jogo_trunfo(p3::Regra *regra, std::vector<std::string> nomes);
	Jogada recebe_jogada();
	void realiza_jogada(Jogada jogada);

private:
	void move_carta_jogador_vencedor(size_t jogador_vencedor);
	void move_carta_empate();
	int checa_super_trunfo();
	size_t jogador_oponente();
	Carta_trunfo carta_super_trunfo;

};




















#endif /* SRC_JOGOTRUNFO_H_ */
