/*
 * napoleao.h
 *
 *  Created on: 6 de jun de 2017
 *      Author: vitorrussi
 */

#ifndef NAPOLEAO_H_
#define NAPOLEAO_H_

#define MOSTRA true
#define SIMULACAO true

#include <memory>

#include "jogo.h"
#include "jogadornapoleao.h"
#include "napoleaopessoa.h"
#include "napoleaoia.h"

using namespace p3;
class Napoleao {
public:
	Napoleao();
	void inicia_jogo(); // comeca o jogo
	virtual ~Napoleao();

private:
	std::unique_ptr<Jogo> _jogo;
	unsigned int _turno = 1;
	Carta::Naipe _trunfo = Carta::Naipe::Ouros;
	int _aposta_max = 0;
	int _declarante = 0;
	int _inicio = 0;
	std::vector<std::unique_ptr<JogadorNapoleao> > _jogadores;
	Carta::Naipe _naipe_inicial = Carta::Naipe::Ouros;
	int _declarante_rodadas = 0;

	bool inicia_rodada(); // comeca uma nova rodada
	void define_trunfo(Carta::Naipe trunfo); // define qual vai ser o trunfo do turno
	void pergunta_turnos(int pos); //pergunta pros jogadores qual a qtd de turnos que eles irão fazer
	void imprime_mao_atual(); //imprime a mao do jogador atual.
	std::string imprime_naipe(Carta::Naipe card);
	std::string imprime_naipe(int card);
	int inicio_turno(unsigned int primeiro);
	int napoleao_jogada(int pos);
	void declarante_escolhe_trunfo();
	Carta carta_jogador_atual(int pos);
	Carta carta_maior();
	std::string imprime_carta(Carta card);
	bool compara_cartas(Carta topo, Carta nova);
	void imprime_pontuacao();
	void fim_do_jogo();
	void limpa_mao();
};

#endif /* NAPOLEAO_H_ */
