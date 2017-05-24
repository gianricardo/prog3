//
//  main.cpp
//  21
//
//  Created by Andre Luigi on 22/05/17.
//  Copyright © 2017 Andre Luigi. All rights reserved.
//

#include <iostream>
#include "../carteado/src/p3/baralho.h"
#include "../carteado/src/p3/carta.h"
#include "../carteado/src/p3/jogador.h"
#include "../carteado/src/p3/jogo.h"
#include "../carteado/src/p3/mesa.h"
#include "../carteado/src/p3/regra.h"
int main(void) {
    // insert code here...
    
    //
    
    p3::Regra *r = new p3::Regra(3, 4, 0, 0, 16);
    
    p3::Jogo j(r, {"j1", "j2", "j3"});
    
    std::cout << "BlackJack" << std::endl;
    
    return 0;
}
