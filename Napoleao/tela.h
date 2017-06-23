/*
 * tela.h
 *
 *  Created on: 20 de jun de 2017
 *      Author: vitorrussi
 */

#ifndef TELA_H_
#define TELA_H_

#include "napoleao.h"

#define MAO 5
#define SIMULACAO true
#define MOSTRA true

class Tela {
public:
	Tela();
	void inicia_jogo();
	virtual ~Tela();
private:
	std::unique_ptr<Napoleao> _nap;
	void tela_inicia_rodada();
	void pergunta_turnos(int pos);
	void imprime_mao_atual();
	std::string imprime_carta(Carta card);
	std::string imprime_naipe(Carta::Naipe card);
	std::string imprime_naipe(int card);
	int escolhe_declarante();
	void declarante_escolhe_trunfo();
	void inicio_turno(unsigned int primeiro);
	void primeira_jogada(int primeiro);
	void jogada_normal(unsigned int pos);
	void imprime_pontuacao();
};

#endif /* TELA_H_ */