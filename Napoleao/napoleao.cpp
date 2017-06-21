/*
 * napoleao.cpp
 *
 *  Created on: 6 de jun de 2017
 *      Author: vitorrussi
 */
#include <iostream>
#include "napoleao.h"

Napoleao::Napoleao(Regra *Rules, std::vector<std::string> nomes, int jogadores, bool SIMULACAO) {
	std::cout << "Inicio do construtor Napoleao" << std::endl;

	_jogadores.resize(jogadores);

	if(SIMULACAO) _jogadores[0] = std::make_unique<NapoleaoIA>(nomes[0]);
	else _jogadores[0] = std::make_unique<NapoleaoPessoa>(nomes[0]);


	for(int i = 1; i < jogadores; i++) {
		_jogadores[i] = std::make_unique<NapoleaoIA>(nomes[i]);
	}

	_jogo = std::make_unique<Jogo>(Rules, nomes);
	std::cout << "Fim do construtor Napoleao" << std::endl;

	_jogo->novo_monte();
}

Napoleao::~Napoleao() {
}


int Napoleao::numero_de_jogadores() {
	return _jogo->numero_de_jogadores();
}

std::string Napoleao::nome_jogador_atual() {
	return _jogo->nome_jogador_atual();
}

void Napoleao::muda_jogador_atual(unsigned int pos) {
	_jogo->muda_jogador_atual(pos);
}

int Napoleao::aposta_maxima(){
	return _aposta_max;
}

void Napoleao::define_declarante(int pos) {
	_declarante = pos;
}

bool Napoleao::pergunta_turnos(int pos, bool zero) {
	int trunfo_atual = _jogadores[pos]->jogador_pergunta_turnos();

	if(trunfo_atual != 0 && zero) {
		if(trunfo_atual < _aposta_max || trunfo_atual > 5) return false;
	}

	if(trunfo_atual > _aposta_max) {
		_aposta_max = trunfo_atual;
		_declarante = pos;
	}
	return true;
}

std::vector<Carta> Napoleao::mostra_mao_jogador_atual(){
	return _jogo->mostra_mao_jogador_atual();
}

int Napoleao::posicao_jogador_atual(){
	return _jogo->posicao_jogador_atual();
}

int Napoleao::posicao_declarante(){
	return _declarante;
}

bool Napoleao::declarante_escolhe_trunfo(){
	int trunfo;
	trunfo = _jogadores[_declarante]->escolhe_trunfo();
	if(trunfo < 0 || trunfo > 3) return false;
	define_trunfo((Carta::Naipe) trunfo);
	return true;
}

Carta::Naipe Napoleao::naipe_trunfo(){
	return _trunfo;
}

int Napoleao::posicao_vencedor_turno(){
	return _vencedor_turno;
}

bool Napoleao::declarante_venceu_turno(){
	_turno++;
	if (_vencedor_turno == _declarante) {
		_declarante_turnos++;
		return true;
	}
	return false;
}

int Napoleao::declarante_turnos_feitos(){
	return _declarante_turnos;
}

bool Napoleao::declarante_venceu_rodada(){
	_turno = 1;
	if(_declarante_turnos == _aposta_max) {
		_jogo->jogador_soma_pontos(_aposta_max,_declarante);
		return true;
	} else {
		for(unsigned int i = 0; i < _jogo->numero_de_jogadores(); i++){
			if ((int)i == _declarante) continue;
			_jogo->jogador_soma_pontos(_aposta_max,(int)i);
		}
	return false;
	}
}

int Napoleao::max_rodadas(){
	return _jogo->max_rodadas();
}


/*void Napoleao::inicia_jogo(){
	std::cout << "NAPOLEAO: Inicio inicia jogo" << std::endl;
	for(int rodada = 0; rodada < _jogo->max_rodadas(); rodada++){
		std::cout << "@@@@@@@@@@@@@@ INICIO DA RODADA " << rodada <<  "@@@@@@@@@@@@@@@@@" << std::endl;
		bool vit_declarante = inicia_rodada();

		if(vit_declarante) {
			std::cout << "O declarante venceu a rodada! Ele ganhou " <<_aposta_max << " pontos!" << std::endl;
			_jogo->jogador_soma_pontos(_aposta_max,_declarante);
		} else {
			std::cout << "O declarante perdeu a rodada! Todos, menos ele, ganharam " <<_aposta_max << " pontos!" << std::endl;
			for(unsigned int i = 0; i < _jogo->numero_de_jogadores(); i++){
				if ((int)i == _declarante) continue;
				_jogo->jogador_soma_pontos(_aposta_max,(int)i);
			}
		}
		std::cout << "A pontuacao ate agora eh:" << std::endl;
		imprime_pontuacao();
		std::cout << "@@@@@@ FIM DA RODADA @@@@@@" << std::endl;
	}
	_jogo->muda_jogador_atual(_jogo->numero_de_jogadores()-1);
	std::cout << "$$$ PONTUACAO FINAL $$$" << std::endl;;
	imprime_pontuacao();

	fim_do_jogo();
	std::cout << "NAPOLEAO: Fim inicia jogo" << std::endl;
}*/

