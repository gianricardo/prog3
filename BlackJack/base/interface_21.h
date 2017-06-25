//
//  interface_21.h
//  main
//
//  Created by Andre Luigi on 11/06/17.
//
// ===> Essa classe não está sendo usada, foi usada apenas para testar o codigo <==

#ifndef interface_21_h
#define interface_21_h

#include <iostream>
#include <vector>
#include "../../carteado/src/p3/carta.h"

class Interface{
public:
     std::string novo_jogo(); //
     void boas_vindas();//
     void placar(int total);//
     int aposta();//
     void naposta(); //
    void mostra_mao(std::vector<p3::Carta> mao); //nao chamada em jogo, nao precisa na ig
     void mostra_maos(std::vector<p3::Carta> d, std::vector<p3::Carta> p);
     int jogue(); //
     void vez_dealer(); //
     void vencedor(bool a, int b, int c); //
     bool continuar(); //
    void obrigado(); //não está sendo usada!
     void placar_rodada(int saldo, int aposta); //
private:
    std::string nome;
};
#endif /* interface_21_h */
