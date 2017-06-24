/*
 * interface.cpp
 *
 *  Created on: 23 de jun de 2017
 *      Author: adolfo
 */

#include "interface.h"

int Interface::get_play(){
	int c;
	std::cout<<"Digite o numero da carta que deseja jogar, 0 para passar:";
	std::cin>>c;
	return c;
}

void Interface::show_hand(std::vector<Carta> v){
	for(auto cardp : v){
		if(cardp.mostra())
		std::cout << cardp.numero() << " ";
		else
		std::cout << "0 ";
	}
	std::cout << std::endl;
}

void Interface::show_status(int last,int number){
	if(last!=-1){
		std::cout<<"A ultima carta jogada foi: ";
		for(int j=0;j<number;j++)
			std::cout<<last<<' ';
		std::cout << "\n";
	}else{
		std::cout<<"Voce inicia a rodada \n";
	}
}

std::string Interface::get_playername(){
	std::string player_name;
	std::cout<<"Insira o nome do jogador: "<<std::endl;
	std::cin>>player_name;
	return player_name;
}


void Interface::show_winner(int j){
	std::cout<<"O jogador vencedor foi o da posicao "<<j<<std::endl;
}

void Interface::show_pontuation(int p, int j){
	std::cout<<"O jogador "<<j<<" fez "<<p<<" pontos"<<std::endl;
}
