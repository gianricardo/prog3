//
//  interface_21.cpp
//  main
//
//  Created by Andre Luigi on 11/06/17.
//
//

#include "interface_21.h"

using namespace std;


string Interface::novo_jogo(){
    std::string n;
    cout<<"- ♠♥♣♦21♦♣♥♠ -"<<endl;
    
    cout<<"\nDigite seu nome:";
    cin>>n;
    cin.clear();
    nome=n;
    return nome;
}

void Interface::boas_vindas(){
    cout<<"Bem vindo "<<nome<<endl;
}

void Interface::placar(int total){
    cout<<"\n"<<nome<<", você possui R$"<<total<<",00 para apostar."<<endl;
    cout<<"A aposta mínima é de R$5,00 e a menor ficha é de R$1,00."<<endl;
}

int Interface::aposta(){
    cout<<"Faça sua aposta, "<<nome<<":";
    int a;
    cin>>a;
    cin.clear();
    return a;
}

void Interface::naposta(){
    cout<<nome<<", você não tem mais dinheiro para jogar!"<<endl;
    cout<<"Vá para casa."<<endl;
}

void Interface::mostra_mao(vector<p3::Carta> mao){

    for (auto a:mao){
        if(a.numero()==0){
            cout<<"[?]";
        }else{
            if(a.naipe()==(typename p3::Carta::Naipe)0){
                cout<<"♠ "<<a.numero();
            }
            if(a.naipe()==(typename p3::Carta::Naipe)1){
                cout<<"♥ "<<a.numero();
            }
            if(a.naipe()==(typename p3::Carta::Naipe)2){
                cout<<"♣ "<<a.numero();
            }
            if(a.naipe()==(typename p3::Carta::Naipe)3){
                cout<<"♦ "<<a.numero();
            }
        }
        cout<<endl;
    }
}

void Interface::mostra_maos(vector<p3::Carta> d, vector<p3::Carta> j){
    cout<<"\nSuas cartas:"<<endl;
    mostra_mao(j);
    cout<<"\nCartas do dealer:"<<endl;
    mostra_mao(d);
    cout<<endl;
}

int Interface::jogue(){
    int j;
    cout<<nome<<", faça sua jogada:"<<endl;
    cout<<"1 = hit\n2 = dobrar aposta\n3 = finalizar jogada"<<endl;
    cin>>j;
    cin.clear();
    return j;
}

void Interface::vez_dealer(){
    cout<<"Vez do Dealer"<<endl;
}

void Interface::vencedor(bool a,int b, int c){
    if (a){
        cout<<"\nParabéns "<<nome<<", você venceu essa rodada, ganhando R$"<<b<<",00!"<<endl;
        cout<<"Agora você tem R$"<<c<<",00 disponíveis!"<<endl;
        return;
    }
    cout<<"\nDesculpe "<<nome<<", você perdeu essa rodada, perdendo R$"<<b<<",00!"<<endl;
    cout<<"Agora você tem R$"<<c<<",00 disponíveis!"<<endl;
    return;
}

bool Interface::continuar(){
    int a;
    cout<<"Deseja jogar uma nova partida?\n1 = Sim\n2 = Não"<<endl;
    cin>>a;
    cin.clear();
    switch (a) {
        case 1:
            return true;
            break;
            
        default:
            return false;
            break;
    }
}

void Interface::obrigado(){
    cout<<"Obrigado por jogar, "<<nome<<"!"<<endl;
}

void Interface::placar_rodada(int saldo, int aposta){
    cout<<"\nVocê tem R$"<<saldo<<",00;"<<endl;
    cout<<"A rodada atual vale R$"<<aposta<<",00."<<endl;
}
