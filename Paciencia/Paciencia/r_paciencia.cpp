/*
 * r_paciencia.cpp
 *
 *  Created on: 20 de jun de 2017
 *      Author: lucas
 */

#include "r_paciencia.h"
#include <iostream>

namespace p3 {

R_Paciencia::R_Paciencia() : p3::Regra(1, 0, -1, 52, 0, 52, Regra::modo_fim::pontuacao,
        Regra::condicao_vitoria::maior_pontuacao,
        Regra::condicao_derrota::nenhuma, 0){

}

bool R_Paciencia::verifica_ordem (int num1, int num2, int m/*1 para monte_vitoria, 2 para monte_mesa*/){

	//std::cout << "Carta num : "<< num1 << " " << num2 << std::endl;

	if(m == 1){

		if(num1 == (num2 + 1))
			return true;
	}
	else if(m == 2){

		if(num1 == (num2 - 1))
			return true;
	}
	return false;
}

bool R_Paciencia::verifica_naipe (Carta::Naipe n1, Carta::Naipe n2, int m /*1 para monte_vitoria, 2 para monte_mesa*/){

	if(m == 1){
		if(n1 == n2){
			//std::cout << "Naipe True" << std::endl; 
			return true;
		}
	}
	else if(m == 2){

		int c1, c2; // 1 para preto, 0 para vermelho

		if(n1 == Carta::Naipe::Espadas || n1 == Carta::Naipe::Paus)
			c1 = 1;
		else
			c1 = 0;
	
		if(n2 == Carta::Naipe::Espadas || n2 == Carta::Naipe::Paus)
			c2 = 1;
		else
			c2 = 0;
		
		if(c1 != c2){
			//std::cout << "Naipe True" << std::endl; 
			return true;
		}
	}

	return false;
}


} /* namespace p3 */
