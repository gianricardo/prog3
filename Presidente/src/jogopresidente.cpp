/*
 * jogopresidente.cpp
 *
 *  Created on: 8 de jun de 2017
 *      Author: adolfo
 */

#include "jogopresidente.h"

JogoPresidente::JogoPresidente(p3::Regra *r,std::vector<std::string> p) : p3::Jogo(r,p){
}

JogoPresidente::~JogoPresidente() {
}

int JogoPresidente::acha_carta_jogavel(std::vector<Carta> v,int numerocartas,int valor){
	int jogavel=0;
	for(auto k:v){
		if(k.numero()>valor && how_many_in_the_hand(v,k.numero())>=numerocartas){
			jogavel=k.numero();
			break;
		}
	}
	return jogavel;
}

void JogoPresidente::joga_cartas(int carta,int numerocartas){
	//retirar as primeiras numerocartas cartas com numero igual a carta
	int i=0;
	while(i!=numerocartas){
		for(int j=0;j<4;j++){
			if(move_carta_jm(p3::Carta(carta,(Carta::Naipe)j),_jog_atual,i+1,true)){
				i++;
				break;
			}
		}
	}
}

int JogoPresidente::how_many_in_the_hand(std::vector<Carta> v,int valor){
	int count=0;
	for(auto c : v){
		if(c.numero()==valor) count++;
	}
	return count;
}

void JogoPresidente::fim_jogada(){
	if(!_jogando) return;
	if(numero_jogadores_aptos()==0){
		jogador_soma_pontos(3,_positions[0]);
		jogador_soma_pontos(2,_positions[1]);
		jogador_soma_pontos(1,_positions[2]);
		limpa_outros_montes();
		verifica_fim_de_jogo();
		restaurar_monte_inicial();
		embaralhar_monte_principal();
		distribuir();
		muda_aptidao(0);
		muda_aptidao(1);
		muda_aptidao(2);
		muda_aptidao(3);
		pass_card(find_highest(2,retorna_bobo()),retorna_bobo(),retorna_pres());
		pass_card(find_lowest(2,retorna_pres()),retorna_pres(),retorna_bobo());
		pass_card(find_highest(1,retorna_vicebobo()),retorna_vicebobo(),retorna_vicepres());
		pass_card(find_lowest(1,retorna_vicepres()),retorna_vicepres(),retorna_vicebobo());
		_rodada++;
		muda_jogador_atual(retorna_pres());
		_positions.clear();
		std::cout<<"============================="<<std::endl;
	}
}

void JogoPresidente::add_position(int jogador){
	_positions.push_back(jogador);
}

int JogoPresidente::retorna_bobo(){
	return _positions[3];
}

int JogoPresidente::retorna_pres(){
	return _positions[0];
}

int JogoPresidente::retorna_vicebobo(){
	return _positions[2];
}

int JogoPresidente::retorna_vicepres(){
	return _positions[1];
}

std::vector<int> JogoPresidente::find_highest(int numbercards,std::size_t player){
	std::vector<int> cards;
	int maior=0;
	int maior2=0;
	for(auto c : mostra_mao_jogador(player)){
		if(c.numero() > maior){
			maior2=maior;
			maior=c.numero();
		}
	}
	cards.push_back(maior);
	if(numbercards>1) cards.push_back(maior2);
	return cards;
}

std::vector<int> JogoPresidente::find_lowest(int numbercards,std::size_t player){
	std::vector<int> cards;
	int menor=14;
	int menor2=14;
	for(auto c : mostra_mao_jogador(player)){
		if(c.numero() < menor){
			menor2=menor;
			menor=c.numero();
		}
	}
	cards.push_back(menor);
	cards.push_back(menor2);
	return cards;
}

void JogoPresidente::pass_card(std::vector<int> v,int pos1,int pos2){
	unsigned int i=0;
	while(i!=v.size()){
		for(int j=0;j<4;j++){
			if(move_carta_jj(p3::Carta(v[i],(Carta::Naipe)j),pos1,pos2)){
				i++;
				break;
			}
		}
	}
}

void JogoPresidente::verifica_fim_de_jogo(){
	if((int)max_rodadas()== (int)rodada()){
		declara_fim_de_jogo();
		verifica_vitoria();
	}
}

void JogoPresidente::verifica_vitoria(){
	verifica_jogador_pontuacao_maxima();
}

void JogoPresidente::verifica_jogador_pontuacao_maxima(){
	int maior_pontuacao = 0;
	int jogador_vencedor = 0;
	for(std::size_t pos_jogador = 0; pos_jogador < _mesa.numero_jogadores(); pos_jogador++)
	{
		if(_mesa.ver_jogador(pos_jogador).pontuacao() > maior_pontuacao)
		{
			maior_pontuacao = _mesa.ver_jogador(pos_jogador).pontuacao();
			jogador_vencedor = (int)pos_jogador;
		}
	}
	declara_vencedor(jogador_vencedor);
}

void JogoPresidente::declara_vencedor(std::size_t j){
	std::cout<<"O jogador vencedor foi o da posicao "<<j<<std::endl;
}

void JogoPresidente::verifica_jogador_unico(){
	std::size_t jog_aptos = 0;
	std::size_t last = _jog_atual;
	for(std::size_t i = 0; i < _mesa.numero_jogadores(); i++){
		if(_mesa.ver_jogador(i).esta_apto()){
			jog_aptos++;
			last = i;
		}
	}
	if(jog_aptos > 1) return;
	for(auto c : mostra_mao_jogador(last)){
		_mesa.jogador_tira_carta(c,last);
	}
	add_position(last);
	muda_aptidao(last);
}
