/*
 * trunfo.cpp
 *
 *  Created on: 6 de jun de 2017
 *      Author: breno
 */

#include <iostream>
#include "regra.h"

int main()
{
	//2 jogadores, 16 cartas cada, 32 cartas ao total. Restante irrelevante

	p3::Regra regra_trunfo(	2, 16, -1, -1, -1, 32,
							p3::Regra::modo_fim::padrao,
							p3::Regra::condicao_vitoria::maior_pontuacao,
							p3::Regra::condicao_derrota::zero_cartas);


	return 0;
}
