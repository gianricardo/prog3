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
#include <QApplication>

#include "trunfoui.h"
#include "../../carteado/src/p3/jogo.h"
#include "../../carteado/src/p3/regra.h"
#include "../Interface_Trunfo/trunfoui.h"
#include "inteligenciaartificial.h"
#include "cartatrunfo.h"
#include "jogada.h"

class Jogo_trunfo : public p3::JogoBasico<Carta_trunfo>{
public:
    Jogo_trunfo(p3::Regra *regra, std::vector<std::string> nomes, TrunfoUI *ui);
    ~Jogo_trunfo();
	void jogar();
	Jogada recebe_jogada();
	void realiza_jogada(Jogada jogada);
    void determina_acao_jogador_vencedor(const size_t jogador_vencedor);
    bool fim_jogada() override;
	int ultimo_jogador_vencedor();
	void imprime_numero_cartas();

private:
	Carta_trunfo carta_super_trunfo;
	size_t _ultimo_jogador_vencedor = 2;

    void verifica_jogadores_derrotados() override;
    void move_carta_jogador_vencedor(const size_t jogador_vencedor);
	void move_carta_empate();
	int checa_super_trunfo();
	size_t jogador_oponente();
	void imprime_atributo_escolhido(Jogada jogada);
    int carta_jogador_0_index();
    int carta_jogador_1_index();

    TrunfoUI *_ui;

};

#endif /* SRC_JOGOTRUNFO_H_ */
