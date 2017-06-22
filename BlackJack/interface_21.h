//
//  interface_21.h
//  main
//
//  Created by Andre Luigi on 11/06/17.
//
//

#ifndef interface_21_h
#define interface_21_h

#include <iostream>
#include <vector>
#include "../carteado/src/p3/carta.h"

class Interface{
public:
    virtual std::string novo_jogo(); //
    virtual void boas_vindas();//
    virtual void placar(int total);//
    virtual int aposta();//
    virtual void naposta(); //
    void mostra_mao(std::vector<p3::Carta> mao); //nao chamada em jogo, nao precisa na ig
    virtual void mostra_maos(std::vector<p3::Carta> d, std::vector<p3::Carta> p);
    virtual int jogue(); //
    virtual void vez_dealer(); //
    virtual void vencedor(bool a, int b, int c); //
    virtual bool continuar(); //
    void obrigado(); //não está sendo usada!
    virtual void placar_rodada(int saldo, int aposta); //
private:
    std::string nome;
};
#endif /* interface_21_h */
