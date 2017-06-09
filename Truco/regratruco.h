/*
 *regratruco.h
 *
 *  Created on: 24 de mai de 2017
 *      Author: bruno
 */

#ifndef REGRATRUCO_H_
#define REGRATRUCO_H_

#include <deque>
#include <random>
#include <algorithm>
#include "regra.h"
#include "carta.h"
#include "jogador.h"


namespace p4{

class Regra_Truco final: public p3::Regra{
public:
	enum class Compara{Maior, Menor, Igual};
	Regra_Truco(std::size_t numero_de_jogadores,
			  int cartas_jogadores,
			  int rodadas,
			  int pontuacao_max,
			  int menor_pontuacao,
			  int cartas_inicial);

	virtual ~Regra_Truco();



private:
};
 /* namespace p3 */

#endif /* REGRATRUCO_H_ */
}
