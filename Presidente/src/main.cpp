/*
 * main.cpp
 *
 *  Created on: 31 de mai de 2017
 *      Author: adolfo
 */

#include <iostream>
#include <string>
#include "jogopresidente.h"
#include "regrapresidente.h"

using namespace p3;

int main(int argc, char *argv[]){
	std::string player_name;
	std::cout<<"Insira o nome do jogador: "<<std::endl;
	std::cin>>player_name;
	RegraPresidente rule_president(4,13,10,-1,-1,52,Regra::modo_fim::rodadas);
	JogoPresidente president(&rule_president,{player_name,"West","North","East"});
	std::vector<Carta> playing;
	president.novo_monte();
	president.novo_monte();
	president.novo_monte();
	president.novo_monte();
	int card;
	std::string decision;
	int last_played_card=-1;
	int number_of_cards_played=0;
	int count,pass_count=0;
	while(president.jogando()){
		if(president.rodada()!=1){
			president.pass_card(president.find_highest(2),president.retorna_bobo(),president.retorna_pres());
			president.pass_card(president.find_lowest(2),president.retorna_pres(),president.retorna_bobo());
			president.pass_card(president.find_highest(1),president.retorna_vicebobo(),president.retorna_vicepres());
			president.pass_card(president.find_lowest(1),president.retorna_vicepres(),president.retorna_vicebobo());
		}
		playing=president.mostra_mao_jogador_atual();
		if(president.posicao_jogador_atual()==0){
			std::cout<<"Suas cartas jogaveis são:\n";
			for(auto cardp : playing){
				if(cardp.numero()>last_played_card && president.how_many_in_the_hand(playing,cardp.numero())>=number_of_cards_played)
					std::cout << cardp.numero() << " ";
			}
			std::cout<<"\n";
			if(last_played_card!=-1){
				std::cout<<"A ultima carta jogada foi: ";
				for(int j=0;j<number_of_cards_played;j++)
					std::cout<<last_played_card<<' ';
				std::cout<<std::endl;
			}
			std::cout<<"Digite o numero da carta que deseja jogar, 0 para passar:";
			std::cin>>card;
			if(card!=0){
				count=president.how_many_in_the_hand(playing,card);
				president.joga_cartas(card,number_of_cards_played!=0?number_of_cards_played:count);
				last_played_card=card;
				number_of_cards_played = number_of_cards_played!=0?number_of_cards_played:count;
				if(president.mostra_mao_jogador_atual().size()==0 && president.esta_apto(president.posicao_jogador_atual())){
					president.muda_aptidao(president.posicao_jogador_atual());
					president.add_position(president.posicao_jogador_atual());
				}
				pass_count=0;
			}else pass_count++;
		}else{
			card=president.acha_carta_jogavel(playing,number_of_cards_played,last_played_card);
			if(card!=0){
				count=president.how_many_in_the_hand(playing,card);
				president.joga_cartas(card,number_of_cards_played!=0?number_of_cards_played:count);
				last_played_card=card;
				number_of_cards_played = number_of_cards_played!=0?number_of_cards_played:count;
				if(president.mostra_mao_jogador_atual().size()==0 && president.esta_apto(president.posicao_jogador_atual())){
					president.muda_aptidao(president.posicao_jogador_atual());
					president.add_position(president.posicao_jogador_atual());
				}
				pass_count=0;
			}else pass_count++;
		}

		if(last_played_card==13 || pass_count==(president.numero_jogadores_aptos()-1)){
			last_played_card=-1;
			number_of_cards_played=0;
		}else{
			if(president.posicao_jogador_atual()==3) president.muda_jogador_atual(0);
			else president.muda_jogador_atual(president.posicao_jogador_atual()+1);
		}
		president.fim_jogada();
	}
}

