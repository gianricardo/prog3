/*
 * regra.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef REGRA_H_
#define REGRA_H_

#include <string>
#include "carta.h"

namespace p3 {

class Regra {
public:

	//modos de fim de jogo TODO:explicar cada um
	enum class modo_fim { padrao, pontuacao, rodadas, zero_cartas, zero_jogadores };

	//modos de vitoria TODO:explicar cada um
	enum class condicao_vitoria { padrao, maior_pontuacao, menor_pontuacao, menos_cartas, mais_cartas};

	//modos de derrota TODO:explicar cada um
	enum class condicao_derrota { nenhuma, zero_cartas, estoura_pontuacao, zero_pontos };
	
	//Construtor
	//recebe como parametros o numero de jogadores que o jogo possui inicialmente, a quantidade de cartas que cada
	//jogador tem na primeira rodada, o numero de rodadas maximo, a pontuacao maxima que pode ser atingida, a pontuacao
	//minima que pode ser atingida, a quantidade de cartas inicial do baralho principal do jogo, e os modos de fim de
	//jogo, de vitoria e de derrota
	Regra(std::size_t numero_de_jogadores,
		  int cartas_jogadores, 
		  int rodadas = -1,
		  int pontuacao_max = -1,
		  int menor_pontuacao = -1,
		  int cartas_inicial = 52,
		  modo_fim fim = modo_fim::pontuacao, 
		  condicao_vitoria vit = condicao_vitoria::maior_pontuacao, 
		  condicao_derrota der = condicao_derrota::nenhuma, 
		  int auto_pontos_carta_mao = 0);

	//Destrutor
	virtual ~Regra();

	//retorna o numero de jogadores inicial do jogo
	std::size_t numero_de_jogadores() const;

	//retorna numero de cartas inicial no baralho principal do jogo
	int cartas_inicial() const;

	//retorna cartas iniciais por jogadores
	int cartas_jogadores() const;

	//retorna numero maximo de rodadas
	int max_rodadas() const;

	//retorna a pontuacao maxima que pode ser atingida
	int pontuacao_max() const;

	//retorna pontuacao mininma que pode ser atingida
	int menor_pontuacao() const;

	//retorna o modo de fim de jogo
	modo_fim fim() const;

	//retorna a condicao de vitoria estabelecida
	condicao_vitoria cond_vit() const;

	//retorna a condicao de derrota estabelecida
	condicao_derrota cond_der() const;

	//retorna a pontuacao automatica por carta na mao
	int pontuacao_carta_mao() const;

	//TODO implementada por bruno:

	//compara as cartas
	virtual int compara(Carta c1, Carta c2, Carta c3);

	//checa se a rodada acabou
	virtual bool checa_fim_rodada(std::size_t pos);

	//
	virtual void jogador_ganhou_rodada(std::size_t jogador,std::size_t rodada);

	//checa o ganhador do turno
	virtual std::size_t jogador_ganhou_turno();

	virtual void recomeca_turno();

	//checa se o turno chegou ao fim
	virtual bool fim_turno(std::size_t rodada, std::size_t ganhou);

	//retorna o valor da pontuacao
	virtual int valor_pontuacao(bool cond,int valor);

	//retorna o jogador que comeca a rodada
	virtual std::size_t jogador_comeca();

	//define o jogador que comeca a rodada
	virtual void jogador_comeca(std::size_t n_pos);

	//retorna o jogador em que a rodada termina
	virtual std::size_t jogador_termina();

	//define o jogador em que a rodada termina
	virtual void jogador_termina(std::size_t n_pos);

	//retorna o jogador em que o turno comeca
	virtual std::size_t jogador_comeca_turno();

	//define o jogador em que o turno comeca
	virtual void jogador_comeca_turno(std::size_t n_pos);

protected:

	std::size_t _numero_de_jogadores;	// numero de jogadores que iniciam a partida
	int _cartas_inicial; 				// numero de cartas do monte
	int _cartas_jogadores; 				// cartas iniciais por jogadores
	int _rodadas; 						// numero maximo de rodadas
	int _pontuacao_max; 				// numero de pontos para termino
	int _menor_pontuacao; 				// usada para condicao de derrota de menor pontuacao
	modo_fim _fim;						// condicao estabelecida para fim de jogo
	condicao_vitoria _vit;				// condicao estabelecida para vitoria de um jogador
	condicao_derrota _der;				// condicao estabelecida para derrota de um jogar

	int _pont_cartas_mao; 				// pontucao somada e subtraida automaticamente por carta na mao
};

} /* namespace p3 */

#endif /* REGRA_H_ */
