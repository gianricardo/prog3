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
#include "inteligenciaartificial.h"
#include "cartatrunfo.h"
#include "jogada.h"

class Jogo_trunfo : public p3::JogoBasico<Carta_trunfo>{
public:
	Jogo_trunfo(p3::Regra *regra, std::vector<std::string> nomes);
	void jogar();
	Jogada recebe_jogada();
	void realiza_jogada(Jogada jogada);
	void determina_acao_jogador_vencedor(size_t jogador_vencedor, Jogada jogada);
	void fim_jogada() override;
	int ultimo_jogador_vencedor();
	void imprime_numero_cartas();

private:
	Carta_trunfo carta_super_trunfo;
	size_t _ultimo_jogador_vencedor = 2;

	void move_carta_jogador_vencedor(size_t jogador_vencedor);
	void move_carta_empate();
	int checa_super_trunfo();
	size_t jogador_oponente();
	void imprime_atributo_escolhido(Jogada jogada);

};




















#endif /* SRC_JOGOTRUNFO_H_ */
