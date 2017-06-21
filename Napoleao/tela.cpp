/*
 * tela.cpp
 *
 *  Created on: 20 de jun de 2017
 *      Author: vitorrussi
 */
#include <iostream>
#include "tela.h"

using namespace p3;
Tela::Tela() {
	std::cout << "Inicio do construtor Tela" << std::endl;
	int jogadores, rodadas;
	std::cout << "TELA: Insira o numero de jogadores: ";
	std::cin >> jogadores;
	while(jogadores < 1 || jogadores > 5) {
		std::cout << "TELA: Numero invalido de jogadores!" << std::endl;
		std::cin >> jogadores;
	}
	std::cout << "TELA: Insira o numero de rodadas: ";
	std::cin >> rodadas;
	while(rodadas < 1 || rodadas > 10000) {
		std::cout << "TELA: Numero invalido de rodadas!" << std::endl;
		std::cin >> rodadas;
	}
	Regra *Rules = new Regra(jogadores,MAO,rodadas,rodadas*10,0,52, (Regra::modo_fim::rodadas));
	std::vector<std::string> nomes(jogadores);
	std::cout << "TELA: Insira o seu nome: ";
	std::cin >> nomes[0];
	for(int i = 1; i < jogadores; i++) {
		std::cout << "TELA: Insira o nome do adversario " << i << ": ";
		std::cin >> nomes[i];
	}
	_nap = std::make_unique<Napoleao>(Rules, nomes, jogadores, SIMULACAO);
}

Tela::~Tela() {
}


void Tela::inicia_jogo() {
	std::cout << "TELA: Inicio inicia jogo" << std::endl;
	_nap->jogo_conf_inicio();
	for(int rodada = 0; rodada < _nap->max_rodadas(); rodada++){
		std::cout << "@@@@@@@@@@@@@@ INICIO DA RODADA " << rodada <<  "@@@@@@@@@@@@@@@@@" << std::endl;

		tela_inicia_rodada();
		if(_nap->declarante_venceu_rodada()) {
			std::cout << "O declarante venceu a rodada! Ele ganhou " <<_nap->aposta_maxima() << " pontos!" << std::endl;
		} else {
			std::cout << "O declarante perdeu a rodada! Todos, menos ele, ganharam " <<_nap->aposta_maxima() << " pontos!" << std::endl;
		}

		std::cout << "A pontuacao ate agora eh:" << std::endl;
		imprime_pontuacao();
		std::cout << "@@@@@@ FIM DA RODADA @@@@@@" << std::endl;
	}
	_nap->muda_jogador_atual(_nap->numero_de_jogadores()-1);
	std::cout << "$$$ PONTUACAO FINAL $$$" << std::endl;;
	imprime_pontuacao();

}

void Tela::tela_inicia_rodada() {
	std::cout << "TELA: Inicio inicia rodada" << std::endl;
	_nap->rodada_conf_inicio();
	int declarante = escolhe_declarante();
	_nap->muda_jogador_atual(declarante);
	std::cout << "O declarante sera " << _nap->nome_jogador_atual() << "!" << std::endl;
	declarante_escolhe_trunfo();

	int winner = _nap->posicao_declarante();

	for(unsigned int i = 0; i < 5; i++){
		std::cout << "=========== TURNO " << i+1 << " ===========" << std::endl;
		std::cout << "A rodada iniciara com o " << _nap->nome_jogador_atual() << "." << std::endl;
		inicio_turno(winner);
		winner = _nap->posicao_vencedor_turno();
		_nap->muda_jogador_atual(winner);
		std::cout << "O vencedor da rodada " << i+1 << " foi o " << _nap->nome_jogador_atual() << std::endl;

		if(_nap->declarante_venceu_turno()) {
			std::cout << "->O declarante fez a rodada, totalizando " << _nap->declarante_turnos_feitos() << " rodadas ganhas!" << std::endl;
		} else {
			std::cout << "->O declarante nao venceu a rodada! Ele esta com " << _nap->declarante_turnos_feitos() << " ganhas!" << std::endl;
		}
	}

}

void Tela::pergunta_turnos(int pos) {
	imprime_mao_atual();
	bool zero = true;
	std::cout << "-> A aposta maxima ate agora eh " << _nap->aposta_maxima() << std::endl;

	if(pos == _nap->numero_de_jogadores() - 1 && _nap->aposta_maxima() == 0) {
		zero = false;
		_nap->define_declarante(pos);
		std::cout << "**Como todos declararam 0, voce eh obrigado a declarar 1 ou mais" << std::endl;
	}

	std::cout << "Insira o numero de rodadas que voce acha que vai fazer: ";
	bool trunfo_atual = _nap->pergunta_turnos(pos, zero);

	while(trunfo_atual == false) {
		std::cout << "Entrada invalida, insira outra entrada: ";
		trunfo_atual = _nap->pergunta_turnos(pos, zero);
	}
	std::cout << std::endl;
}

