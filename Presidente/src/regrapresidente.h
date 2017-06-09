/*
 * regrapresidente.h
 *
 *  Created on: 7 de jun de 2017
 *      Author: adolfo
 */

#ifndef REGRAPRESIDENTE_H_
#define REGRAPRESIDENTE_H_

#include "regra.h"
using namespace p3;

class RegraPresidente : public Regra{
public:
	RegraPresidente(std::size_t numero_de_jogadores,
			      int cartas_jogadores,
				  int rodadas = -1,
				  int pontuacao_max = -1,
				  int menor_pontuacao = -1,
				  int cartas_inicial = 52,
				  modo_fim fim = modo_fim::pontuacao,
				  condicao_vitoria vit = condicao_vitoria::maior_pontuacao,
				  condicao_derrota der = condicao_derrota::nenhuma);
	virtual ~RegraPresidente();
};

#endif /* REGRAPRESIDENTE_H_ */
