
#ifndef GAME_H
#define GAME_H

#include <jogo.h>

#include "rules.h"
#include "cards.h"

class OneSuitGame : public p3::JogoBasico<OneSuitCard> {
    
public:
    
    OneSuitGame(std::string player);
    
    void fim_jogada();
    
    void next_turn();
    
private:
    
};

#endif
