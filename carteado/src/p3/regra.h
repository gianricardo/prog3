/*
 * regra.h
 *
 *  Created on: 17 de mai de 2017
 *      Author: aluno
 */

#ifndef REGRA_H_
#define REGRA_H_

#include <string>

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
		  condicao_derrota der = condicao_derrota::nenhuma );

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
};

} /* namespace p3 */

#endif /* REGRA_H_ */