void Napoleao::rodada_conf_inicio() {
	_aposta_max = 0;
	_declarante = 0;
	_declarante_turnos = 0;
	_vencedor_turno = 0;
	limpa_mao();
	_jogo->restaurar_monte_inicial();
	_jogo->embaralhar_monte_principal();
	_jogo->distribuir();
}

// Define qual o naipe de trunfo da rodada atual
void Napoleao::define_trunfo(Carta::Naipe trunfo) {
	_trunfo = trunfo;
}

bool Napoleao::primeira_jogada(int pos){
	int first = napoleao_jogada(pos); // pergunta a posicao da carta que a pessoa escolheu
	if(first == -1) return false;

	_vencedor_turno = pos;

	Carta maior = carta_jogador_atual(first);
	_naipe_inicial = maior.naipe();
	_jogo->move_carta_jm(maior,pos,1);
	return true;
}

Carta Napoleao::jogada_normal(int pos){
	int jogada = napoleao_jogada(pos); // pergunta a posicao da carta que a pessoa escolheu
	if(jogada == -1) {
		Carta ret(0, (typename Carta::Naipe) 0);
		return ret;
	}
	Carta nova = carta_jogador_atual(jogada);
	return nova;
}

void Napoleao::joga_monte(Carta nova, int pos){
	Carta topo = carta_maior();
	if(compara_cartas(topo,nova)){
		_jogo->move_carta_jm(nova,pos,1,false);
	} else {
		_jogo->move_carta_jm(nova,pos,1);
		_vencedor_turno = pos;
	}
}


int Napoleao::napoleao_jogada(int pos){
	int jogada = _jogadores[pos]->jogador_jogada();

	if(jogada < 0 || jogada > (int)_jogo->cartas_jogadores() - (int)_turno) {
		std::cout << "NAPOLEAO JOGADA Carta invalida" << std::endl;
		return -1;
	}
	std::cout << "NAPOLEAO JOGADA Carta valida" << std::endl;
	return jogada;

}


// Retorna a carta do jogador atual. Recebe como argumento a posicao da carta na mao do jogador.
Carta Napoleao::carta_jogador_atual(int pos) {
	std::vector<Carta> aux = _jogo->mostra_mao_jogador_atual();
	return aux[pos];
}

Carta Napoleao::carta_maior(){
	auto monte_aux = _jogo->mostra_monte(1);
	if(monte_aux[0].first == false) {
		_jogo->vira_carta_monte(1);
		monte_aux = _jogo->mostra_monte(1);
	}
	return monte_aux[0].second;
}

bool Napoleao::compara_cartas(Carta topo, Carta nova){
	if(topo.naipe() == _trunfo && nova.naipe() == _trunfo) {
		if(topo.numero() >= nova.numero()) return true;
		else return false;
	}

	if(topo.naipe() == _trunfo) return true;
	if(nova.naipe() == _trunfo) return false;

	if(topo.naipe() == _naipe_inicial && nova.naipe() == _naipe_inicial) {
		if(topo.numero() >= nova.numero()) return true;
		else return false;
	}

	if(topo.naipe() == _naipe_inicial) return true;
	if(nova.naipe() == _naipe_inicial) return false;

	if(topo.numero() >= nova.numero()) return true;
	else return false;

}

std::vector<int> Napoleao::vetor_pontuacao() {
	int atual = _jogo->posicao_jogador_atual();
	int i;
	std::vector<int> pontos(_jogo->numero_de_jogadores());
	for(i = atual+1; i != atual; i++){
		if(i == (int)_jogo->numero_de_jogadores()) { i = -1; continue;}
		_jogo->muda_jogador_atual(i);
		pontos[i] = _jogo->pontuacao_jogador_atual();
	}
	_jogo->muda_jogador_atual(i);
	pontos[i] = _jogo->pontuacao_jogador_atual();

	return pontos;
}


void Napoleao::fim_do_jogo() {
	std::cout << "$$$$$$$$$$$$$$$$$$$$ FIM DE JOGO $$$$$$$$$$$$$$$" << std::endl;
	int num = (int)_jogo->numero_de_jogadores();
	std::vector<int> pontuacao(num);
	for(int i = 0; (int)i < num; i++) {
		_jogo->muda_jogador_atual(i);
		pontuacao[i] = _jogo->pontuacao_jogador_atual();
	}
	auto max = std::max_element(pontuacao.begin(),pontuacao.end());
	int qtd = std::count(pontuacao.begin(),pontuacao.end(),*max);

	if(qtd == 1) {
		std::cout << "Temos um unico vencedor!!" << std::endl;
	} else {
		std::cout << "Tivemos um empate com " << qtd << " jogadores!" << std::endl;
	}

}

void Napoleao::limpa_mao() {
		for(unsigned i = 0; i < _jogo->numero_de_jogadores(); i++) _jogo->esvazia_mao(i);
}

