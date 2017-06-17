//
//  main.cpp
//  21
//
//  Created by Andre Luigi on 22/05/17.
//  Copyright © 2017 Andre Luigi. All rights reserved.
//
//
//
//  git clone https://github.com/gianricardo/prog3.git
//  qmake -spec macx-xcode PROJECT=BlackJack
//
//

#include <iostream>
#include <vector>


#include "jogo_21.h"
#include "regra_21.h"
#include "interface_21.h"


using namespace p3;

int main(void) {
    
    Interface iu;
    Regra21 *rules = new Regra21();
    BlackJack game(rules, iu.novo_jogo());
    game.play(iu);
    return 0;
}

