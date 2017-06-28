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
}

Tela::~Tela() {
}

void Tela::define(MainWindow *m){
    w = m;
    int jogadores, rodadas;
    jogadores = 2;
    std::vector<std::string> nomes(jogadores);
    w->construindo();
    nomes[0] = w->nome_jogador();
    nomes[1] = w->nome_adversario();
    rodadas = w->numero_rodadas();
    w->informacao("Comecando o jogo!");
    w->rodada_atual(0);
    Regra *Rules = new Regra(jogadores,MAO,rodadas,rodadas*10,0,52, (Regra::modo_fim::rodadas));
    _nap = std::make_unique<Napoleao>(Rules, nomes, jogadores, SIMULACAO);
}

void Tela::inicia_jogo() {
    _nap->jogo_conf_inicio();
    for(int rodada = 0; rodada < _nap->max_rodadas(); rodada++){
        w->rodada_atual(rodada+1);
        tela_inicia_rodada();
        if(_nap->declarante_venceu_rodada()) {
            w->rodada_fim(_nap->posicao_declarante(), _nap->aposta_maxima(), true);
        } else {
            w->rodada_fim(_nap->posicao_declarante(), _nap->aposta_maxima(), false);
        }
        imprime_pontuacao();
    }
    w->fim_do_jogo();

}

void Tela::tela_inicia_rodada() {
    _nap->rodada_conf_inicio();
    w->inicio_rodada();
    w->sleep(1000);
    int declarante = escolhe_declarante();
    w->aposta_max(_nap->aposta_maxima());
    _nap->muda_jogador_atual(declarante);
    w->declarante(_nap->nome_jogador_atual());
    w->sleep(1000);
    declarante_escolhe_trunfo();
    w->turnos_vencidos(0);
    int winner = _nap->posicao_declarante();

    for(unsigned int i = 0; i < 5; i++){
        w->informacao("O turno iniciara com o " + _nap->nome_jogador_atual() + ".");
        w->sleep(1000);
        inicio_turno(winner);
        winner = _nap->posicao_vencedor_turno();
        _nap->muda_jogador_atual(winner);
        w->informacao("O vencedor do turno " + std::to_string(i+1) + " foi o " + _nap->nome_jogador_atual());

        if(_nap->declarante_venceu_turno()) {
            w->informacao("->O declarante fez o turno, totalizando " + std::to_string(_nap->declarante_turnos_feitos()) + " rodadas ganhas!");
            w->turnos_vencidos(_nap->declarante_turnos_feitos());
        } else {
            w->turnos_vencidos(_nap->declarante_turnos_feitos());
        }
        w->sleep(1000);
    }

}

void Tela::pergunta_turnos(int pos) {
    imprime_mao_atual();
    bool zero = true;
    w->sleep(1000);
    if(pos == _nap->numero_de_jogadores() - 1 && _nap->aposta_maxima() == 0) {
        zero = false;
        _nap->define_declarante(pos);
        w->informacao("**Como todos declararam 0, voce eh obrigado a declarar 1 ou mais");
    }
    w->informacao("Jogador " + _nap->nome_jogador_atual() + ", insira o numero de turnos que voce acha que vai fazer: ");
    int trunfo_atual = _nap->pergunta_turnos(pos, zero);

    if(trunfo_atual == -1) {
        int aposta = w->pergunta_turnos();
        _nap->set_aposta_maxima(aposta);
        _nap->define_declarante(0);
    }
    while(trunfo_atual == 0) {
        trunfo_atual = _nap->pergunta_turnos(pos, zero);
    }
}

void Tela::imprime_mao_atual() {
    std::vector<Carta> aux = _nap->mostra_mao_jogador_atual();
    int cont = 0;
    bool mostra = _nap->posicao_jogador_atual() == 0;

    for(auto i:aux) {
        std::string card = imprime_carta(i);
        w->imprime_carta(card, mostra || MOSTRA ,++cont, _nap->posicao_jogador_atual() );
    }
}

std::string Tela::imprime_carta(Carta card) {

    std::string ret, aux = std::to_string(card.numero());
    ret.append(":/baralho/");
    ret.append(std::to_string((int)card.naipe()  ) );
    ret.append(aux);
    ret.append(".png");
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
        pergunta_turnos(i);
        if(_nap->aposta_maxima() == 5) break;
    }

    return _nap->posicao_declarante();
}

void Tela::declarante_escolhe_trunfo() {
    w->informacao("Declarante " + _nap->nome_jogador_atual() + ", escolha o naipe de trunfo:");
    int escolha = _nap->declarante_escolhe_trunfo();

    if (escolha == -1) {
        int naipe = w->pergunta_naipe();
        _nap->define_naipe(naipe);
    }

    while(escolha == 0){;
        escolha = _nap->declarante_escolhe_trunfo();
    }
    Carta::Naipe trunfo = _nap->naipe_trunfo();
    w->trunfo_rodada((int) trunfo);
    w->sleep(1000);
}

void Tela::inicio_turno(unsigned int primeiro){
    w->inicio_turno();
    primeira_jogada(primeiro); // pergunta a posicao da carta que a pessoa escolheu

    for(int i = primeiro+1; i != (int)primeiro; i++){
        if(i == _nap->numero_de_jogadores()){
            i = -1;
            continue;
        }
        Carta topo = _nap->carta_maior();
        w->carta_monte(imprime_carta(topo));
        _nap->muda_jogador_atual(i);
        w->sleep(1000);
        jogada_normal(i);
    }
    Carta topo = _nap->carta_maior();
    w->carta_monte(imprime_carta(topo));
    w->sleep(1500);

}

void Tela::primeira_jogada(int primeiro) {
    w->informacao("Jogador " + _nap->nome_jogador_atual() + ", escolha a carta a ser jogada!");
    imprime_mao_atual();
    int escolha = _nap->primeira_jogada(primeiro);
    if(escolha == -1){
        int card = w->pergunta_carta();
        while(card > 5 - (int)_nap->turno_atual()){
            card = w->pergunta_carta();
        }
        _nap->first_move(card);
        w->atualiza_cartas(0);
        imprime_mao_atual();
    }
    while(escolha == 0) {
        escolha = _nap->primeira_jogada(primeiro);
    }
    if(escolha != -1) { w->atualiza_cartas(1); imprime_mao_atual();}
    if(SIMULACAO && primeiro == 0) {w->atualiza_cartas(1); imprime_mao_atual();}
    w->sleep(1000);
    Carta first = _nap->carta_maior();
}

void Tela::jogada_normal(unsigned int pos) {
    w->informacao("Jogador " + _nap->nome_jogador_atual() + ", escolha a carta a ser jogada!");
    imprime_mao_atual();
    Carta escolha = _nap->jogada_normal(pos);
    if(escolha.numero() == 14) { //aqui vai a entrada do usuario
        int pos_carta = w->pergunta_carta();
        _nap->executa_jogada(pos_carta);
        w->atualiza_cartas(0);
        imprime_mao_atual();
        w->sleep(1000);
    }

    while(escolha.numero() == 0){
        escolha = _nap->jogada_normal(pos);
    }
    if(escolha.numero() != 14) {
        _nap->joga_monte(escolha,pos);
        w->atualiza_cartas(1);
        imprime_mao_atual();
    }
    if(SIMULACAO && pos == 0) {w->atualiza_cartas(1); imprime_mao_atual();}
    w->sleep(1000);
}

void Tela::imprime_pontuacao() {
    std::vector<int> pontos = _nap->vetor_pontuacao();
    w->pontos_jogador(pontos[0]);
    w->pontos_adversario(pontos[1]);
}


















