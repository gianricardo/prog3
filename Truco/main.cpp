/*
 * main.cpp

 *
 *  Created on: 24 de mai de 2017
 *      Author: bruno
 */

#include "jogo.h"
#include "mesa.h"
#include "baralho.h"
#include "regratruco.h"

int main(){
	std::vector<std::string> nome = {"Bruno", "Joao", "Pedro"};
	p4::Regra_Truco r1(2,3,-1,12,40);
	p4::Regra_Truco *r1_ptr = &r1;
	p3::Jogo j1(r1_ptr,nome);

	while(j1.jogando()){

	}

	return 0;
}



