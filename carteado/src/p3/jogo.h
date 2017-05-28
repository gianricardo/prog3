/*
 * jogo.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef JOGO_H_
#define JOGO_H_

#include <memory>
#include <limits>
#include "mesa.h"
#include "regra.h"

namespace p3 {

class Jogo {
public:

    //Construtor
	Jogo(Regra *regra, std::vector<std::string> nomes);
	
	virtual ~Jogo();

	std::size_t numero_de_jogadores() const; //retorna numero de jogares
	int cartas_inicial() const; //retorna numero de cartas iniciais monte
	int cartas_jogadores() const; //retorna cartas iniciais por jogadores
	int max_rodadas() const; //retorna numero maximo de rodadas
	int pontuacao_max() const; //retorna numero de pontos para termino

	void reiniciar(); // TODO

	 //Termina a jogada do jogador atual, caso ele seja o ultimo jogador, muda a rodada
	void fim_jogada();

    //Retorna se o jogo esta em andamento
	bool jogando() const;

	//Retorna numero da rodada atual
	std::size_t rodada() const;

    //Retorna o nome do jogador atual
	std::string nome_jogador_atual() const;

    //Retorna a posicao na mesa do jogador atual
	std::size_t posicao_jogador_atual() const;

    //Retorna um vetor contendo as cartas do jogador atual
	std::vector<Carta> mostra_mao_jogador_atual() const;

    //Retorna a pontucao do jogador atual
	int pontuacao_jogador_atual() const;

	 //Aumenta a pontucao do jogador atual em "pontos" pontos
	void jogador_soma_pontos(int pontos);

    //Diminui a pontucao do jogador atual em "pontos" pontos
	void jogador_subtrai_pontos(int pontos);

	 // move carta do jogador atual para outro jogador
	bool move_carta_j(Carta carta, std::size_t j);
	
	 // move carta do monte principal para outro monte
	bool move_carta_m(std::size_t m, bool p_cima = true, bool m_cima = true);
	
	 // move carta entre jogadores
	bool move_carta_jj(Carta carta, std::size_t j1, std::size_t j2 = jogador_atual);
	
	 // move carta de um jogador para um monte
	bool move_carta_jm(Carta carta, std::size_t j = jogador_atual, std::size_t m = 0, bool m_cima = true);
	
	 // move carta de um monte para um jogador
	bool move_carta_mj(std::size_t m = 0, std::size_t j = jogador_atual, bool m_cima = true);
	
	 // move carta entre montes
	bool move_carta_mm(std::size_t m1, std::size_t m2 = 0, bool m1_cima = true, bool m2_cima = true);

	
    //Cria um novo monte na mesa
	void novo_monte();

    //Deleta um monte da mesa especificada em "i"
	void deleta_monte(std::size_t i);

private:

	static const std::size_t jogador_atual = std::numeric_limits<std::size_t>::max();

	void verifica_fim_de_jogo();

	void verifica_vitoria();					//checa se algum jogador ja ganhou

	void verifica_jogadores_derrotados();		//checa se algum jogador perdeu

	bool todos_jogadores_derrotados();			//retorna se todos os jogadores perderam

	void verifica_fim_zero_cartas();			//ultizado na condicao de fim de todos com zero cartas

	void verifica_jogador_pontuacao_maxima();	//utilizado para condicao de vitoria de maior pontuacao

	void verifica_jogador_pontuacao_minima();	//utilizado para condicao de vitoria de menor pontuacao

	void verifica_jogador_mais_cartas();		//ultizado para condicao de vitoria de mais cartas

	void verifica_jogador_menos_cartas();		//ultizado para condicao de vitoria de menos cartas

	void verifica_jogador_unico();				//utilizado na condicao de vitoria de ultimo jogador

	int numero_jogadores_aptos();

	void declara_fim_de_jogo();

	void declara_vencedor(std::size_t j);

	void _coloca_monte(Carta c, std::size_t m, bool topo);

	Carta _pega_monte(std::size_t m, bool topo);

	std::unique_ptr<Regra> _regra;
	Mesa _mesa;

	std::size_t _jog_atual;
	std::size_t _rodada;

	bool _jogando;

};


} /* namespace p3 */

#endif /* JOGO_H_ */
