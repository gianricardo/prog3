
#ifndef GAME_H
#define GAME_H

#include <jogo.h>

#include "rules.h"
#include "cards.h"

class OneSuitGame : private p3::JogoBasico<OneSuitCard> {

public:
    
    OneSuitGame(std::string player);
    
    void next_turn();
    
    void show();
    
private:
    
    void _distribute(int start = 0, int end = 9);
    
    void _turn_all();
};

#endif
