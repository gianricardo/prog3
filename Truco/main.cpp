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
	int carta;
	std::vector<std::string> nome = {"Bruno", "Joao", "Pedro"};
	p4::Regra_Truco r1(2,3,-1,12,40);
	p4::Regra_Truco *r1_ptr = &r1;
	p3::Jogo j1(r1_ptr,nome);

	while(j1.jogando()){
		if(j1.posicao_jogador_atual() == 0){
			j1.mostra_mao_jogador_atual();
			std::cout<< "Escolha uma carta: ";
			std::cin >> carta;
			j1.move_carta_jm((j1.mostra_mao_jogador_atual())[carta],0,2,true);
		}

	}

	return 0;
}



