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
  //  std::cout << "TELA: Inicio inicia jogo" << std::endl;
    _nap->jogo_conf_inicio();
    for(int rodada = 0; rodada < _nap->max_rodadas(); rodada++){
        std::cout << "@@@@@@@@@@@@@@ INICIO DA RODADA " << rodada <<  "@@@@@@@@@@@@@@@@@" << std::endl;
        w->rodada_atual(rodada+1);
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
    //std::cout << "TELA: Inicio inicia rodada" << std::endl;
    _nap->rodada_conf_inicio();
    int declarante = escolhe_declarante();
    _nap->muda_jogador_atual(declarante);
    std::cout << "O declarante sera " << _nap->nome_jogador_atual() << "!" << std::endl;
    w->declarante(_nap->nome_jogador_atual());

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
        w->informacao("**Como todos declararam 0, voce eh obrigado a declarar 1 ou mais");
    }

    std::cout << "Insira o numero de rodadas que voce acha que vai fazer: ";
    w->informacao("Jogador " + _nap->nome_jogador_atual() + ", insira o numero de rodadas que voce acha que vai fazer: ");
    int trunfo_atual = _nap->pergunta_turnos(pos, zero);

    if(trunfo_atual == -1) {
        int aposta = w->pergunta_turnos();
        _nap->set_aposta_maxima(aposta);
        _nap->define_declarante(0);
    }

    while(trunfo_atual == 0) {
        std::cout << "Entrada invalida, insira outra entrada: ";
        trunfo_atual = _nap->pergunta_turnos(pos, zero);
    }
    std::cout << std::endl;
}

void Tela::imprime_mao_atual() {
    std::vector<Carta> aux = _nap->mostra_mao_jogador_atual();
    int cont = 0;
    bool mostra = _nap->posicao_jogador_atual() == 0;

    for(auto i:aux) {
        std::string card = imprime_carta(i);
        w->imprime_carta(card, mostra || MOSTRA ,++cont, _nap->posicao_jogador_atual() );
        std::cout << "\t--> " << cont << "-) "<< imprime_carta(i) << std::endl;
    }
    std::cout << std::endl;
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
        std::cout << "Jogador "<< _nap->nome_jogador_atual() << std::endl;
//        std::string inf;
//        inf.append("Jogador ");
//        inf.append(_nap->nome_jogador_atual());
        //w->informacao("Jogador " + _nap->nome_jogador_atual());

        pergunta_turnos(i);
        if(_nap->aposta_maxima() == 5) break;
    }

    return _nap->posicao_declarante();
}

void Tela::declarante_escolhe_trunfo() {
    w->informacao("Declarante " + _nap->nome_jogador_atual() + ", escolha o naipe de trunfo:");
    std::cout << "\nDeclarante " << _nap->nome_jogador_atual() << ", escolha o naipe de trunfo:" << std::endl;
    int escolha = _nap->declarante_escolhe_trunfo();

    if (escolha == -1) {
        int naipe = w->pergunta_naipe();
        _nap->define_naipe(naipe);
        w->trunfo_rodada(naipe);
    }

    while(escolha == 0){
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

        w->carta_monte(imprime_carta(topo));
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
    int escolha = _nap->primeira_jogada(primeiro);
    if(escolha == -1){
        int card = w->pergunta_carta();
        _nap->first_move(card);

        w->atualiza_cartas(0);
        imprime_mao_atual();
    }
    while(escolha == 0) {
        std::cout << "Escolha invalida!" << std::endl;
        escolha = _nap->primeira_jogada(primeiro);
    }
    if(escolha != -1) { w->atualiza_cartas(1); imprime_mao_atual();}
    Carta first = _nap->carta_maior();
    std::cout << "->A carta escolhida foi: " << imprime_carta(first) << std::endl;
    std::cout << "O naipe inicial desse turno eh o " << imprime_naipe(first.naipe()) << std::endl;

}

void Tela::jogada_normal(unsigned int pos) {
    std::cout << "Jogador " << _nap->nome_jogador_atual() << std::endl;
    imprime_mao_atual();
    Carta escolha = _nap->jogada_normal(pos);
    if(escolha.numero() == 14) { //aqui vai a entrada do usuario
        int pos_carta = w->pergunta_carta();
        _nap->executa_jogada(pos_carta);
        w->atualiza_cartas(0);
        imprime_mao_atual();
    }

    while(escolha.numero() == 0){
        std::cout << "Escolha invalida!" << std::endl;
        escolha = _nap->jogada_normal(pos);
    }
    if(escolha.numero() != 14) {
        _nap->joga_monte(escolha,pos);
        w->atualiza_cartas(1);
        imprime_mao_atual();
    }

    std::cout << "->A carta escolhida foi: " << imprime_carta(escolha) << std::endl;

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


















