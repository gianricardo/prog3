/*
 * napoleao.h
 *
 *  Created on: 6 de jun de 2017
 *      Author: vitorrussi
 */

#ifndef NAPOLEAO_H_
#define NAPOLEAO_H_

#include <memory>

#include "../carteado/src/p3/jogo.h"
#include "jogadornapoleao.h"
#include "napoleaopessoa.h"
#include "napoleaoia.h"

using namespace p3;
class Napoleao {
public:
	Napoleao(Regra *Rules, std::vector<std::string> nomes, int jogadores, bool SIMULACAO);
	void inicia_jogo(); // comeca o jogo
	virtual ~Napoleao();

public:
	std::unique_ptr<Jogo> _jogo;
	unsigned int _turno = 1;
	Carta::Naipe _trunfo = Carta::Naipe::Ouros;
	int _aposta_max = 0;
	int _declarante = 0;
	int _inicio = 0;
	std::vector<std::unique_ptr<JogadorNapoleao> > _jogadores;
	Carta::Naipe _naipe_inicial = Carta::Naipe::Ouros;
	int _declarante_turnos = 0;
	int _vencedor_turno = 0;

	int numero_de_jogadores();
	std::string nome_jogador_atual();
	void muda_jogador_atual(unsigned int pos);
	int aposta_maxima();
	void set_aposta_maxima(int val);
	void define_declarante(int pos);
	void define_naipe(int naipe);
	int pergunta_turnos(int pos, bool zero);
	std::vector<Carta> mostra_mao_jogador_atual();
	int posicao_jogador_atual();
	int posicao_declarante();
	int declarante_escolhe_trunfo();
	Carta::Naipe naipe_trunfo();
    int primeira_jogada(int pos);
    void first_move(int first);
	Carta jogada_normal(int pos);
    void executa_jogada(int pos);
	void joga_monte(Carta nova, int pos);
	int posicao_vencedor_turno();
	bool declarante_venceu_turno();
	int declarante_turnos_feitos();
	bool declarante_venceu_rodada();
	int max_rodadas();
	void jogo_conf_inicio();
	void rodada_conf_inicio();
	void define_trunfo(Carta::Naipe trunfo); // define qual vai ser o trunfo do turno
	//void pergunta_turnos(int pos); //pergunta pros jogadores qual a qtd de turnos que eles irão fazer
	void imprime_mao_atual(); //imprime a mao do jogador atual.
	int napoleao_jogada(int pos);
	Carta carta_jogador_atual(int pos);
	Carta carta_maior();
	bool compara_cartas(Carta topo, Carta nova);
	std::vector<int> vetor_pontuacao();
	void fim_do_jogo();
	void limpa_mao();
};

#endif /* NAPOLEAO_H_ */
