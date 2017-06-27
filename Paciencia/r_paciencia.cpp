/*
 * r_paciencia.cpp
 *
 *  Created on: 20 de jun de 2017
 *      Author: lucas
 */

#include "r_paciencia.h"

namespace p3 {

R_Paciencia::R_Paciencia() : p3::Regra(1, 0, -1, 52, 0, 52, Regra::modo_fim::pontuacao,
        Regra::condicao_vitoria::maior_pontuacao,
        Regra::condicao_derrota::nenhuma, 0){

}

static bool R_Paciencia::verifica_ordem (int num1, int num2) const{

	if(num1 == (num2 - 1))
		return true;

	return false;
}

static bool R_Paciencia::verifica_naipe (Carta::Naipe n1, Carta::Naipe n2) const{

	if(n1 == n2)
		return true;

	return false;
}


} /* namespace p3 */
