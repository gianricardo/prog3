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
	RegraPresidente *rule_president = new RegraPresidente(4,13,5,-1,-1,52,Regra::modo_fim::rodadas);
	JogoPresidente president(rule_president,{player_name,"West","North","East"});
	std::vector<Carta> playing;
	president.novo_monte();
	president.novo_monte();
	president.novo_monte();
	president.novo_monte();
	int card;
	std::string decision;
	int last_played_card=-1;
	int number_of_cards_played=0;
	int wining;
	int count;
	unsigned int pass_count=0;
	while(president.jogando()){
		playing=president.mostra_mao_jogador_atual();
		if(president.posicao_jogador_atual()==0 && president.esta_apto(0)){
			for(auto cardp : playing){
				std::cout << cardp.numero() << " ";
			}
			std::cout << "\n";
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
				std::cout << "\n";
			}
			std::cout<<"Digite o numero da carta que deseja jogar, 0 para passar:";
			std::cin>>card;
			if(card!=0 && card>last_played_card){
				wining=president.posicao_jogador_atual();
				count=president.how_many_in_the_hand(playing,card);
				president.joga_cartas(card,number_of_cards_played!=0?number_of_cards_played:count);
				last_played_card=card;
				number_of_cards_played = number_of_cards_played!=0?number_of_cards_played:count;
				if(president.mostra_mao_jogador_atual().size()==0 && president.esta_apto((int)president.posicao_jogador_atual())==true){
					president.muda_aptidao((int)president.posicao_jogador_atual());
					president.add_position((int)president.posicao_jogador_atual());
				}
				pass_count=0;
			}else pass_count++;
		}else if(president.esta_apto((int)president.posicao_jogador_atual())){
			card=president.acha_carta_jogavel(playing,number_of_cards_played,last_played_card);
			if(card!=0){
				wining=president.posicao_jogador_atual();
				count=president.how_many_in_the_hand(playing,card);
				president.joga_cartas(card,number_of_cards_played!=0?number_of_cards_played:count);
				last_played_card=card;
				number_of_cards_played = number_of_cards_played!=0?number_of_cards_played:count;
				if(president.mostra_mao_jogador_atual().size()==0 && president.esta_apto((int)president.posicao_jogador_atual())){
					president.muda_aptidao((int)president.posicao_jogador_atual());
					president.add_position((int)president.posicao_jogador_atual());
				}
				pass_count=0;
			}else pass_count++;
		}
		std::cout<<"A carta jogada foi:"<<last_played_card<<std::endl;
		std::cout<<"ela foi jogada pelo jogador: "<<wining<<std::endl;
		if(last_played_card==13 || pass_count==(president.numero_jogadores_aptos()-1)){
			if(president.esta_apto(wining))	president.muda_jogador_atual(wining);
			last_played_card=-1;
			number_of_cards_played=0;
		}
		if(last_played_card!=-1 || !president.esta_apto(president.posicao_jogador_atual())){
			if(president.posicao_jogador_atual()==3) president.muda_jogador_atual(0);
			else president.muda_jogador_atual(president.posicao_jogador_atual()+1);
		}
		std::cout<<"Jogadores aptos: "<<president.numero_jogadores_aptos()<<std::endl;
		std::cout<<"pass_count: "<<pass_count<<std::endl;
		if(president.numero_jogadores_aptos()==0){
			last_played_card=-1;
			number_of_cards_played=0;
		}
		president.fim_jogada();
	}
	return 0;
}

