/*
 * napoleao.cpp
 *
 *  Created on: 6 de jun de 2017
 *      Author: vitorrussi
 */
#include <iostream>
#include "napoleao.h"

#define MAO 5


Napoleao::Napoleao() {
	std::cout << "Inicio do construtor Napoleao" << std::endl;

	int jogadores, rodadas;
	std::cout << "NAPOLEAO: Insira o numero de jogadores: ";
	std::cin >> jogadores;
	while(jogadores < 1 || jogadores > 5) {
		std::cout << "NAPOLEAO: Numero invalido de jogadores!" << std::endl;
		std::cin >> jogadores;
	}
	std::cout << "NAPOLEAO: Insira o numero de rodadas: ";
	std::cin >> rodadas;
	while(rodadas < 1 || rodadas > 10000) {
		std::cout << "NAPOLEAO: Numero invalido de rodadas!" << std::endl;
		std::cin >> rodadas;
	}

	Regra *Rules = new Regra(jogadores,MAO,rodadas,rodadas*10,0,52, (Regra::modo_fim::rodadas));

	std::vector<std::string> nomes(jogadores);

	std::string meunome;
	std::cout << "NAPOLEAO: Insira o seu nome: ";
	std::cin >> meunome;
	nomes[0] = meunome;

	for(int i = 1; i < jogadores; i++) {
		std::string aux;
		std::cout << "NAPOLEAO: Insira o nome do adversario " << i << ": ";
		std::cin >> aux;
		nomes[i] = aux;
	}
	_jogadores.resize(jogadores);

	if(SIMULACAO) _jogadores[0] = new NapoleaoIA(nomes[0]);
	else _jogadores[0] = new NapoleaoPessoa(nomes[0]);


	for(int i = 1; i < jogadores; i++) {
		_jogadores[i] = new NapoleaoIA(nomes[i]);
	}

	_jogo = new Jogo(Rules, nomes);
	std::cout << "Fim do construtor Napoleao" << std::endl;

	_jogo->novo_monte();
}

Napoleao::~Napoleao() {
	delete (_jogo);
}


