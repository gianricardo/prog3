//
//  jogo_21.cpp
//  main
//
//  Created by Andre Luigi on 08/06/17.
//
//

#include "jogo_21.h"

BlackJack::BlackJack(Regra21 *Rules, std::string nome_jogador) : JogoBasico(Rules, {"Dealer", nome_jogador}){
    
}

void BlackJack::revela_mao_dealer(){
    vira_carta_jogador(1,0);
}


int BlackJack::soma_mao(std::size_t pos){
    Regra21  r;
    int soma=0;
    for(auto a:mostra_mao_jogador(pos)){
        soma = soma+r.verifica_ponto(a.numero());
    }
    return soma;
}


void BlackJack::hit(std::size_t player_pos){
    move_carta_mj(0,player_pos,false);
    int card_pos=-1;
    for(auto a:mostra_mao_jogador(player_pos)){
        card_pos++;
    }
    vira_carta_jogador(card_pos,player_pos);
}

void BlackJack::inicia_rodada_21( ){
    vira_carta_jogador(0,0); //coloca uma carta do dealer virada para cima
    vira_carta_jogador(0,1);//vira as duas cartas do jogador
    vira_carta_jogador(1,1);
}

std::size_t BlackJack::pos_j()const{
    return pos_jogador;
}
std::size_t BlackJack::pos_d()const{
    return pos_dealer;
}

void BlackJack::vez_do_dealer(){
    muda_jogador_atual((int)pos_dealer);
}

void BlackJack::vez_do_jogador(){
    muda_jogador_atual((int)pos_jogador);
}

std::string BlackJack::nome_jogador(){
    std::string n = "-";
    if(posicao_jogador_atual() ==pos_dealer){
        vez_do_jogador();
        n = nome_jogador_atual();
        vez_do_dealer();
    }else {n = nome_jogador_atual();}
    return n;
}


void BlackJack::apostar(int a){
    Banco.set_aposta(a);
    ultima_aposta=Banco.get_aposta();
    
}

bool BlackJack::dobrar_aposta(){
    if (saldo()>ultima_aposta*2){
        ultima_aposta=ultima_aposta*2;
        return Banco.set_aposta(ultima_aposta);
    }
    ultima_aposta=saldo();
    return Banco.set_aposta(saldo());
}

bool BlackJack::verifica_ganhador(){
    if(soma_mao(pos_jogador)==21){ //se o jogador ffizer 21, jogador vence
        Banco.resultado(true);
        return true;

    }
    if(soma_mao(pos_dealer)>21){ //se o dealer estoura, jogador vence
        Banco.resultado(true);
        return true;
    }
    if(soma_mao(pos_jogador)>21){ //se o jogador estoura mas o dealer nao o cassino ganha
        Banco.resultado(false);
        return false;
    }
    
    if(21-soma_mao(pos_jogador)<21-soma_mao(pos_dealer)){//se jogador se aproxima mais de 21 ele ganha
        Banco.resultado(true);
        return true;
    }
    Banco.resultado(false);
    return false; //se nenhuma das anteriores, o cassino ganha

}

bool BlackJack::pode_apostar(){
    return Banco.autoriza_jogada();
}

int BlackJack::saldo(){
    return Banco.get_dj();
}


std::vector<Carta> BlackJack:: mao_dealer(){
    return mostra_mao_jogador(pos_d());
}

std::vector<Carta> BlackJack:: mao_jogador(){
    return mostra_mao_jogador(pos_j());
}


bool BlackJack::jogada(int i){
    switch (i) {
        case 1:
            hit(pos_j());
            return true;
            break;
        case 2:
            return dobrar_aposta();
            break;
        default:
            return false;
            break;
    }
    
}

int BlackJack::aposta(){
    return ultima_aposta;
}

void BlackJack::play(MainWindow &iu){
    bool continuar=true; //em quanto quiser jogar
    bool r=true;//rodada;
    while (continuar){
        r=true;
        inicia_rodada_21();
        iu.placar(saldo());
        int ndapostas=0;
        if(!pode_apostar()){ //verifica se esta apto a apostar;
            iu.naposta();
            continuar = false;
        }else{
            unsigned int cartas =2;
            //faz aposta:
            apostar(iu.aposta());
            while(r){
                iu.placar_rodada(saldo(), aposta());
                iu.mostra_maos(mao_dealer(),mao_jogador());
                int j = iu.jogue();
                if (j!=2 || ndapostas<3) {r=jogada(j);}
                if (j==1) cartas++;
                if (j==2) ndapostas++;
                if(cartas>29) {r=false;}
            }
            iu.vez_dealer();
            revela_mao_dealer();
            iu.mostra_maos(mao_dealer(),mao_jogador());
            IA_Dealer ia_dealer(soma_mao(pos_j()));
            bool pede=ia_dealer.decidir(soma_mao(pos_d()));
            cartas=2;
            while (pede){
                hit(pos_d()); //se verdadeiro pede
                cartas++;
                pede=ia_dealer.decidir(soma_mao(pos_d())); //decide se pede hit na proxima
                if(cartas>30) {pede=false;}
                iu.mostra_maos(mao_dealer(),mao_jogador());
            }
            verifica_ganhador();
            iu.vencedor(verifica_ganhador(), aposta(), saldo());
            reiniciar();
            continuar=iu.continuar();
        }

    }
    iu.obrigado();
    return;
}
