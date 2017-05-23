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

	enum class modo_fim { padrao, pontuacao, rodadas, zero_cartas };
	enum class condicao_vitoria { padrao, maior_pontuacao, menor_pontuacao, menos_cartas, mais_cartas};
	enum class condicao_derrota { nenhuma, zero_cartas, estoura_pontuacao };
	
	Regra(std::size_t numero_de_jogadores,
		  int cartas_jogadores, 
		  int rodadas = -1,
		  int pontuacao_max = -1,
		  int cartas_inicial = 52,
		  modo_fim fim = modo_fim::pontuacao, 
		  condicao_vitoria vit = condicao_vitoria::maior_pontuacao, 
		  condicao_derrota der = condicao_derrota::nenhuma );

	virtual ~Regra();
	std::size_t numero_de_jogadores() const;
	int cartas_inicial() const; //retorna numero de cartas do monte
	int cartas_jogadores() const; //retorna cartas iniciais por jogadores
	int max_rodadas() const; //retorna numero maximo de rodadas
	int pontuacao_max() const; //retorna numero de pontos para termino
	modo_fim fim() const;
	condicao_vitoria cond_vit() const;
	condicao_derrota cond_der() const;

protected:
	std::size_t _numero_de_jogadores;
	int _cartas_inicial; // numero de cartas do monte
	int _cartas_jogadores; // cartas iniciais por jogadores
	int _rodadas; // numero maximo de rodadas
	int _pontuacao_max; // numero de pontos para termino

	modo_fim _fim;
	condicao_vitoria _vit;
	condicao_derrota _der;
};

} /* namespace p3 */

#endif /* REGRA_H_ */