void Napoleao::inicia_jogo(){
	for(int rodada = 0; rodada < _jogo->max_rodadas(); rodada++){
		std::cout << "@@@@@@@@@@@@@@ INICIO DA RODADA " << rodada <<  "@@@@@@@@@@@@@@@@@" << std::endl;
		bool vit_declarante = inicia_rodada();
		limpa_mao();
		_jogo->distribuir();
		_jogo->restaurar_monte_inicial();
		_jogo->embaralhar_monte_principal();
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



}
//No construtor do jogo, as cartas ja foram distribuidas, por isso se distribui as cartas apenas no final;
bool Napoleao::inicia_rodada() {
	_aposta_max = 0;
	_declarante = 0;
	_declarante_rodadas = 0;
	for(unsigned int i = 0; i < _jogo->numero_de_jogadores(); i++){
		_jogo->muda_jogador_atual(i);
		std::cout << "Jogador "<< _jogo->nome_jogador_atual() << std::endl;
		pergunta_turnos(i);
	}

	_jogo->muda_jogador_atual(_declarante);
	std::cout << "O declarante sera " << _jogo->nome_jogador_atual() <<", pois ele escolheu o maior numero de rodadas, que sao " << _aposta_max << "!" << std::endl;

	declarante_escolhe_trunfo();

	int winner = _declarante;

	for(unsigned int i = 0; i < 5; i++){
		_turno = i+1;
		std::cout << "=========== TURNO " << _turno << " ===========" << std::endl;
		std::cout << "A rodada iniciara com o " << _jogo->nome_jogador_atual() << "." << std::endl;
		winner = inicio_turno(winner);
		_jogo->muda_jogador_atual(winner);
		std::cout << "O vencedor da rodada " << i+1 << " foi o " << _jogo->nome_jogador_atual() << std::endl;

		if(winner == _declarante) {
			std::cout << "->O declarante fez a rodada, totalizando " << ++_declarante_rodadas << " rodadas ganhas!" << std::endl;
		} else {
			std::cout << "->O declarante nao venceu a rodada! Ele esta com " << _declarante_rodadas << " ganhas!" << std::endl;
		}
	}

	if(_aposta_max == _declarante_rodadas) return true;
	else return false;
}

// Define qual o naipe de trunfo da rodada atual
void Napoleao::define_trunfo(Carta::Naipe trunfo) {
	_trunfo = trunfo;
	std::cout << "O trunfo escolhido foi: " << imprime_naipe(trunfo) << std::endl;
}

//pergunta pro jogador quantos turnos ele faz naquela rodada
void Napoleao::pergunta_turnos(int pos) {
	imprime_mao_atual();
	bool zero = true;
	std::cout << "-> A aposta maxima ate agora eh " << _aposta_max << std::endl;

	if((unsigned int)pos == _jogo->numero_de_jogadores() - 1 && _aposta_max == 0) {
		zero = false;
		_declarante = pos;
		std::cout << "**Como todos declararam 0, voce eh obrigado a declarar 1 ou mais" << std::endl;
	}

	std::cout << "Insira o numero de rodadas que voce acha que vai fazer: ";
	int trunfo_atual = _jogadores[pos]->jogador_pergunta_turnos();

	while(true) {
		if(trunfo_atual == 0 && zero) break;
		if(trunfo_atual > _aposta_max && trunfo_atual < 6) break;

		std::cout << "Entrada invalida, insira outra entrada: ";
		trunfo_atual = _jogadores[pos]->jogador_pergunta_turnos();
	}
	std::cout << "O jogador escolheu fazer " << trunfo_atual << " rodadas!" << std::endl;

	if(trunfo_atual > _aposta_max) {
		std::cout << "->A escolha foi a maior ate agora, se tornando a nova maior!" << std::endl;
		_aposta_max = trunfo_atual;
		_declarante = pos;
	} else {
		std::cout << "->A escolha foi menor que a maior!" << std::endl;
	}
	std::cout << std::endl;
}

//imprime a mao do jogador
void Napoleao::imprime_mao_atual(){
	std::vector<Carta> aux = _jogo->mostra_mao_jogador_atual();
	int cont = 0;
	bool mostra = _jogo->posicao_jogador_atual() == 0;

	if (mostra || MOSTRA) for(auto i:aux) {
		std::cout << "\t--> " << cont++ << "-) "<< imprime_carta(i) << std::endl;
		//if (mostra)	std::cout << "\t--> " << cont++ << "-) "<< imprime_carta(i) << std::endl;
		//else std::cout << "\t-->" << cont++ << "-) ???" << std::endl;
	}
	std::cout << std::endl;
}

std::string Napoleao::imprime_naipe(Carta::Naipe card) {
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

std::string Napoleao::imprime_naipe(int card) {
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

int Napoleao::inicio_turno(unsigned int primeiro) {
	std::cout << "@@@@@@ INICIO DO TURNO @@@@@@" << std::endl;
	int first = napoleao_jogada(primeiro); // pergunta a posicao da carta que a pessoa escolheu
	int winner = primeiro; // define o primeiro jogador tendo a maior carta

	Carta maior = carta_jogador_atual(first);
	std::cout << "->A carta escolhida foi: " << imprime_carta(maior) << std::endl;
	_naipe_inicial = maior.naipe();
	std::cout << "O naipe inicial desse turno eh o " << imprime_naipe(_naipe_inicial) << std::endl;

	_jogo->move_carta_jm(maior,primeiro,1);

	for(unsigned int i = primeiro+1; i != primeiro; i++){
		if(i == _jogo->numero_de_jogadores()){
			i = -1;
			continue;
		}
		Carta topo = carta_maior();
		std::cout << "A maior carta ate agora eh: " << imprime_carta(topo) << std::endl;

		_jogo->muda_jogador_atual(i);
		int jogada = napoleao_jogada(i);
		Carta nova = carta_jogador_atual(jogada);
		std::cout << "->A carta escolhida foi da: " << imprime_carta(nova) << std::endl;
		if(compara_cartas(topo,nova)){
			_jogo->move_carta_jm(nova,i,1,false);
		} else {
			winner = i;
			_jogo->move_carta_jm(nova,i,1);
		}
	}
	std::cout << "A maior carta desse turno foi: " << imprime_carta(carta_maior()) << std::endl;
	std::cout << "@@@@@@ FIM DO TURNO @@@@@@" << std::endl;
	return winner;

}

int Napoleao::napoleao_jogada(int pos){
	std::cout << "Jogador " << _jogadores[pos]->nome() << ":" << std::endl;
	imprime_mao_atual();
	std::cout << "Escolha a carta a ser jogada: ";

	int jogada = _jogadores[pos]->jogador_jogada();

	while(jogada < 0 || jogada > (int)_jogo->cartas_jogadores() - (int)_turno) {
		std::cout << "Escolha invalida!" << std::endl;
		jogada = _jogadores[pos]->jogador_jogada();
	}
	return jogada;

}

void Napoleao::declarante_escolhe_trunfo(){
	int trunfo;
	std::cout << "\nDeclarante " << _jogo->nome_jogador_atual() << ", escolha o naipe de trunfo:" << std::endl;
	std::cout << "0-) Espadas\n1-) Copas\n2-) Paus\n3-) Ouros\n\tESCOLHA: ";
	trunfo = _jogadores[_declarante]->escolhe_trunfo();
	while(trunfo < 0 || trunfo > 3){
		std::cout << "Entrada Invalida" << std::endl;
		trunfo = _jogadores[_declarante]->escolhe_trunfo();
	}
	define_trunfo((Carta::Naipe) trunfo);
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

std::string Napoleao::imprime_carta(Carta card) {
	std::string ret, aux = std::to_string(card.numero());
	ret.append(aux);
	ret.append(" de ");
	ret.append(imprime_naipe(card.naipe()));
	return ret;
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

void Napoleao::imprime_pontuacao() {
	int atual = _jogo->posicao_jogador_atual();
	int i;
	for(i = atual+1; i != atual; i++){
		if(i == (int)_jogo->numero_de_jogadores()) { i = -1; continue;}
		_jogo->muda_jogador_atual(i);
		std::cout << "Pontos: " << _jogadores[i]->nome() << " = " << _jogo->pontuacao_jogador_atual() << std::endl;
	}
	_jogo->muda_jogador_atual(i);
			std::cout << "Pontos: " << _jogadores[i]->nome() << " = " << _jogo->pontuacao_jogador_atual() << std::endl;
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

