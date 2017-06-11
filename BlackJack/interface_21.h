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
    std::string novo();
    void boas_vindas();
    void placar(int total);
    int aposta();
    void naposta();
    void mostra_mao(std::vector<p3::Carta> mao);
    void mostra_maos(std::vector<p3::Carta> d, std::vector<p3::Carta> p);
    int jogue();
    void vez_dealer();
    void vencedor(bool a, int b, int c);
    bool continuar();
    void obrigado();
private:
    std::string nome;
};
#endif /* interface_21_h */