void Tela::imprime_mao_atual() {
	std::vector<Carta> aux = _nap->mostra_mao_jogador_atual();
	int cont = 0;
	bool mostra = _nap->posicao_jogador_atual() == 0;

	if (mostra || MOSTRA) for(auto i:aux) {
		std::cout << "\t--> " << cont++ << "-) "<< imprime_carta(i) << std::endl;
		//if (mostra)	std::cout << "\t--> " << cont++ << "-) "<< imprime_carta(i) << std::endl;
		//else std::cout << "\t-->" << cont++ << "-) ???" << std::endl;
	}
	std::cout << std::endl;
}

std::string Tela::imprime_carta(Carta card) {
	std::string ret, aux = std::to_string(card.numero());
	ret.append(aux);
	ret.append(" de ");
	ret.append(imprime_naipe(card.naipe()));
	return ret;
}

std::string Tela::imprime_naipe(Carta::Naipe card) {
	switch(card) {
	case Carta::Naipe::Copas:
		return "Copas";
	case Carta::Naipe::Paus:
		return "Paus";
	case Carta::Naipe::Espadas:
		return "Espadas";
	case Carta::Naipe::Ouros:
		return "Ouros";
	default:
		return "Nao era pra chegar aqui";
	}
}

std::string Tela::imprime_naipe(int card) {
	switch(card) {
	case (int)Carta::Naipe::Copas:
		return "Copas";
	case (int)Carta::Naipe::Paus:
		return "Paus";
	case (int)Carta::Naipe::Espadas:
		return "Espadas";
	case (int)Carta::Naipe::Ouros:
		return "Ouros";
	default:
		return "Nao era pra chegar aqui";
	}
}

int Tela::escolhe_declarante(){
	for(int i = 0; i < _nap->numero_de_jogadores(); i++){
		_nap->muda_jogador_atual(i);
		std::cout << "Jogador "<< _nap->nome_jogador_atual() << std::endl;
		pergunta_turnos(i);
		if(_nap->aposta_maxima() == 5) break;
	}

	return _nap->posicao_declarante();
}

void Tela::declarante_escolhe_trunfo() {
	std::cout << "\nDeclarante " << _nap->nome_jogador_atual() << ", escolha o naipe de trunfo:" << std::endl;
	std::cout << "0-) Espadas\n1-) Copas\n2-) Paus\n3-) Ouros\n\tESCOLHA: ";

	bool escolha = _nap->declarante_escolhe_trunfo();
	while(!escolha){
		std::cout << "DECLARANTE ESCOLHE TRUNFO Entrada Invalida" << std::endl;
		escolha = _nap->declarante_escolhe_trunfo();
	}
	Carta::Naipe trunfo = _nap->naipe_trunfo();
	std::cout << "O trunfo escolhido foi: " << imprime_naipe(trunfo) << "!!" << std::endl;
}

void Tela::inicio_turno(unsigned int primeiro){
	std::cout << "@@@@@@ INICIO DO TURNO @@@@@@" << std::endl;

	primeira_jogada(primeiro); // pergunta a posicao da carta que a pessoa escolheu

	for(int i = primeiro+1; i != (int)primeiro; i++){
		if(i == _nap->numero_de_jogadores()){
			i = -1;
			continue;
		}
		Carta topo = _nap->carta_maior();
		std::cout << "A maior carta ate agora eh: " << imprime_carta(topo) << std::endl;
		_nap->muda_jogador_atual(i);
		jogada_normal(i);
	}
	std::cout << "A maior carta desse turno foi: " << imprime_carta(_nap->carta_maior()) << std::endl;
	std::cout << "@@@@@@ FIM DO TURNO @@@@@@" << std::endl;

}

void Tela::primeira_jogada(int primeiro) {
	std::cout << "Jogador " << _nap->nome_jogador_atual() << std::endl;
	imprime_mao_atual();
	bool escolha = _nap->primeira_jogada(primeiro);

	while(escolha == false) {
		std::cout << "Escolha invalida!" << std::endl;
		escolha = _nap->primeira_jogada(primeiro);
	}
	Carta first = _nap->carta_maior();
	std::cout << "->A carta escolhida foi: " << imprime_carta(first) << std::endl;
	std::cout << "O naipe inicial desse turno eh o " << imprime_naipe(first.naipe()) << std::endl;

}

void Tela::jogada_normal(unsigned int pos) {
	std::cout << "Jogador " << _nap->nome_jogador_atual() << std::endl;
	imprime_mao_atual();
	Carta escolha = _nap->jogada_normal(pos);

	while(escolha.numero() == 0){
		std::cout << "Escolha invalida!" << std::endl;
		escolha = _nap->jogada_normal(pos);
	}

	std::cout << "->A carta escolhida foi: " << imprime_carta(escolha) << std::endl;
	_nap->joga_monte(escolha,pos);
}

void Tela::imprime_pontuacao() {
	std::vector<int> pontos = _nap->vetor_pontuacao();
	int atual = _nap->posicao_jogador_atual();
	int i;
	for(i = atual+1; i != atual; i++){
		if(i == (int)_nap->numero_de_jogadores()) { i = -1; continue;}
		_nap->muda_jogador_atual(i);
		std::cout << "Pontos: " << _nap->nome_jogador_atual() << " = " << pontos[i] << std::endl;
	}
	_nap->muda_jogador_atual(i);
	std::cout << "Pontos: " << _nap->nome_jogador_atual() << " = " << pontos[i] << std::endl;
}


















